pw = [1] * 105
for i in range(1, 105):
    pw[i] = pw[i - 1] * 2

def countBits(N, K):
    count = 0
    for i in range(K):
        count += N // pw[i + 1] * pw[i]
        count += max(0, N % pw[i + 1] - pw[i] + 1)
    return count

def findUpperBound(bitCount, low, high):
    middle, best = 0, 0
    while low <= high:
        middle = (low + high + 1) >> 1
        if countBits(middle, K) <= bitCount:
            best = middle
            low = middle + 1
        else:
            high = middle - 1
    return best


K, M = map(int, raw_input().split())
highestResult = countBits(1 << K, 102) / M + 50
lowestResult = max(1, highestResult - 111)
low, high, best, middle = lowestResult, highestResult, highestResult, 0

while low <= high:
    middle = (low + high + 1) >> 1
    skippedNumbers, skippedBits = 0, 0
    for i in range(M):
        if skippedNumbers >= pw[K] - 1:
            break
        skippedNumbers = findUpperBound(skippedBits + middle, skippedNumbers + 1, pw[K] - 1)
        skippedBits = countBits(skippedNumbers, K)
    if skippedNumbers >= pw[K]- 1:
        best = middle
        high = middle - 1
    else:
        low = middle + 1
print(best)
