#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int * queue;
int size = 0;
int capacity = 0;


void resize(void) {
	int * old = queue;
	queue = (int*)malloc(capacity*2*sizeof(int));
	memcpy(queue, old, capacity*sizeof(int));
	free(old);
	capacity *= 2;
}


void insert(int val) {
	if (size == capacity) resize();

	queue[size] = val;
	size++;

	int tmp;
	int z = size-1;
	while  (z > 0) {
		if (queue[z] > queue[(z-1)/2]) return;
		tmp = queue[(z-1)/2];
		queue[(z-1)/2] = queue[z];
		queue[z] = tmp;
		z = (z-1)/2;
	}
}

void add(int val) {
	if (size == capacity) resize();

	queue[size] = val;
	size++;
}


void root_fix(int root) {
	int z = root + 1;
	int tmp;

	while (size >= z*2+1) {
		if (queue[z-1] < queue[z*2-1] && queue[z-1] < queue[z*2]) 
			break;
		z = queue[z*2-1] < queue[z*2] ? z*2 : z*2+1;
		tmp = queue[z/2-1];
		queue[z/2-1] = queue[z-1];
		queue[z-1] = tmp;
	}

	if (size >= z*2) {
		if (queue[z-1] > queue[z*2-1]) {
			tmp = queue[z-1]; 
			queue[z-1] = queue[z*2-1];
			queue[z*2-1] = tmp;
		}
	}
}

void construct(void) {
	for (int i = size - 1; i >= 0; i--) {
		root_fix(i);
	}
}

int delete_min(void) {
	int result = queue[0];
	queue[0] = queue[size-1];
	size--;

	root_fix(0);

	return result;
}



void init(void) {
	queue = (int*)malloc(32*sizeof(int));
	capacity = 32;
	size = 0;
}


int main(void) {
	init();	
	add(0);
	add(1000);
	add(10001);
	add(1001);
	add(1002);
	add(9);
	add(8);
	add(7);
	add(6);
	add(5);
	add(4);
	add(3);
	add(2);
	add(1);
	construct();

	while (size > 0) {
		printf("%d\n", delete_min());
	}

	return 0;
}

