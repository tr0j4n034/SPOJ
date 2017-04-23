while True:
    N, M = map(int, input().split())
    if N + M == 0:
        exit(0)
    dp = [-1] * (N + 1)
    dp[0] = 0
    for i in range(M):
        a, b = map(int, input().split())
        for j in range(N, a - 1, -1):
            if dp[j - a] != -1:
                dp[j] = max(dp[j], dp[j - a] + b)
    a, b = 0, 0
    for i in range(N + 1):
        if dp[i] > b:
            a, b = i, dp[i]
    input()
    print(a, b)