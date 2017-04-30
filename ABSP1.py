T = int(input())
for _ in range(T):
    N = int(input())
    a = list(map(int, input().split()))
    sum = [0] * N
    sum[0] = a[0]
    for i in range(1, N):
        sum[i] = sum[i - 1] + a[i]
    result = 0
    for i in range(N):
        result += (i + 1) * a[i] - sum[i]
    print(result)