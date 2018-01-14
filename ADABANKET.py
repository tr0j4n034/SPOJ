N, result = int(input()), 12345
for i in range(N):
    result = min(result, input().count('1'))
print(result * 2)
