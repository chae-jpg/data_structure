#include <stdio.h>
#include <stdlib.h>

typedef int element;

typedef struct ListNode{
	element data;
	ListNode* link;
} ListNode;

typedef struct {
	ListNode* head;
	ListNode* tail;
	int length;
} ListType;

#define TRUE 1;
#define FALSE 0;


void init(ListType* list) {
	list->head = (ListNode*)malloc(sizeof(ListNode));
	list->head = NULL;
	list->tail = (ListNode*)malloc(sizeof(ListNode));
	list->tail = NULL;
	list->length = 0;
}

int is_empty(ListType* list)
{
	if (list->head == NULL) return 1;
	else return 0;
}

ListNode* get_node_at(ListType* list, int pos)
{
	int i;
	ListNode* tmp_node = list->head;
	if (pos < 0) return NULL;
	for (i = 0; i < pos; i++)
		tmp_node = tmp_node->link;
	return tmp_node;
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

void remove_node(ListNode** phead, ListNode* p, ListNode* removed) {
	if (*phead == NULL) {
		printf("The list is blank.\n");
	}
	else {
		if (p == NULL) {
			printf("The preceding node cannot be NULL.\n");
		}
		else {
			p->link = removed->link;
			free(removed);
		}
	}
}

void add_first(ListType* list, element data) {
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	node->data = data;
	if (list->head == NULL) {
		node->link = NULL;
		list->head = node;
		list->tail = node;
	}
	else {
		node->link = list->head;
		list->head = node;
	}
	list->length++;
}

void add_last(ListType* list, element data) {
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	node->data = data;
	if (list->head == NULL) {
		node->link = NULL;
		list->head = node;
		list->tail = node;
	}
	else {
		node->link = NULL;
		list->tail->link = node;
		list->tail = node;
	}
	list->length++;
}

void add(ListType* list, int position, element data)
{
	ListNode* p;
	if ((position >= 0) && (position <= list->length)) {
		ListNode* node = (ListNode*)malloc(sizeof(ListNode));
		if (node == NULL) {
			printf("Memory allocation error");
			return;
		}
		node->data = data;
		if (position == 0) {
			add_first(list, data);
		}
		else if (position == list->length) {
			add_last(list, data);
		}
		else {
			p = get_node_at(list, position - 1);
			insert_node(&(list->head), p, node);
		}
		list->length++;
	}
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

void delete_first(ListType* list) {
	list->head = list->head->link;
	if (list->length <= 2) {
		list->tail = list->head;
	}
	list->length--;
}

void delete_last(ListType* list) {
	ListNode* node = list->head;
	while (node->link != list->tail) {
		node = node->link;
	}
	list->tail = node;
	if (list->length <= 2) {
		list->head = list->tail;
	}
	list->length--;
}

void delete_node(ListType* list, int pos) {
	if (!is_empty(list) && (pos >= 0) && (pos < list->length)) {
		if (pos == 0) {
			delete_first(list);
		}
		else if (pos == list->length - 1){
			delete_last(list);
		}
		else {
			ListNode* p = get_node_at(list, pos - 1);

			ListNode* removed = get_node_at(list, pos);
			remove_node(&(list->head), p, removed);
		}

		list->length--;
	}
}


element get_entry(ListType* list, int pos)
{
	ListNode* p;
	if (pos >= list->length) {
		printf("Position Error.");
		return NULL;
	}
	p = get_node_at(list, pos);
	return p->data;
}

int is_in_list(ListType* list, element item)
{
	ListNode* p;
	p = list->head;
	while ((p != NULL)) {
		if (p->data == item)
			break;
		p = p->link;
	}
	if (p == NULL) return FALSE;
	return TRUE;
}

int main()
{
	ListType list1;
	init(&list1);
	add_first(&list1, 20);
	add_last(&list1, 30);
	add_first(&list1, 10);
	add_last(&list1, 40);
	add(&list1, 2, 70);
	display(&list1);
	delete_node(&list1, 2);
	delete_first(&list1);
	delete_last(&list1);
	display(&list1);
	printf("%s\n", (is_in_list(&list1, 20) == 1) ? "TRUE" : "FALSE");
	printf("%d\n", get_entry(&list1, 0));
}
