// 306. Additive Number
//
// Errors:
//      - Incorrectly handled zeros, treating 0 as an invalid input
//        when it should be valid (but 00 is invalid)
//      - Cannot handle numbers above maximum int, falsely assumed 
//        from the problem definition that numbers would not reach 
//        this size


int countDigits(long num) {
	if (num < 0) return -1;

	int digits = 1;
	long divisor = 10;
	while (num/divisor && digits < 12) {
		divisor *= 10;
		digits++;
	}
	return digits;
}


long readInt(char* num, int l, int r) {
	char tmp = num[r+1];
	num[r+1] = '\0';
	long result = strtol(num+l, NULL, 10);
	num[r+1] = tmp;
	return result;
}


bool isAdditiveNumber(char* num) {

	char tmp;
	long one, two, sum;
	int l, r, digits;

	int len = strlen(num);
	if (len < 3) return false;

	for (int i = 0; 2*(i+1) < len; i++) {
		for (int j = i + 1; j - i <= len - j - 1  && i + 1 <= len - j - 1; j++) {
			one = readInt(num, 0, i);
			two = readInt(num, i+1, j);
			r = j;
			do {
				sum = one + two;
				one = two; two = sum;
				digits = countDigits(sum);
				l = r + 1; r = l + digits - 1;
			}
			while (l < len && sum == readInt(num, l, r));

			if (l == len) return true;
			if (num[i+1] == '0') j = len;
		}
		if (num[0] == '0') i = len / 2;
	}
	return false;
}
