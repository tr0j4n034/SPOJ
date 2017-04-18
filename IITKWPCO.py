T = int(input())
for _ in range(T):
    N = int(input())
    a = sorted(list(map(int, input().split())))
    result, ptr = 0, 0
    for i in range(0, N):
        while ptr < N - 1 and a[ptr] < 2 * a[i]:
            ptr += 1
        if a[i] * 2 == a[ptr]:
            result += 1
            a[ptr] = -1
    print(result)
