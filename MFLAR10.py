while True:
    s = input()
    if s == "*":
        break
    d = len(set(word.upper()[0] for word in map(str, s.split())))
    if d == 1:
        print('Y')
    else:
        print('N')