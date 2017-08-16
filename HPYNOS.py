def f(N):
    for i in range(50):
        s = 0
        for j in str(N):
            s += (ord(j) - 48) ** 2
        if s == 1:
            return i + 1
        N = s
    return -1

print(f(int(input())))
