# use Wilson theorem to solve this problem
# (n - 1) ! % n = n - 1

def power(a, b, modulo):
    if b == 0:
        return 1 % modulo
    if b % 2 == 1:
        return power(a, b - 1, modulo) * a % modulo
    half = power(a, b >> 1, modulo)
    return half * half % modulo
def solve(a, b):
    product = 1
    for i in range(a + 1, b):
        product = product * i % b
    return (b - 1) * power(product, b - 2, b) % b
T = int(input())
for i in range(T):
    (N, P) = map(int, raw_input().split())
    if N >= P:
        print(0)
    else:
        print(solve(N, P))

