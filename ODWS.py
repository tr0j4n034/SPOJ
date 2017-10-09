def getOrder(text):
    result = 0
    for c in text:
        result = (26 * result + ord(c) - 97) % 1000000007
    return result

T = int(input())
for _ in range(T):
    a = input()
    b = input()
    print('Case %d: %d' %(_ + 1, (getOrder(b) - getOrder(a) - 1 + 1000000007) % 1000000007))
