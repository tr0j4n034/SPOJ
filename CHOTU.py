import math

T = int(input())
for i in range(T):
    a, b = map(int, input().split(' '))
    print("%.3f" %(2 * math.sqrt(a * a - b * b)))
