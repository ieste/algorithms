//  main.c
//  Problem 11172
//  Created by Isabella Stephens on 10/06/2016.


#include <cstdio>

using namespace std;

int main(void) {
    int i, j, k, cnt, T;
    int n, t, tp, tmp;
    
    scanf("%d ", &T);
    
    for (cnt = 0; cnt < T; cnt++) {
        scanf("%d ", &t);
        scanf("%d ", &tp);
        
        if (t > tp) {
            printf(">\n");
        } else if (t < tp) {
            printf("<\n");
        } else {
            printf("=\n");
        }
    }
    
    return 0;
}