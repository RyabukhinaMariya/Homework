def rev_compare(str1, str2):
    if str1 > str2:
        return f'{str1} < {str2}'
    elif str1 == str2:
        return f'{str1} = {str2}'
    return f'{str2} < {str1}'
