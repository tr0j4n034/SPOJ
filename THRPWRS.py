def decompose(N):
    if N < 2:
        return []
    p = -1
    for i in range(65):
        if 2 ** i >= N:
            p = i
            break
    l = decompose(N - 2 ** (p - 1))
    l.append(3 ** (p - 1))
    return l

while True:
    N = int(input())
    if N == 0:
        exit(0)
    if N == 1:
        print("{ }")
        continue
    l = decompose(N)
    s = ""
    for i in l:
        if s != "":
            s += ", "
        s += str(i)
    print("{ " + s + " }")
