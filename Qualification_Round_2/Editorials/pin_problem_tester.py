from fractions import gcd

t = input()
assert 1 <= t <= 100000
for _ in xrange(t):
    n, m = map(int, raw_input().strip().split(' '))
    assert 1 <= n <= 10000
    assert 1 <= m <= 10
    a = map(int, raw_input().strip().split(' '))
    for __ in a:
        assert 1 <= __ <= 10
    lcm = a[0]
    for i in range(1, m):
        lcm = (a[i] * lcm) / gcd(a[i], lcm)

    print n / lcm