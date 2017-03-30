dp = [[0] * 9 for i in range(35)]
for i in range(3):
    dp[1][i] = 1
for i in range(9):
    dp[2][i] = 1
for i in range(3, 32):
    for j in range(9):
        (a, b) = (j / 3, j % 3)
        for k in range(3):
            if a != b and a != k and b != k:
                continue
            dp[i][a * 3 + k] += dp[i - 1][j]

T = int(input())
for c in range(T):
    N = int(input())
    sum = 0
    for i in range(9):
        sum += dp[N][i]
    print(sum)