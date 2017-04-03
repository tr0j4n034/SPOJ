def f(N):
    return (N * N + N + 2) >> 1
T = int(input())
for i in range(T):
    N = int(input())
    low, high, mid, best = 0, N, 0, N
    while low <= high:
        mid = (low + high + 1) >> 1
        if f(mid) >= N:
            best = mid
            high = mid - 1
        else:
            low = mid + 1
    print(best)