s = ""
n = int(input())

k = 2

while k <= n:
    if n % k == 0:
        s += str(k)
        n /= k
        break
    k += 1

m = 2
while m <= n:
    if n % m == 0:
        s += " * "
        s += str(m)
        n /= m
        continue
    m += 1

print(s)
