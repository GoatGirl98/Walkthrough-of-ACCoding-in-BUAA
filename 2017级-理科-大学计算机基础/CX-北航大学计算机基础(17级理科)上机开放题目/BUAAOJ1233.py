def GPA(score):
    if score >= 60:
        return 4-3*(100-score)*(100-score)/1600.0
    else:
        return 0

A = []
B = []
n = int(input())
for i in range(0, n):
    A.insert(i, int(input()))
for i in range(0, n):
    B.insert(i, float(input()))
sum1 = 0
sum2 = 0
for i in range(0, n):
    sum1 += GPA(A[i])*B[i]
for i in range(0, n):
    sum2 += B[i]
GPAA = float(sum1/sum2)
print("%.3f" % GPAA)
