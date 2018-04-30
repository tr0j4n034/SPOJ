T = int(input())
for i in range(T):
    N = int(input())
    data = sorted(list(map(int, input().split(' '))))
    result = 1
    for i in range(N):
        result *= max(data[i] - i, 0)
        result %= 1000000007
    print(result)
print("KILL BATMAN")
