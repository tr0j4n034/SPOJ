N = int(input())
prime = [1] * (N + 1)

for i in range(2, N + 1):
    if prime[i] == 0:
        continue
    for j in range(i + i, N + 1, i):
        prime[j] = 0
printed = False
for i in range(2, N + 1):
    if prime[i] == 0:
        continue
    if printed:
        print(' * ', end='')
    printed = True
    counter, product = 0, i
    while product <= N:
        counter += N // product
        product *= i
    print('%d^%d' % (i, counter), end='')
print('')