cat = [[0 for i in range(1005)] for j in range(1005)]
for i in range(1, 1005):
    for j in range(i + 1):
        if j == 0:
            cat[i][j] = 1
        else:
            cat[i][j] = (cat[i][j - 1] + cat[i - 1][j]) % 1000000
while True:
    N = int(input())
    if N == 0:
        break
    print(cat[N][N])
