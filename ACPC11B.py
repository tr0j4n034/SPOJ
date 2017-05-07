T = int(input())
for _ in range(T):
    a = sorted(list(map(int, input().split()))[1::])
    b = sorted(list(map(int, input().split()))[1::])
    result = 0xFFFFFF
    p1, p2 = 0, 0
    for i in a:
        while p1 + 1 < len(b) and b[p1 + 1] <= i:
            p1 += 1
        while p2 + 1 < len(b) and b[p2] < i:
            p2 += 1
        if b[p1] <= i:
            result = min(result, i - b[p1])
        if b[p2] >= i:
            result = min(result, b[p2] - i)
    print(result)