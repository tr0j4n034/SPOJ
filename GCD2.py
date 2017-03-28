def gcd(a, b):
    while a > 0 and b > 0:
        if a >= b:
            a %= b
        else:
            b %= a
    return a + b

T = int(input())
for i in range(T):
    a, b = map(int, raw_input().split())
    print(gcd(a, b))