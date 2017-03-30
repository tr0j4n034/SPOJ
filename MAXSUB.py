modulo = 1000000009
def power(a, b):
    if b == 0:
        return 1
    if b % 2 == 1:
        return power(a, b - 1) * a % modulo
    half = power(a, b >> 1)
    return half * half % modulo
T = int(input())
for c in range(T):
    N = int(input())
    assert N > 0
    a = map(int, raw_input().split())
    big = -1 << 30
    sum = 0
    zeroes = 0
    count = 0
    for i in a:
        if i > big:
            big = i
            count = 1
        elif i == big:
            count += 1
        if i > 0:
            sum += i
        if i == 0:
            zeroes += 1
    if big == 0:
        print('0 %d' %(power(2, count) - 1))
    elif big < 0:
        print('%d %d' %(big, count % modulo))
    else:
        print('%d %d' %(sum, power(2, zeroes)))