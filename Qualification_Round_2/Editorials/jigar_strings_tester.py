t = input()

assert 1 <= t <= 1370

arr = [0 for _ in range(26)]

for _ in xrange(t):
    w = raw_input().strip()
    n = len(w)
    final_answer = n
    assert 1 <= n <= 1991

    for __ in range(26):
        arr[__] = 0

    for i in w:
        assert 97 <= ord(i) <= 122
        arr[ord(i) - 97] += 1

    # all asserts passed

    arr.sort(reverse=True)
    for i in xrange(1, 27):
        if n % i == 0:
            answer = 0
            num_group = i
            group_length = n / i
            for j in xrange(num_group):
                if(arr[j] > group_length):
                    answer += arr[j] - group_length

            for j in range(num_group, 26):
                answer += arr[j]

            final_answer = min(answer, final_answer)

    print final_answer