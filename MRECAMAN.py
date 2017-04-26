a = [0] * 500001
b = [0] * 5000000
a[0] = 0
for i in range(1, 500001):
    if a[i - 1] > i and b[a[i - 1] - i] == 0:
        a[i] = a[i - 1] - i
    else:
        a[i] = a[i - 1] + i
    b[a[i]] = 1
while True:
    N = int(input())
    if N == -1:
        exit(0)
    else:
        print(a[N])

