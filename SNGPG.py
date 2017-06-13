size = 100005
primes = [1] * size
dp = [0] * size
for i in range(2, size):
    if primes[i] == 0:
        continue
    for j in range(i + i, size, i):
        primes[j] = 0


def isprime(n):
    if n < size:
        return primes[n]
    for i in range(2, 12345):
        if n % i == 0:
            return 0
    return 1

for i in range(size):
    if primes[i] == 0:
        dp[i] = 0
        continue
    if isprime(i * i + 1) or isprime(i * i + 2):
        dp[i] = 1
for i in range(1, size):
    dp[i] += dp[i - 1]

T = int(input())
for _ in range(T):
    a, b = map(int, input().split())
    if a == 0:
        print(dp[b])
    else:
        print(dp[b] - dp[a - 1])
