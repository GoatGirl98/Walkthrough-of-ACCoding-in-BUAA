dp = [[0]*210 for i in range(210)]
map = [[0] for _ in range(210)]
res = 0
n = int(input())

for i in range(0, n):
    map[i] = input()

for i in range(0, n):
    for j in range(i, n):
        if map[i][j] == '-':
            dp[i][j] = 1


for i in range(1, n):
    for j in range(i, n):
        if dp[i][j]:
            if dp[i - 1][j - 1] and dp[i - 1][j]:
                if dp[i - 1][j - 1] < dp[i - 1][j]:
                    dp[i][j] += dp[i - 1][j - 1]
                else:
                    dp[i][j] += dp[i - 1][j]


for i in range(1, n):
    for j in range(i, n):
        if res < dp[i][j]:
            res = dp[i][j]

print(res)
