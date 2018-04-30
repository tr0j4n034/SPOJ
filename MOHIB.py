T = int(input())
for i in range(T):
    x, a = map(int, input().split())
    delta = a * a - x * x - 3 * x + 3 * a
    print (delta >> 1)
