def gcd(a,b):
    r = 0
    while(not((a & 1) or (b & 1))):
        a >>= 1
        b >>= 1
        r = r+1
    while(True):
        while(not(a&1)):
            a>>=1
        while(not(b&1)):
            b>>=1
        if(a > b):
            a = a - b
        else:
            b = b - a
        if(a == 0):
            return b << r
        if(b == 0):
            return a << r

m = int(input())
n = int(input())
print(gcd(m,n))
