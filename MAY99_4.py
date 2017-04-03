n, k = map(int, raw_input().split())
if n < k:
    print(-1)
    exit(0)
n, k = n - 1, k - 1
dp = [[0 for i in range(500)] for j in range(500)]
for i in range(n + 5):
    for j in range(i + 1):
        if j == 0:
            dp[i][j] = 1
        else:
            dp[i][j] = (dp[i - 1][j] + dp[i - 1][j - 1]) % 10000007
print(dp[n][k])
