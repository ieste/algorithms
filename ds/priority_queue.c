// Errors during implementation:
// 		forgot to handle case in delete min where there is no right 
// 		node but the left node is smaller than the root
#include <stdio.h>
#include <stdlib.h>

typedef struct node node;
struct node {
	int val;
	node* left;
	node* right;
	node* parent;
};

typedef struct p_queue {
	node* root;
	int size;
} p_queue;


node* find_rightmost_parent(p_queue* q) {
	int size = q->size + 1;
	node* result = q->root;
	int bits = 0;

	while (size / (1 << bits)) {
		bits++;
	}

	for (int i = bits-2; i > 0; i--) {
		result = size & (1 << i) ? result->right : result->left;
	}
	return result;
}


node* find_rightmost_node(p_queue* q) {
	int size = q->size;	
	node* result = q->root;
	int bits = 0;

	while (size / (1 << bits)) {
		bits++;
	}

	for (int i = bits - 2; i >= 0; i--) {
		result = size & (1 << i) ? result->right : result->left;
	}
	return result;
}




void insert(p_queue* q, int val) {

	int tmp;
	node* z = (node*)malloc(sizeof(node));
	node* p;
	z->val = val;
	z->left = NULL;
	z->right = NULL;
	z->parent = NULL;

	if (q->size == 0) {
		q->root = z;
	} else { 
		// Find rightmost parent
		p = find_rightmost_parent(q);
		z->parent = p;
		if (q->size & 1) {
			p->left = z;
		} else {
			p->right = z;
		}
	}
	q->size++;

	while(1) {
		if (z == q->root) return;
		if (z->val > p->val) return;
		tmp = z->val; z->val = p->val; p->val = tmp;
		z = p;
		p = z->parent;
	}
}

int delete_min(p_queue* q) {
	int tmp;
	int result = q->root->val;

	if (q->size == 1) {
		q->root = NULL;
		q->size = 0;
		return result;
	} 

	node* z = find_rightmost_node(q);
	q->root->val = z->val;
	if (z->parent->right == z) z->parent->right = NULL;
	else z->parent->left = NULL;
	free(z);
	q->size--;
	z = q->root;
	while(1) {
		if (z->left == NULL && z->right == NULL) return result;
		if (z->right == NULL && z->left->val > z->val) return result;
		if (z->left->val > z->val && z->right->val > z->val) return result;
		if (z->right == NULL) z = z->left;
		else z = (z->left->val < z->right->val ? z->left : z->right);
		tmp = z->parent->val;
		z->parent->val = z->val;
		z->val = tmp;
	}
}


int main(void) {
	
	p_queue queue = {0};

	insert(&queue, 12);
	insert(&queue, 3);
	insert(&queue, 4);
	insert(&queue, 0);
	insert(&queue, 100);
	insert(&queue, 8);
	insert(&queue, 1);


	while (queue.size > 0) {
		printf("%d\n", delete_min(&queue));
	}

	return 0;
}
