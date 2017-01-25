// 10114 - Loansome Car Buyer


#include <cstdio>


int main(void) 
{
	int i, j, k, T;
	int d, m, next_m;
	float down, amt, val, owed, pmt, depr, next_depr;

	scanf("%d %f %f %d ", &d, &down, &amt, &i);

	while (d > 0) {
        
        // Read the initial depreciation rate
        scanf("%d %f ", &m, &depr);
        i--;
        
        // Initial calculations
        owed = amt;
        pmt = amt / d;
        val = (amt + down) * (1 - depr);
        j = 0;

        // If there is more than one depreciation rate, read the next one
        if (i > 0) {
            scanf("%d %f ", &next_m, &next_depr);
            i--;
        } else {
            next_m = 0;
        }
        
        while (val < owed) {
            
            j++;
            
            if (j == next_m) {
                depr = next_depr;
                
                if (i > 0) {
                    scanf("%d %f ", &next_m, &next_depr);
                    i--;
                }
            }
 
            owed -= pmt;
            val *= (1 - depr);
        }
            
        while(i != 0) {
            scanf("%d %f ", &m, &depr);
            i--;
        }
            
        if (j == 1) {
            printf("1 month\n");
        } else {
            printf("%d months\n", j);
        }
        
        scanf("%d %f %f %d ", &d, &down, &amt, &i);

	}
		
	return 0;
}
