T = int(input())
for _ in range(T):
    N = int(input())
    sticks = "0" + input()
    dp = [0] * (N + 1)
    for i in range(1, N + 1):
        dp[i] = dp[i - 1]
        for j in range(1, i + 1):
            if sticks[j:i + 1].count('1') * 2 > i - j + 1:
                dp[i] = max(dp[i], dp[j - 1] + i - j + 1)
    print(dp[N])
