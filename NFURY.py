dp = [1234] * 1005
dp[0] = 0
for i in range(1, 1005):
    for j in range(1, 40):
        if j * j > i:
            break
        dp[i] = min(dp[i], dp[i - j * j] + 1)
T = int(input())
for i in range(T):
    N = int(input())
    print(dp[N])

