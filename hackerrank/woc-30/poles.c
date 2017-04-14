#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

long** cw;
long** lup;

long min_cost(int n, int k) {
	if (lup[n][k] > -1) return lup[n][k];
	if (n == k) lup[n][k] = 0;    
	else {
		long min = LONG_MAX;
		for (int i = k; i <= n; i++) {
			//printf("Min cost %d, %d + move %d to %d = %ld\n", i, k, n, i+1, min_cost(i,k)+cw[i][n]);
			if (min > min_cost(i-1, k-1) + cw[i][n]) 
				min = min_cost(i-1, k-1) + cw[i][n];
		} 
		lup[n][k] = min;
	}
	//printf("%d %d %ld\n", n, k, lup[n][k]);
	return lup[n][k];
}


int main(){
	int n; 
	int k; 
	//scanf("%d %d",&n,&k);
	n = 5000;
	k = 2500;

	int* weights = malloc(n*sizeof(int));
	int* heights = malloc(n*sizeof(int));

	cw = malloc(n*sizeof(long*));
	for (int i = 0; i < n; i++) {
		cw[i] = malloc(n*sizeof(long)); 
	}

	lup = malloc(n*sizeof(long*));
	for (int i = 0; i < n; i++) {
		lup[i] = malloc(n*sizeof(long));
		for (int j = 0; j < n; j++) {
			lup[i][j] = -1;
		}
	}

	for(int a0 = 0; a0 < n; a0++){
		//scanf("%d %d", heights+a0, weights+a0);
		heights[a0] = a0+1;
		weights[a0] = a0;
	}

	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			if (i == j) cw[i][j] = 0;
			else {
				cw[i][j] = cw[i][j-1] + (long)weights[j] * (heights[j] - heights[i]);
			}
		}
	}

	for (int i = 0; i < n; i++) {
		lup[i][0] = cw[0][i];
	}
	printf("Calculating result. \n");
	long result = min_cost(n-1, k-1);

	printf("%ld", result);
	return 0;
}
