T = int(input())
for _ in range(T):
    N = int(input())
    print(N * (3 * N + 1) / 2 % 1000007)
