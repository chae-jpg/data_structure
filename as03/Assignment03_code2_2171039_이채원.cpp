#include <stdlib.h>
#include <stdio.h>


typedef int element;
typedef struct ListNode {
	element data;
	struct ListNode* link;
} ListNode;
typedef struct {
	ListNode* head;
	int length;
} ListType;

void init(ListType* list) {
	list->head = (ListNode*)malloc(sizeof(ListNode));
	list->head = NULL;
	list->length = 0;
}


void insert_node(ListNode** phead, ListNode* p, ListNode* new_node) {
	if (*phead == NULL) {
		new_node->link = NULL;
		*phead = new_node;
	}
	else {
		new_node->link = p->link;
		p->link = new_node;
	}
}

ListNode* get_node_at(ListType* list, int pos) {
	int i;
	ListNode* tmp_node = list->head;
	if (pos < 0) return NULL;
	for (int i = 0; i < pos; i++) {
		tmp_node = tmp_node->link;
	}
	return tmp_node;
}

void add(ListType* list, int position, element data) {
	ListNode* p;

	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	node->data = data;
	p = get_node_at(list, position - 1);
	insert_node(&(list->head), p, node);
	list->length++;
}

ListType merge(ListType* a, ListType* b) {
	ListType c;
	init(&c);

	int idx = 0, i = 0, j = 0, a_len = a->length, b_len = b->length;
	ListNode* n = a->head;
	ListNode* m = b->head;

	while (i < a_len && j < b_len) {
		if (n->data < m->data) {
			add(&c, idx++, n->data);
			n = n->link;
			i++;
		}
		else {
			add(&c, idx++, m->data);
			m = m->link;
			j++;
		}
	}

	while (i < a_len) {
		add(&c, idx++, n->data);
		n = n->link;
		i++;
	}
	while (j < b_len) {
		add(&c, idx++, m->data);
		m = m->link;
		j++;
	}
	return c;
}

void display(ListType* list) {
	int i;
	ListNode* node = list->head;
	printf("( ");
	for (i = 0; i < list->length; i++) {
		printf("%d ", node->data);
		node = node->link;
	}
	printf(")\n");
}

int main() {
	ListType a, b;
	init(&a); init(&b);

	add(&a, 0, 1);
	add(&a, 1, 2);
	add(&a, 2, 5);
	add(&a, 3, 10);
	add(&a, 4, 15);
	add(&a, 5, 20);
	add(&a, 6, 25);
	display(&a);

	add(&b, 0, 3);
	add(&b, 1, 7);
	add(&b, 2, 8);
	add(&b, 3, 15);
	add(&b, 4, 18);
	add(&b, 5, 30);
	display(&b);

	ListType(c) = merge(&a, &b);

	display(&c);
}