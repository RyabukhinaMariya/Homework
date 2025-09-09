str1, str2 = map(str, input("Введите 2 строки через пробел ").split())
print(str1 + " > " + str2 if str1 > str2 else str2 +" > " + str1)