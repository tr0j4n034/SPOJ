l, r = map(int, input().split())
result = 0
while result < (l ^ r):
    result = 2 * result + 1
print(result)
