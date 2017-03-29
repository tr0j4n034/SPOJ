def get(N):
    sum = 0
    product = 1
    while product <= N:
        sum += product * (N / product - N / (product << 1))
        product <<= 1
    return sum
a, b = map(int, raw_input().split())
print(get(b) - get(a - 1))
