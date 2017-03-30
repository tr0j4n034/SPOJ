f = [0] * 505
f[0] = 2
for i in range(1, 505):
    f[i] = f[i - 1] * 2 % 1298074214633706835075030044377087
T = int(input())
for i in range(T):
    N = int(input())
    print(f[N] - 1)
