N = int(input())
p = 1
fac = 1
for i in range(1, N + 1):
    fac = fac * i % 109546051211
    p = p * fac % 109546051211
    if p == 0:
        break
print(p)