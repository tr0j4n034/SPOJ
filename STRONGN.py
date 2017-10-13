fac = [1] * 10
for i in range(1, 10):
    fac[i] = fac[i - 1] * i
T = int(input())
for _ in range(T):
    N = int(input())
    sum = 0
    for i in str(N):
        sum += fac[ord(i) - 48]
    if sum == N:
        print('YES')
    else:
        print('NO')
