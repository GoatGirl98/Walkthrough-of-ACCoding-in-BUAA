ddl = [0] * 15
n = int(input())
remain = 48
week = 15 - n
for i in range(0, n):
    ddl[i] = int(input())
    remain -= ddl[i]

if week * 10 < remain:
    print("gg")
else:
    ans = int((remain + week - 1)/week)
    print(ans)
