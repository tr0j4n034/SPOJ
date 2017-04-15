def get(n):
    n = (n + 1) // 2
    return n * n
a, b = map(int, input().split())
if a % 2 == 1:
    a -= 1
print(get(b) - get(a))
