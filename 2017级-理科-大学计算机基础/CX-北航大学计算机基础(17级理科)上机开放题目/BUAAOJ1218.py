isPrime = [True]*250010
isPrime[0] = False
for i in range(1, 250010):
    if isPrime[i]:
        k = (i << 1) + 1
        j = i + k
        while j < 250010:
            isPrime[j] = False
            j += k

number = input()
number2 = number.split()
a = int(number2[0])
b = int(number2[1])
if a < 0:
    a = 0
if b < 0:
    b = 0
res = 0
if a <= b <= 1:
    print(0)
else:
    if b == 2:
        print(2)
    else:
        if a <= 2:
            res = 2
            a = 3
        if a % 2 == 0:
            a += 1
        if b % 2 == 0:
            b -= 1
        start = (a - 1) >> 1
        end = (b - 1) >> 1
        while start <= end:
            if isPrime[start]:
                res += ((start << 1) + 1)
            start += 1
        print(res)
