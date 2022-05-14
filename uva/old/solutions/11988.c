#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct node {
	struct node* next;
	char val;
} node;

typedef struct list {
	node* head;
	node* tail;
} list;

void append(list* l, char val) {
	node* new = calloc(1, sizeof(node));
	new->val = val;

	if (l->tail) {
		l->tail->next = new;
	} else {
		l->head = new;
	}
	l->tail = new;
}

void join(list* first, list* second) {
	if (first->head) {
		first->tail->next = second->head;
		second->head = first->head;
	}
}

void output_list(list* list) {
	node* current = list->head;
	node* next;
	do {
		putc(current->val, stdout);
		next = current->next;
		free(current);
		current = next;
	} while (current);
}

int main() {
	char c;
	list *main, *new;
	main = new = NULL;

	while ((c = getchar()) != EOF) {
		if (c == '[') {
			if (new && main) {
				join(new, main);
			} 
			if (main) {
				new = calloc(1, sizeof(list));
			}
		} else if (c == ']') {
			if (new && main) {
				join(new, main);
				free(new);
				new = NULL;
			}
		} else if (c != '\n') {
			if (new) {
				append(new, c);
			} else {
				if (!main) main = calloc(1, sizeof(list));
				append(main, c);
			}
		} else {
			if (new && main) join(new, main);
			if (main) output_list(main);
			putc('\n', stdout);
			free(new); free(main);
			new = main = NULL;
		}
	}

	return 0;
}


