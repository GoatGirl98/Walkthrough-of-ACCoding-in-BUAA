A = []
n = float(input())
if(n >= 300 and n < 500):
    A.insert(0, float(n-50))
else:
    A.insert(0, float(n))
if (n >= 500 and n < 1000):
    A.insert(1, float(n - 100))
else:
    A.insert(1, float(n))
if(n >= 1000):
    A.insert(2, float(n-300))
else:
    A.insert(2, float(n))
if(n>=300):
    A.insert(3, float(300 + (n - 300)*0.8))
else:
    A.insert(3, n)
minIndex = 0
minPrice = 114514191981.0
for i in range(0,4):
    if(A[i]<minPrice):
        minIndex = i
        minPrice = A[i]
print("%.2f" % minPrice)
