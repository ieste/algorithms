#include <iostream>
#include <string>

using namespace std;

int main(void) {

	string s;

	cin >> s;

	for (int i = 1; i < s.length(); i++) {
		if (s[i-1] == s[i]) {
			s = s.substr(0, i-1) + s.substr(i+1, s.length()-i-1);
			i -= 2;
		}
	}

	if (s.length() > 0)
		cout << s << '\n';
	else
		cout << "Empty String\n";

	return 0;
}
