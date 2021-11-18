a = int(input())
b = int(input())
c = int(input())
ans = 0
for i in range(100, 1000):
    a1 = int(i/100)
    tmp = int(i/10)
    b1 = int(tmp%10)
    c1 = int(i%10)
    for i1 in range(1,a):
        for i2 in range(1,b):
            for i3 in range(1,c):
                if(a1**i1+b1**i2+c1**i3==i):
                    ans = ans + 1

print(ans)
