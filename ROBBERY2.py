T = int(input())
for _ in range(T):
    N, K = map(int, input().split())
    steps = 0
    skipped = 1 << 55
    while skipped > 0:
        current = (steps + skipped) * K
        if current * (current + 1) // 2 <= N:
            steps += skipped
        skipped >>= 1
    coins = [0] * K
    N -= steps * K * (steps * K + 1) // 2
    last = steps * K + 1
    for i in range(K):
        if N <= last:
            coins[i] += N
            break
        coins[i] += last
        N -= last
        last += 1
    for i in range(K):
        a1 = i + 1
        an = (steps - 1) * K + i + 1
        coins[i] += (a1 + an) * steps // 2
    print(" ".join(map(str, coins)))
