primes = [0] * 123456
for i in range(2, 123456):
    if primes[i] == 1:
        continue
    for j in range(i + i, 123456, i):
        primes[j] = 1
T = int(input())
queries = [[0, 0] for i in range(T)]
for i in range(T):
    queries[i][0] = int(input())
    queries[i][1] = i
queries.sort(key = lambda a: a[0])
result = [0] * T
ptr = 0
product = 1
for i in range(2, 123456):
    if ptr == T:
        break
    while ptr < T and product * i > queries[ptr][0]:
        result[queries[ptr][1]] = product
        ptr += 1
    if primes[i] == 0:
        product *= i
for i in range(T):
    print(result[i])