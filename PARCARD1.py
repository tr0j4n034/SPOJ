N = 10
pt = []
for i in range(1, N):
    if i % 2 == 0:
        v = i // 2
        pt.append(v * (3 * v + 1) // 2)
    else:
        v = i // 2 + 1
        pt.append(v * (3 * v - 1) // 2)
dp = [0] * N
dp[0] = 1
for i in range(1, N):
    v = 0
    for j in pt:
        if j > i:
            break
        if v < 2:
            dp[i] += dp[i - j]
        else:
            dp[i] -= dp[i - j]
        v = (v + 1) % 4
print(*dp)
