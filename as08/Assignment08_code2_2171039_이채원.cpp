#include <stdio.h>

#define MAX_VERTICES 8
#define INF 1000L
#define MAX_ELEMENT 200

typedef struct {
	int v;
	int size;
} element;
typedef struct {
	element heap[MAX_ELEMENT];
	int heap_size;
} HeapType;

int weight[MAX_VERTICES][MAX_VERTICES] =
{ { 0,3,INF,INF,INF,INF,INF,14 },
{ 3,0,8,INF,INF,INF,INF,10 },
{ INF,8,0,15,2,INF,INF,INF },
{ INF,INF,15,0,INF,INF,INF,INF },
{ INF,INF,2,INF,0,9,4,5 },
{ INF,INF,INF,INF,9,0,INF,INF },
{ INF,INF,INF,INF,4,INF,0,6 },
{ 14,10,INF,INF,5,INF,6,0 } };
bool selected[MAX_VERTICES];
int dist[MAX_VERTICES];
int parent[MAX_VERTICES];

void build_min_heap(HeapType* h) {
	for (int i = h->heap_size / 2; i > 0; i--) {
		element temp = h->heap[i];
		int parent = i;
		int child = i * 2;
		while (child <= h->heap_size) {
			// Find a larger child node
			if ((child < h->heap_size) &&
				(h->heap[child].size) > h->heap[child + 1].size)
				child++;
			if (temp.size <= h->heap[child].size) break;
			// Move down one level
			h->heap[parent] = h->heap[child];
			parent = child;
			child *= 2;
		}
		h->heap[parent] = temp;
	}
}

void decrease_key_min_heap(HeapType* h, int i, int key) {
	if (h->heap[i].size <= key) {
		printf("\nNew key is not smaller than current key\n");
		return;
	}

	h->heap[i].size = key;
	while (i > 1 && h->heap[i / 2].size > key) {
		element t = h->heap[i];
		h->heap[i] = h->heap[i / 2];
		h->heap[i / 2] = t;
		i /= 2;
	}
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
		if (child < h->heap_size && h->heap[child].size > h->heap[child + 1].size) child++;
		if (h->heap[parent].size <= h->heap[child].size) break;

		h->heap[parent] = h->heap[child];
		h->heap[child] = temp;
		parent = child; child *= 2;

	}
	return item;

}

void print_prim(int n) {
	int idx[MAX_VERTICES] = { -1, -1, -1, -1, -1, -1, -1, -1 };
	int s = 0;
	for (int i = 0; i < MAX_VERTICES; i++) {
		if (parent[i] == n) {
			printf("Vertex %d -> %d      edge: %d\n", n, i, dist[i]);
			idx[s++] = i;
		}
	}
	for (int i = 0; i < s; i++) {
		print_prim(idx[i]);
	}


}

int main() {
	HeapType h;
	h.heap_size = 1;

	for (int i = 0; i < MAX_VERTICES; i++) {
		dist[i] = INF;
		parent[i] = -1;
		selected[i] = false;
	}

	//set verticle 0 as an initial verticle
	dist[0] = 0;
	selected[0] = true;
	h.heap[1].size = dist[0];
	h.heap[1].v = 0;
	for (int i = 1; i < MAX_VERTICES; i++) {
		h.heap[h.heap_size+1].size = dist[i];
		h.heap[1+h.heap_size++].v = i;
	}
	build_min_heap(&h);
	
	for (int i = 0; i < MAX_VERTICES; i++) {
		element u = delete_min_heap(&h);
		selected[u.v] = true;
		printf("v : %d, dist : %d\n", u.v, u.size);
		for (int j = 0; j < MAX_VERTICES; j++) {
			if (!weight[u.v][j] || weight[u.v][j] == INF) continue;
			//if the node is still in the queue
			if (!selected[j] && weight[u.v][j] < dist[j]) {
				parent[j] = u.v;
				dist[j] = weight[u.v][j];
				for (int k = 0; k <= h.heap_size; k++) {
					if (h.heap[k].v == j) {
						decrease_key_min_heap(&h, k, dist[j]);
						break;
					}
				}
			}
		}
	}
	print_prim(0);
}