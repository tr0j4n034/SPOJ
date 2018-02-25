T = int(raw_input())
for i in range(T):
    a, b, c = map(int, raw_input().split())
    print('Case {}: {}' .format(i + 1, a * b * (b + 1) // 2 * c * (c + 1) // 2))
