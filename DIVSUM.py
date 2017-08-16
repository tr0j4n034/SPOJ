MAX = 500005
sigma = [0] * MAX
lp = [0] * MAX
p = [0] * MAX
pc = [0] * MAX

for i in range(2, MAX):
    if lp[i] == 0:
        for j in range(i, MAX, i):
            if lp[j] == 0:
                lp[j] = i
sigma[1] = 1
for i in range(2, MAX):
    j = i / lp[i]
    if j % lp[i] == 0:
        p[i] = p[j]
        pc[i] = pc[j] * lp[i]
    else:
        p[i] = j
        pc[i] = lp[i]
    sigma[i] = sigma[p[i]] * (pc[i] * lp[i] - 1) / (lp[i] - 1)
T = int(input())
for _ in range(T):
    N = int(input())
    print(sigma[N] - N)
