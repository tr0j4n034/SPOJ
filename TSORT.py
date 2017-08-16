N = int(input())
count = [0] * 1000001
for i in range(N):
    count[int(input())] += 1
for i in range(1000001):
    for j in range(count[i]):
        print(i)
