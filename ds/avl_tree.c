#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node node;

struct node {
	int val;
	int lht;
	int rht;
	node* p;
	node* l;
	node* r;
}

node* root = NULL;


int get_height(node* u) {
	int lht, rht;

	if (u == NULL) return 0;

	if (u->l == NULL)
		lht = 0;
	else
		lht = 1 + (u->l->lht > u->l->rht ? u->l->lht : u->l->rht);
	
	if (u->r == NULL)
		rht = 0;
	else
		rht = 1 + (u->r->lht > u->r->rht ? u->r->lht : u->r->rht);

	return 1 + (lht > rht ? lht : rht);
}


node* rebal(node* n) {
	node* tmp;
	if (n->lht > n->rht) {
		if (n->l->lht >= n->l->rht) {
		}
	}
}


void insert(int val) {
	node* u = (node*)calloc(sizeof(u));
	u->val = val;

	if (root == NULL) {
		root = u;
		return;
	}
	
	// Traverse tree to insert u
	node* v = root;
	while (1) {
		if (v->val == val) {
			free(u);
			return;
		}

		if (v->val > val) {
			if (v->l == NULL) {
				v->l = u;
				u->p = v;
				break;
			}
			v = v->l;
		} else {
			if (v->r == NULL) {
				v->r = u;
				u->p = v;
				break;
			}
			v = v->r;
		}
	}

	// Update subtree heights
	v = u->p;
	int lht, rht;
	while (v != NULL) {
		if (v->val > val)
			v->lht = get_height(u->l);
		else
			v->rht = get_height(u->r);

		if ((v->lht - v->rht)/2 != 0)
			v = rebal(v);
		else 
			v = v->p;
	}
}

void delete(int val) {

}


int predecessor(int val) {

}

int successor(int val) {
}

int main(void) {
	
	return 0;
}




