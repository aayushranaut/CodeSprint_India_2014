t = input()
for i in range(t):
	b = raw_input().strip()
	w = raw_input().strip()
	count = 0
	for ch in b:
		if ch in w:
			count+=1
			continue
	print count