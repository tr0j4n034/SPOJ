def power(a, b):
    if b == 0:
        return 1
    if b % 2 == 1:
        return power(a, b - 1) * a % 10
    half = power(a, b >> 1)
    return half * half % 10

T = int(input())
for i in range(T):
    a, b = map(int, raw_input().split())
    print(power(a % 10, b))