while True:
    M, N = map(int, input().split())
    if M + N == 0:
        exit(0)
    dp = [[0 for i in range(N + 1)] for j in range(M + 1)]
    dp[0][0] = 1
    for i in range(1, M + 1):
        a, b = map(int, input().split())
        for j in range(a, b + 1):
            for k in range(j, N + 1):
                dp[i][k] += dp[i - 1][k - j]
    print(dp[M][N])