def gcd(A, B):
    if A == 0:
        return B
    return gcd(B % A, A)
result = 0
for i in range(3):
    result = gcd(result, int(input()))
print(result)
