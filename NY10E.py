fac = [1] * 80
for i in range(1, 80):
    fac[i] = fac[i - 1] * i
T = int(input())
for i in range(T):
    c, n = map(int, input().split())
    print(c, int(fac[n + 9] / fac[n] / fac[9]))
