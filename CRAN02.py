T = int(input())
for _ in range(T):
    N = int(input())
    d = dict()
    d[0] = 1
    sum, result = 0, 0
    for i in map(int, input().split()):
        sum += i
        if d.get(sum) is not None:
            result += d[sum]
        if d.get(sum) is None:
            d[sum] = 1
        else:
            d[sum] += 1
    print(result)
