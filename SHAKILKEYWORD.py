import re

T = int(input())
for i in range(T):
    line = input()
    for ch in "|$ *@.&\"!^,?":
        line = " ".join(line.split(ch))
    a = "\n".join([j for j in line.split() if j.count('#') > 0])
    print('No keywords.' if not a else a)
