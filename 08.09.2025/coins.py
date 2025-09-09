a, b, c = 10, 8, 5
count_a, count_b, count_c = 0,0,0
fl = True
summ = int(input("Введите вашу сумму "))
for count_a in range(summ//a,-1,-1):
    for count_b in range(summ//b,-1,-1):
        for count_c in range(summ//c,-1,-1):
            if a*count_a+b*count_b+c*count_c == summ:
                print("a : "+str(count_a),"b : "+str(count_b), "c : "+str(count_c))
                fl = False
                quit()
if fl:
    print('-42')
