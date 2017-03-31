MAX = 100005
sq = [0] * MAX
sum = [[0 for i in range(10)] for j in range(MAX)]
for i in range(2, MAX):
    for j in range(i * i, MAX, i * i):
        sq[j] = 1
for i in range(1, MAX):
    for j in range(10):
        sum[i][j] = sum[i - 1][j]
    if sq[i] == 0:
        can = [0] * 10
        now = i
        while now > 0:
            can[now % 10] = 1
            now //= 10
        for j in range(10):
            sum[i][j] += can[j]
T = int(input())
for i in range(T):
    a, b, d = map(int, raw_input().split())
    print(sum[b][d] - sum[a - 1][d])
