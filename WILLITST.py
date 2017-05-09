N = int(input())
for _ in range(1234):
    if N == 1:
        break
    if N % 2 == 0:
        N = N >> 1
    else:
        N = 3 * N + 3
if N == 1:
    print("TAK")
else:
    print("NIE")