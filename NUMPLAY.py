dp = [[0 for i in range(4)] for j in range(10005)]

for i in range(4):
    dp[1][i] = 1
for i in range(2, 10004):
    dp[i][0] = dp[i - 1][1]
    dp[i][1] = dp[i - 1][0] + dp[i - 1][3]
    dp[i][2] = dp[i - 1][1] + dp[i - 1][3]
    dp[i][3] = dp[i - 1][2]

T = int(input())
for _ in range(T):
    N = int(input())
    print(sum(dp[N]))
