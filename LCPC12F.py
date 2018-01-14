T = int(input())
for case in range(T):
    data = list(map(int, input().split()))
    X, N = data[0], data[1]
    result = 0
    counts = [0] * (X + 1)
    for i in data[2:]:
        if i <= X:
            result += counts[X - i]
            counts[i] += 1
    print('%d. %d' %(case + 1, result))
