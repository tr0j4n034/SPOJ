n = int(input())
dp = [0] * 1000002
ans = 1
for i in map(int, input().split(' ')):
    dp[i] = max(dp[i], dp[i - 1] + 1)
    ans = max(ans, dp[i])
print(ans)
