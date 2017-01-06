#include <cstdio>

int main(void) {

    int i, j, k, T;
    int dx, dy, x, y;
    char out[2];

    scanf("%d ", &T);

    while (T) {

	scanf("%d %d ", &dx, &dy);

        for (i = 0; i < T; i++) {
	    scanf("%d %d ", &x, &y);

	    if (y < dy) {
		out[0] = 'S';
	    } else if (y > dy) {
		out[0] = 'N';
	    } else {
		printf("divisa\n");
		continue;
	    }
	    
	    if (x < dx) {
		out[1] = 'O';
	    } else if (x > dx) {
		out[1] = 'E';
	    } else {
		printf("divisa\n");
		continue;
	    }

	    printf("%c%c\n", out[0], out[1]);

	}

        scanf("%d ", &T);
    }
    
    
    return 0;
}
