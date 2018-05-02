T = int(input())
for i in range(T):
    N = int(input())
    now, result = 1, 1
    while now < N:
        now <<= 1
        result += 1
    print(result)
