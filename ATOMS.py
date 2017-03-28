T = int(input())
for i in range(T):
    N, K, M = map(int, raw_input().split())
    result = 0
    while N * K <= M:
        result += 1
        N *= K
    print(result)