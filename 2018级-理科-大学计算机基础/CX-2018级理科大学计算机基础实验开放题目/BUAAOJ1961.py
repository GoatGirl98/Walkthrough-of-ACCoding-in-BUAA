budget = int(input())
ans = float(0.0)
n = int(input())
for i in range(0, n):
    m = float(input())
    if m >= 50 and m < 100:
        m = m - 5
    else:
        if m >= 100 and m < 200:
            m = m - 15
        else:
            if m >= 200:
                m = m - 40
    ans = ans + m
if ans >= 500 and ans < 1000:
    ans = ans * 0.9
else:
    if ans >= 1000:
        ans = ans * 0.8
ans = int(ans)
print(ans)
if ans > budget:
    print("chitu!")
else:
    print("enough!")
