N, M = map(int, input().split())
a = [[0 for i in range(M + 2)]]
for i in range(N):
    a.append([123456] + (list(map(int, input().split()))) + [123456])
for i in range(2, N + 1):
    for j in range(1, M + 1):
        a[i][j] += min(a[i - 1][j - 1], a[i - 1][j], a[i - 1][j + 1])
print(min(a[N]))