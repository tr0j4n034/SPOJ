T = int(input())
for _ in range(T):
    N, K = map(int, input().split())
    if K == 0 or N == 1:
        print(-1)
        continue
    result = 1
    K -= 1
    for i in range(30, -1, -1):
        if K > 0 and result + (1 << i) < N:
            K -= 1
            result += (1 << i)
    print(result)
