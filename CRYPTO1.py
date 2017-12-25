import time
mod = 4000000007
a = int(input())
pw = 1000000002
x = pow (a, pw, mod)
if (x > mod / 2):
    x = mod - x
print(time.asctime(time.gmtime(x)))
