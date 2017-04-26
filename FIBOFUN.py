A, B, N, M = 0, 0, 0, 0

class matrix:
    a = []

    def __init__(self, default=None):
        if default is not None:
            self.a = default
        else:
            self.a = [[0, 0], [0, 0]]

    def __mul__(self, other):
        s = matrix()
        for i in range(2):
            for j in range(2):
                for k in range(2):
                    s.a[i][j] += self.a[i][k] * other.a[k][j]
        for i in range(2):
            for j in range(2):
                s.a[i][j] %= M
        return s

    def __pow__(self, power, modulo=None):
        if power == 1:
            return matrix([[1, 1], [1, 0]])
        if power % 2 == 1:
            return self * (self.__pow__(power - 1))
        half = self.__pow__(power // 2)
        return half * half


T = int(input())
for _ in range(T):
    A, B, N, M = map(int, input().split())
    mat = matrix([[1, 1], [1, 0]]) ** N
    print((mat.a[0][0] * B + mat.a[0][1] * A - B + M) % M)
