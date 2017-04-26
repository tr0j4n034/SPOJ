while True:
    try:
        a = input()
        b = input()
        for i in range(97, 123):
            print(chr(i) * (min(a.count(chr(i)), b.count(chr(i)))), end='')
        print()
    except EOFError:
        exit(0)
