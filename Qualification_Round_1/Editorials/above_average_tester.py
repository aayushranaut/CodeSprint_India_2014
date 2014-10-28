t = input()
assert 1 <= t <= 10000
for _ in range(t):
    a = map(int, raw_input().strip().split(' '))
    n = a.pop(0)
    assert 1 <= n <= 100
    assert len(a) == n
    x = sum(a) / n

    answer = 0
    for i in a:
        assert 0 <= i <= 100
        if i > x:
            answer += 1
    print answer