import math

T = int(input())
for _ in range(T):
    N = int(input())
    root = int(math.sqrt(4 + 4 * N) / 2)- 1
    print('Case %d: %d' %(_ + 1, root))