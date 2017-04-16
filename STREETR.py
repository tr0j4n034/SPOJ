def gcd(a, b):
    if a == 0:
        return b
    return gcd(b % a, a)
N = int(input())
a = [0] * N
for i in range(N):
    a[i] = int(input())
g = 0
for i in range(1, N):
    g = gcd(g, a[i] - a[i - 1])
sum = 0
print((a[N - 1] - a[0]) // g - N + 1)