def binarySearch(N):
    low, high, best = 0, N, N
    while low <= high:
        middle = (low + high) >> 1
        if middle * middle >= N:
            best = middle
            high = middle - 1
        else:
            low = middle + 1
    return best

T = int(input())
for i in range(T):
    N = int(input())
    print(binarySearch(N))
