import math
m = math.sqrt(2)
m1 = math.sqrt(2+m)
pre = m
now = math.sqrt(2+m) * pre
n = int(input())
i = 2
while(True):
    if(2**(i+1)/now - 2**(i)/pre <= 10**(-n)):
        print(i)
        pnow = round(2**(i+1)/now,n)
        print(pnow)
        break
    else:
        i=i+1
        m1 = math.sqrt(2+m1)
        pre = now
        now = now * m1
