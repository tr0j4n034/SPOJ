T = int(input())
for c in range(T):
    w, h, n = map(int, input().split(' '))
    if n == 0:
        print(w * h)
        continue
    
    rows, columns = [], []
    for i in range(n):
        x, y = map(int, input().split(' '))
        rows.append(x)
        columns.append(y)
    rows.sort()
    columns.sort()
    l = max(rows[0] - 1, w - rows[n - 1])
    r = max(columns[0] - 1, h - columns[n - 1])
    for i in range(1, n):
        l = max(l, rows[i] - rows[i - 1] - 1)
        r = max(r, columns[i] - columns[i - 1] - 1)
    print(l * r)
