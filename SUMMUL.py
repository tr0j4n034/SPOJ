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
            s.a[i][j] %= 1000000007
        return s

def __pow__(self, power, modulo=None):
    if power == 1:
        return matrix([[1, 1], [1, 0]])
        if power % 2 == 1:
            return self * (self.__pow__(power - 1))
    half = self.__pow__(power // 2)
        return half * half


def get(n, modulo):
    m = matrix([[1, 1], [1, 0]]) ** n
    return m.a[0][1]

modulo = 1000000007
T = int(input())
for _ in range(T):
    N = int(input())
    print((get(N * 2, modulo) - N + modulo) % modulo)
