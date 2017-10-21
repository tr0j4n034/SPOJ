while True:
    N, M = map(int, input().split())
    if N + M == 0:
        break
    print(N ** M)
