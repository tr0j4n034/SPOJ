import math

T = int(raw_input())
for i in range(T):
    N = int(raw_input())
    root = int(math.sqrt(N))
    if root * root == N:
        print('Case {}: Yes'.format(i + 1))
    else:
        print('Case {}: No'.format(i + 1))
