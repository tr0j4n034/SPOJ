primes = [0] * 1234
for i in range(2, 1234):
    if primes[i] == 1:
        continue
    for j in range(i + i, 1234, i):
        primes[j] = 1
for i in range(20):
    N = int(input())
    result = 1
    for j in range(2, 1234):
        if primes[j] == 1:
            continue
        if result * j > N:
            break
        result *= j
    print(result)