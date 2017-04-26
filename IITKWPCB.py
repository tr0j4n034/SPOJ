def gcd(a, b):
    while a > 0 and b > 0:
        if a >= b:
            a %= b
        else:
            b %= a
    return a + b
T = int(input())
for _ in range(T):
    N = int(input())
    for i in range(N // 2, 0, -1):
        if gcd(N, i) == 1:
            print(i)
            break