n = int(input())

while 1 != n:
    if n & 1:
        n = 3 * n + 1
    else:
        n >>= 1
    print(n)
