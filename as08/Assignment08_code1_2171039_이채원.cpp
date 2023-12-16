#include <stdio.h>
#define MAX_ELEMENT 200
typedef int element;
typedef struct {
	element heap[MAX_ELEMENT];
	int heap_size;
} HeapType;

void decrease_key_min_heap(HeapType* h, int i, int key) {
	if (h->heap[i] <= key) {
		printf("\nNew key is not smaller than current key\n");
		return;
	}

	h->heap[i] = key;
	while (i > 1 && h->heap[i / 2] > key) {
		h->heap[i] = h->heap[i / 2];
		h->heap[i / 2] = key;
		i /= 2;
	}
	printf("\ndecrease operation success.\n");
	printf("The new index of the element is %d, and its data is %d.\n", i, h->heap[i]);
}

void increase_key_min_heap(HeapType* h, int i, int key) {
	int parent, child;
	if (h->heap[i] >= key) {
		printf("\nNew key is not larger than current key\n");
		return;
	}

	h->heap[i] = key;
	parent = i, child = i * 2;

	while (child <= h->heap_size) {
		if (child < h->heap_size && h->heap[child] > h->heap[child + 1]) child++;
		if (h->heap[parent] <= h->heap[child]) break;

		h->heap[parent] = h->heap[child];
		h->heap[child] = key;
		parent = child; child *= 2;
	}
	printf("\nincrease operation success.\n");
	printf("The new index of the element is %d, and its data is %d.\n", parent, h->heap[parent]);
}

element delete_min_heap(HeapType* h) {
	int parent, child;
	element item, temp;

	item = h->heap[1];
	temp = h->heap[h->heap_size--];
	h->heap[1] = temp;
	parent = 1;
	child = 2;

	while (child <= h->heap_size) {
		if (child < h->heap_size && h->heap[child] > h->heap[child + 1]) child++;
		if (h->heap[parent] <= h->heap[child]) break;

		h->heap[parent] = h->heap[child];
		h->heap[child] = temp;
		parent = child; child *= 2;

	}
	return item;

}

int main() {
	HeapType h = { {0, 1, 4, 2, 7, 5, 3, 3, 7, 8, 9} , 10 };

	decrease_key_min_heap(&h, 4, 3);
	increase_key_min_heap(&h, 3, 10);
	decrease_key_min_heap(&h, 5, 8);
	printf("\nHeap elements : ");
	while (h.heap_size) {
		int t = delete_min_heap(&h);
		printf("%d ", t);
	}
}