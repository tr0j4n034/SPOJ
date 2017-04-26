T = int(input())
for _ in range(T):
    s = list(map(str, input().split()))
    res, l = 1, 1
    for i in range(1, len(s)):
        if len(s[i]) == len(s[i - 1]):
            l += 1
        else:
            l = 1
        res = max(res, l)
    print(res)