N, K = map(int, raw_input().split())
s = [0] * (N + 1)
for i in range(K):
    l, r = map(int, raw_input().split())
    s[l] += 1
    if r != N:
        s[r + 1] -= 1
for i in range(1, N + 1):
    s[i] += s[i - 1]
s = s[0:1] + sorted(s[1:])
print(s[N // 2 + 1])