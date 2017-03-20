d = [0] * 1005
d[0] = 1
d[1] = 0
for i in range(2, 1005):
    d[i] = (i - 1) * (d[i - 1] + d[i - 2])

comb = [[0 for i in range(1005)] for j in range(1005)]
for i in range(0, 1005):
    for j in range(0, i + 1):
        if j == 0:
            comb[i][j] = 1
        else:
            comb[i][j] = comb[i - 1][j - 1] + comb[i - 1][j]

fac = [0] * 1005
fac[0] = 1
for i in range(1, 1005):
    fac[i] = fac[i - 1] * i

T = int(input())

for cases in range(0, T):
    N = int(input())
    if N == 0:
        print('0.000000')
    else:
        print('1.000000')
    continue
    sum = 0
    for j in range(1, N + 1):
        sum = sum + j * comb[N][j] * d[N - j]
    print('%.6f' % (1.0 * sum / fac[N]))
