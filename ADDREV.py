T = int(input())
for _ in range(T):
    a, b = map(int, input().split())
    print(int(str(int(str(a)[::-1]) + int(str(b)[::-1]))[::-1]))