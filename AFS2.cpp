def f(n):
    return n * (n + 1) // 2
t = int(input())
for j in range(0, t):
    sum = 0
    up = 0
    n = int(input())
    for i in range(1, 123456789):
        now = n // i
        before = n // (i + 1)
        sum += i * (f(now) - f(before))
        up = before
        if (i + 1) * (i + 1) >= n:
            break
    for i in range(1, up + 1):
        sum += n // i * i
    print(sum - f(n))