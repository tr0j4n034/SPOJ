f = [0] * 105
f[1] = 1
f[2] = 3
for i in range(3, 50):
    f[i] = f[i - 1] - f[i - 2]
for i in range(1, 50):
    f[i] += f[i - 1]
T = int(input())
for c in range(T):
    N = int(input())
    N %= 6
    if N == 0:
        N = 6
    print(f[N])