a = []
sum = 0
for _ in range(10):
    sum += int(input())
    a.append(sum)
a.sort()
result = 0xFFFFF
for _ in range(9, -1, -1):
    if abs(a[_] - 100) < abs(result - 100):
        result = a[_]
print(result)