while True:
    try:
        N = int(input())
        print(N // 9 * 81 + (N % 9) ** 2)
    except EOFError:
        exit(0)