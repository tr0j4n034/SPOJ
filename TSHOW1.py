T = int(input())
for _ in range(T):
    N = int(input())
    level = 1
    while N > (1 << level):
        N -= (1 << level)
        level += 1
    result = ""
    N -= 1
    for i in range(level):
        if N % 2 == 0:
            result += '5'
        else:
            result += '6'
        N //= 2
    print(result[::-1])
