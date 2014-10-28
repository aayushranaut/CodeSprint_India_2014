t = input()
assert 1 <= t <= 17
for _ in xrange(t):
    n = input()
    mices = map(int, raw_input().strip().split(' '))
    holes = map(int, raw_input().strip().split(' '))
    mices.sort()
    holes.sort()
    print max([abs(a - b) for a, b in zip(mices, holes)])