t = input()
assert 1 <= t <= 1000

for _ in xrange(t):
    word = raw_input().strip()
    maxi = 'a'
    loc = []
    for i in xrange(len(word)):
        assert 96 <= ord(word[i]) <= 122
        if word[i] > maxi:
            loc = [i]
            maxi = word[i]
        elif word[i] == maxi:
            loc.append(i)
        else:
            pass

    max_word = word
    for i in loc:
        w = word[i:] + word[:i]
        if w > max_word:
            max_word = w

    print max_word