count = 0

word = raw_input().strip()
assert 1 <= len(word) <= 100000
for w in word:
    assert w in "abcdefghijklmnopqrstuvwxyz"

cur_count = 0
for w in word:
    if w == 'a':
        cur_count += 1
    else:
        if cur_count > count:
            count = cur_count
        cur_count = 0

if cur_count > count:
    count = cur_count
cur_count = 0

print "a" * (count + 1)