def f(n, k):
    return fac[n] // fac[k] // fac[n - k]
fac = [1] * 123
for i in range(1, 123):
    fac[i] = fac[i - 1] * i
T = int(input())
for _ in range(T):
    N = int(input())
    if N == 2:
        print(1)
        continue
    for i in range(65):
        if N & (1 << i):
            N = i
            break
    result = 0
    for j in range(1, N // 2 + 1):
        result += f(j + j - 1, j)
    print(result)