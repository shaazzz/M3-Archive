#!/bin/env python

def pw(x, y):
    ans = 1
    while y > 0:
        if y%2 == 1:
            ans = ans*x
        x = x*x
        y = y // 2
    return ans

delta = 229939
x = pw(1377, delta)

print(x % 100)

ans = 0
y = x % 1_00000_00000_00000_00000;
for _ in range(20):
    ans += y % 10
    y //= 10
print(ans)

ans = 0
while x > 0:
    p10 = 1_000_000_000_000_000_000
    y = x % p10
    while y > 0:
        ans += y % 10
        y //= 10
    x //= p10
print(ans)
