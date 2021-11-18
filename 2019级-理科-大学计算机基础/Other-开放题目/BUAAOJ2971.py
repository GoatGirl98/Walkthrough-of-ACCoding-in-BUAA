import math
m = int(input())
if(m==1):
    print(0)
else:
    ans = int((math.log(m-1)/math.log(2)) + 1)
    print(ans)
