while True:
    x = float(input())
    if x == 0.0:
        exit(0)
    sum, N = 0.0, 1
    while sum < x:
        N += 1
        sum += 1. / N
    print(N - 1, "card(s)")
