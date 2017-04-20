dp = [0] * 3000
lp = [0] * 3000
for i in range(2, 3000):
    if lp[i] != 0:
        continue
    for j in range(i, 3000, i):
        lp[j] = i
for i in range(2, 3000):
    to = i // lp[i]
    if to % lp[i] == 0:
        dp[i] = dp[to]
    else:
        dp[i] = dp[to] + 1
s = list()
for i in range(2, 3000):
    if dp[i] > 2:
        s.append(i)
T = int(input())
for _ in range(T):
    N = int(input())
    print(s[N - 1])
