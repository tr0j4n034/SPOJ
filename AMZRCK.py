fib = [1] * 90
fib[1] = 2
for i in range(2, 90):
    fib[i] = fib[i - 2] + fib[i - 1]
T = int(input())
for i in range(T):
    N = int(input())
    print(fib[N])
