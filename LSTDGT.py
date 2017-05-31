period = [0] * 10
for i in range(1, 10):
    now = i
    for j in range(10):
        now = now * i % 10
        if now == i:
            period[i] = j + 1
            break
T = int(input())
for _ in range(T):
    a, b = raw_input().split()
    a = int(a[-1])
    b = int(b) % period[a]
    if b == 0:
        b = period[a]
    result = a
    for i in range(b - 1):
        result = result * a % 10
    print(result)
