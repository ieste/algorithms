#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool is_anagram(string s1, string s2) {
	vector<int> s1counts(26, 0);
	vector<int>s2counts(26, 0);

	if (s1.length() != s2.length())
		return false;

	for (int i = 0; i < s1.length(); i++) {
		s1counts[s1[i] - 'a']++;
		s2counts[s2[i] - 'a']++;
	}

	for (int i = 0; i < 26; i++) {
		if (s1counts[i] != s2counts[i])
			return false;
	}

	return true;
}

int main(void) {

	int T, t, i, j, k, a, b, result;
	cin >> T;
	string s, s1, s2;
	for (t = 0; t < T; t++) {
		result = 0;
		cin >> s;

		for (i = 0; i < s.length() - 1; i++) {
			for (j = 1; j < s.length() - i; j++) {
				for (a = i+1; a < s.length() - j + 1; a++) {
					if (is_anagram(s.substr(i, j), s.substr(a, j)))
						result++;
				}
			}
		}

		cout << result << '\n';
	}

	return 0;
}
