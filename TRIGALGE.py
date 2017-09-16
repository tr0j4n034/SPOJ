import math

T = int(input())
for _ in range(T):
    A, B, C = map(float, input().split())
    low, high = 0.0, C
    for i in range(50):
        middle = (low + high) / 2.0
        f = A * middle + B * math.sin(middle)
        if f >= C:
            high = middle
        else:
            low = middle
    print('%.6f' %low)

