dp = [[0 for i in range(2000)] for j in range(20)] # with leading  zeros
dp2 = [[0 for i in range(2000)] for j in range(20)] # without leading zeros

dp[0][0] = 1
for i in range(1, 20):
    for j in range(2000):
        for k in range(10):
            if j - k * k >= 0:
                dp[i][j] += dp[i - 1][j - k * k]
for i in range(1, 10):
    dp2[1][i * i] = 1
for i in range(2, 20):
    for j in range(1, 2000):
        for k in range(10):
            if j - k * k >= 0:
                dp2[i][j] += dp2[i - 1][j - k * k]


def getsum(number):
    s = 0
    while number > 0:
        s += (number % 10) ** 2
        number //= 10
    return s

lucky = []
for i in range(1, 2000):
    now = i
    for j in range(200):
        if now == 1:
            break
        now = getsum(now)
    if now == 1:
        lucky.append(i)


def calculate(number, sum):
    number = str(number)
    l = len(number)
    result = 0
    for i in range(l):
        result += dp2[i][sum]
    skipped = 0
    for i in range(l):
        digit = int(number[i])
        for j in range(digit):
            if i == 0 and j == 0:
                continue
            if skipped + j * j <= sum:
                result += dp[l - 1 - i][sum - skipped - j * j]
        skipped += digit * digit
    return result

def bruteCount(number):
    result = 0
    for i in range(1, number + 1):
        if getsum(i) not in lucky:
            result += 1
    return result
def countWays(number):
    if number < 1:
        return 0
    result = 0
    for i in lucky:
        result += calculate(number, i)
    if getsum(number) in lucky:
        result += 1
    return number - result


while True:
    a, b = map(int, raw_input().split())
    if a + b == 0:
        exit(0)
    print(countWays(b) - countWays(a - 1))
