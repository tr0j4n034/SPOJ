while True:
    N = int(input())
    if N == 0:
        exit(0)
    a = []
    for _ in range(N):
        a.append(int(input()))
    a.sort()
    if a[0] > 200 or (1422 - a[-1]) * 2 > 200:
        print('IMPOSSIBLE')
        continue
    #print(a)
    good = True
    for _ in range(1, N):
        if a[_] - a[_ - 1] > 200:
            good = False
            break
    if good:
        print('POSSIBLE')
    else:
        print('IMPOSSIBLE')
