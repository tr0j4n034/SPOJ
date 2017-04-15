import math

T = int(input())
for _ in range(T):
    N = int(input())
    if N < 2:
        print(1)
    else:
        print(math.floor((math.log(2 * math.pi * N) / 2 + \
                     N * (math.log(N) - 1)) / math.log(10) \
                     ) + 1)