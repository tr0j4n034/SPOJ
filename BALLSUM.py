def gcd(a, b):
    while b > 0:
        a, b = b, a % b
    return a


while True:
    a, b = map(int, input().split(' '))
    if a == -1 and b == -1:
        break
    p = (b * (b - 1) // 2 - b // 2) // 2
    q = a * (a - 1) // 2
    g = gcd(p, q)
    if p == 0:
        print (0)
    else:
        print ("%d/%d" %(p // g, q // g))
