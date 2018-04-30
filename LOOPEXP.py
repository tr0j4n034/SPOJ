f = [0] * 100001
for i in range (1, 100001):
    f[i] = f[i - 1] + 1 / i

T = int(input())
for i in range(T):
    N = int(input())
    print("%.14f" % f[N])
