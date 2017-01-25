
#include <cstdio>
#include <cstring>
#Include <set>


void get_type(char c1, char c2, char c3, char c4, char * cptr)
{
    int idx = 0;
    
    if (c1 == c2) {
        cptr[idx] = c1;
    } else if (c1 == 'O') {
        cptr[idx] = c2;
    } else if (c2 == 'O') {
        cptr[idx] = c1;
    } else {
        cptr[0] = 'A';
        cptr[1] = 'B'; idx++;
    }
    idx++;
    
    
    if (c3 == c4) {
        cptr[idx] = c3;
    } else {
        cptr[idx] = '+';
    }
    idx++;
    
    cptr[idx] = '\0';
    
}

int main(void)
{

	char p1[5], p2[5], c[5];
	int i, j, k;
	int t, tp, tmp;

	scanf("%s %s %s ", p1, p2, c);

	i = 0;

	while(p1[0] != 'E' && p2[0] != 'N' && c[0] != 'D') {

		i++;

		if(c[0] =='?') {
			// Child is unknown


		}

		else {

		}


		
		scanf("%s %s %s ", p1, p2, c);
	}


	return 0;
}



