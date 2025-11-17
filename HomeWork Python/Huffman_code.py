def encode(text):
    freq_dict = frequance(text) #подсчитываем частоту вхождения символов
    tree = make_huff_tree(freq_dict)
    codes = make_codes(tree, pref = '', codes = None) #создаем таблицу кодов, основываясь на дереве хаффмана
    encode_str = make_encoded_str(text, codes)
    return encode_str, codes

def frequance(text):
    freq_dict = {}

    for el in text:
        freq_dict[el] = 1 if el not in freq_dict else freq_dict[el] + 1
    return freq_dict

def make_huff_tree(freq_dict):
    huff_tree = [(freq, char) for char, freq in freq_dict.items()]
    huff_tree.sort()

    while len(huff_tree) > 1:
        freq1, right = huff_tree.pop(0) #берем эл-ты с наименьшей степенью вхождения
        freq2, left = huff_tree.pop(0)
        new_el = (freq1 + freq2, [right, left])
        huff_tree.append(new_el)
        huff_tree.sort(key = lambda x: x[0]) #сортировка только по первому эл-ту
    return huff_tree[0][1] if huff_tree else None

def make_codes(tree, pref = '', codes = None):
    if codes is None:
        codes = {}

    if isinstance(tree, str): #если код создан добавляем к остальным кодам
        codes[tree] = pref
    else:
        make_codes(tree[0], pref + '0', codes)
        make_codes(tree[1], pref + '1', codes)
    return codes

def make_encoded_str(text, codes):
    encoded_str = ''
    for el in text:
        encoded_str += codes[el]
    return encoded_str

def decode_str(text, codes):
    decode_dict = {code: el for el, code in codes.items()}
    decoded_str = ''
    el_st = 0
    el_end = 1
    while el_end <= len(text):
        curr_code = text[el_st:el_end]
        if curr_code in decode_dict:
            decoded_str += decode_dict[curr_code]
            el_st, el_end = el_end, el_end + 1
        else:
            el_end += 1
    return decoded_str


def encode_file(input_file, output_file):
    with open(input_file, 'r', encoding='utf-8') as f:
        text = f.read()

    encoded_text, table = encode(text)

    with open(output_file, 'w', encoding = 'utf-8') as f:
        table_str = ','.join(f'{ord(char)}:{code}' for char, code in table.items()) #записываем символы кодами из ASKII
        f.write(table_str + '\n')
        f.write(encoded_text)
    return output_file

def decode_file(input_file, output_file):
    with open(input_file, 'r', encoding = 'utf-8') as f:
        table_line = f.readline().strip()
        encoded_bits = f.readline().strip()

    table = {}
    for item in table_line.split(','):
        char_code, code = item.split(':')
        table[chr(int(char_code))] = code

    decoded_text = decode_str(encoded_bits, table)

    with open(output_file, 'w', encoding='utf-8') as f:
        f.write(decoded_text)
    return output_file
