dp = [[0 for i in range(7)] for j in range(505)]
dp[0][0] = 1
for i in range(0, 500):
    for j in range(0, 7):
        for k in range(0, 10):
            if k != 7:
                dp[i + 1][(10 * j + k) % 7] += dp[i][j]
t = int(input())
for i in range(0, t):
    n = int(input())
    sum = 0
    for j in range(1, 7):
        sum += dp[n][j]
    print(10 ** n - sum - 1)