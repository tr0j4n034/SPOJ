T = int(input())
for _ in range(T):
    N, K = map(int, input().split())
    a = sorted(list(map(int, input().split())))
    result = a[K - 1] - a[0]
    for i in range(K, N):
        result = min(result, a[i] - a[i - K + 1])
    print(result)