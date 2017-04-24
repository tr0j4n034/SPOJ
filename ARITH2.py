T = int(input())
for _ in range(T):
    input()
    s = list(map(str, input().split()))
    result = int(s[0])
    for i in range(2, len(s) - 1, 2):
        if s[i - 1] == "+":
            result += int(s[i])
        elif s[i - 1] == "-":
            result -= int(s[i])
        elif s[i - 1] == "*":
            result *= int(s[i])
        else:
            result //= int(s[i])
    print(result)