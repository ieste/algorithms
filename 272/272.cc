#include <cstdio>

using namespace std;

int main(void) {

	int i = 0;
	char c;

	while(scanf("%c", &c) != EOF) {
		if (c == '"') {
			if (i % 2) printf("''");
			else printf("``");
			i++;
		} else {
			printf("%c", c);
		}
	}

	return 0;
}
