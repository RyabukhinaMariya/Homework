from itertools import product

n = int(input())
a = []
s = ''.join([str(i) for i in range(n)])
h = [''.join(i) for i in product(s, repeat = n)] #создаем массив всех возможных расположений ферзей на доске,\\
                            # где значение элемента - позиция ферзя, номер элемента - номер строки, где расположен ферзь
res = 0

for k in h:
    if all([k[i] != k[j] for i in range(n-1) for j in range(i+1, n)]):
        if all(int(k[i])-i != int(k[j])-j for i in range(n-1) for j in range(i+1, n)):
            if all(int(k[i])+i != int(k[j])+j for i in range(n-1) for j in range(i+1, n)):
                print(k)
print(res)


