import math
a = int(input())
b = int(input())
k = float(input())
n = int((b-a)/k)
ans = 0
for i in range(0,n):
    ans = ans + k * math.e**(-(a + k * i)*(a + k * i))
print("%.5f" % ans)

