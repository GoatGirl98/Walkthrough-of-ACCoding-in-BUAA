dp = [[0]*510 for i in range(510)]

for num in range(1, 510):
    dp[num][1] = 1

for i in range(2, 510):
    for j in range(2, i):
        if j >= i-j:
            dp[i][j] = dp[i][j - 1] + dp[i - j][i - j]
        else:
            dp[i][j] = dp[i][j - 1] + dp[i - j][j]
    else:
        dp[i][i] = 1+dp[i][i - 1]

n = int(input())
print(dp[n][n])
