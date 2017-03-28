def get(a, b):
    return a // 2 * b
T = int(input())
for i in range(T):
    a, b = map(int, raw_input().split())
    result = 0
    result = max(result, get(a + 1, b))
    result = max(result, get(b + 1, a))
    print(result)