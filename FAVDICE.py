def f(N):
    e = 0
    for i in range(1, N + 1):
        e += 1 / i
    return e * N
T = int(input())
for _ in range(T):
    N = int(input())
    print('%.2f' % f(N))