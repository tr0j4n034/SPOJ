while True:
    a, b = map(int, input().split(' '))
    if a + b == 0:
        break
    if a > b:
        print ("0.000000")
    else:
        print("%.6f" %((b - a + 1) / (b + 1)))
