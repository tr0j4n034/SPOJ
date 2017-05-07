def power(a, b):
    result = 1
    a %= modulo
    while b > 0:
        if b % 2 == 1:
            result = result * a % modulo
        b >>= 1
        a = (a * a) % modulo
    return result
 
modulo = 10000007
while True:
    N, K = map(int, raw_input().split())
    if N + K == 0:
        exit(0)
    print (2 * power(N - 1, K) + power(N, K) + 2 * power(N - 1, N - 1) + power(N, N)) % modulo