//
//  main.c
//  
//
//  Created by Isabella Stephens on 9/06/2016.
//
//

#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
    int i, j, k, cnt, T;
    int n, t, tp, tmp;
    vector<int> h, w, A, B;
    
    scanf("%d ", &T);
    
    for (cnt = 1; cnt <= T; cnt++) {
        scanf("%d ", &n);
        
        h.clear(); w.clear();
        A.clear(); B.clear();
        
        for (j = 0; j < n; j++) {
            scanf("%d ", &t);
            h.push_back(t);
        }
        
        for (j = 0; j < n; j++) {
            scanf("%d ", &t);
            w.push_back(t);
        }
        
        A.push_back(w[0]);
        
        for (i = 1; i < n; i++) {
            A.push_back(w[i]);
            for (j = 0; j < i; j++) {
                if (h[i] > h[j]) {
                    if ((A[j] + w[i]) > A[i]) {
                        A[i] = A[j] + w[i];
                    }
                }
            }
        }
        
        B.push_back(w[0]);
        
        for (i = 1; i < n; i++) {
            B.push_back(w[i]);
            for (j = 0; j < i; j++) {
                if (h[i] < h[j]) {
                    if ((B[j] + w[i]) > B[i]) {
                        B[i] = B[j] + w[i];
                    }
                }
            }
        }
        
        t = *max_element(A.begin(), A.end());
        tp = *max_element(B.begin(), B.end());
        
        if (t >= tp) {
            printf("Case %d. Increasing (%d). Decreasing (%d).\n", cnt, t, tp);
        } else {
            printf("Case %d. Decreasing (%d). Increasing (%d).\n", cnt, tp, t);
        }
        
    }
    
    return 0;
}