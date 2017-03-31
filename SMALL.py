def gcd(a, b):
    while a > 0 and b > 0:
        if a >= b:
            a %= b
        else:
            b %= a
    return a + b
def lcm(a, b):
    return a * b / gcd(a, b)
dp = [0] * 10005
dp[0] = 1
for i in range(1, 10005):
    dp[i] = lcm(dp[i - 1], i)
T = int(input())
for c in range(T):
    N = int(input())
    print(dp[N] % 1000000007)