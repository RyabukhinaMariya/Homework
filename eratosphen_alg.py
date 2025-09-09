A = int(input("Сколько чисел проверить на простоту? : "))
primes = [i for i in range(A+1)]
n = 2
while n<A:
    if primes[n]:
        for i in range(2*n, A+1, n):
            primes[i] = 0
    n+=1
primes = [num for num in primes if num!=0 and num!=1]
print(primes)