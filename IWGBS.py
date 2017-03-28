N = int(input())
f = [0] * (N + 3)
f[1] = 2
f[2] = 3
for i in range(3, N + 1):
    f[i] = f[i - 2] + f[i - 1]
print(f[N])