def power(a, b):
    if b == 0:
        return 1
    if b % 2 == 1:
        return power(a, b - 1) * a % modulo
    half = power(a, b >> 1)
    return half * half

modulo = 1000000007

while True:
    N, M = map(int, input().split())
    if N + M == 0:
        break
    numerator = power(N, M + 1) - 1 + modulo
    denumerator = power(N - 1, modulo - 2)
    print(numerator * denumerator % modulo - 1)
