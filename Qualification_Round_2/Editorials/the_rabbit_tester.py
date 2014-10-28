import math
t = input()
assert 1 <= t <= 100

for _ in range(t):
    n = input()
    assert 1 <= n <= 1e8
    x = (-1 + ((1 + 8 * n) ** 0.5)) / 2
    print int(math.floor(x))