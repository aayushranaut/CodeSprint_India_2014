t = input()
assert 1 <= t <= 100000
for _ in range(t):
    x = raw_input().strip()
    assert 1 <= len(x) <= 26
    s = set(raw_input().strip())
    assert 1 <= len(s) <= 100
    for i in s:
        assert i in 'abcdefghijklmnopqrstuvwxyz'
    count = 0
    for i in x:
        assert i in 'abcdefghijklmnopqrstuvwxyz'
        if i in s:
            count += 1
    print count