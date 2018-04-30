T = int(input())
for i in range(T):
    N = int(input())
    print (N * (N - 1) * (N - 2) * (N - 3) // 24 % 1000000007)
