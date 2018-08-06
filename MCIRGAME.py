import math

while 1:
    n = (int)(input())
    if n == -1:
        break
    print(math.factorial(2 * n) // math.factorial(n + 1) // math.factorial(n))
