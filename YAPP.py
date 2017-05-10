def power(a, b):
    if b == 0:
        return 1 % mod
    if b % 2 == 1:
        return power(a, b - 1) * a % mod
    half = power(a, b >> 1)
    return half * half % mod
mod = 1000000007
T = int(input())
for _ in range(T):
    print(power(2, int(input()) - 1))