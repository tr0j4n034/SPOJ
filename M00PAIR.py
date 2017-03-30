dp = [0] * 1005
dp[1] = 0
dp[2] = 1
for i in range(3, 1005):
    dp[i] = dp[i - 1] + 2 * dp[i - 2]
while True:
    try:
        N = int(input())
        print(dp[N])
    except EOFError:
        exit()