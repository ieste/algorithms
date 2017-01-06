import math

for i in range(1000):
	s = math.floor(i/1.1)

	for j in range(1000):
		if math.ceil(j*1.1) > i:
			break  

	if j - 1 != s:
		print s, i, j
