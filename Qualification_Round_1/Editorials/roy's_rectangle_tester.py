t = input()
assert 1 <= t <= 1e5

for _ in range(t):
    x, y, x1, y1, x2, y2 = map(int, raw_input().strip().split(' '))
    assert x1 <= x2
    assert y1 <= y2
    assert -1e9 <= x1 <= x <= x2 <= 1e9
    assert -1e9 <= y1 <= y <= y2 <= 1e9
    a = abs(x - x1)
    b = abs(x - x2)
    c = abs(y - y1)
    d = abs(y - y2)

    print min([a, b, c, d])