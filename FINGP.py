pattern = raw_input()
T = int(input())
result = []
for _ in range(T):
    text = raw_input()
    if text.endswith(pattern):
        result.append(text)
if len(result) == 0:
    print('Wrong fingerprints!')
else:
    print(len(result))
    for text in sorted(result):
        print(text)
