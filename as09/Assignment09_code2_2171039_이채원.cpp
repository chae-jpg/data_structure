#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <memory.h>

#define INPUT_SIZE  1000
#define  DATA_MAXVAL  10000

bool used[DATA_MAXVAL];

typedef struct TreeNode {
	int data;
	TreeNode* left;
	TreeNode* right;
} TreeNode;

void init(TreeNode* node) {
	node->data = NULL;
	node->left = NULL;
	node->right = NULL;
}

void bst_insert(TreeNode* node, int data) {
	TreeNode *parent = NULL, *temp;
	temp = (TreeNode*)malloc(sizeof(TreeNode));
	temp->data = data;
	temp->left = NULL;
	temp->right = NULL;
	if (node->data == NULL) {
		node->data = data;
		return;
	}
	while (node != NULL) {
		parent = node;
		if (data < node->data) node = node->left;
		else node = node->right;
	}
	if (data < parent->data) parent->left = temp;
	else parent->right = temp;
}

void bst_print(TreeNode* node) {
	if (node == NULL) return;
	bst_print(node->left);
	printf("%d\n", node->data);
	bst_print(node->right);
}

int main() {
	// output: sorted result
	int* input = (int*)malloc(sizeof(int) * INPUT_SIZE);
	TreeNode* root = (TreeNode*)malloc(sizeof(TreeNode));
	srand(time(NULL));
	memset(used, false, INPUT_SIZE);
	init(root);
	// Generate an input data randomly
	for (int i = 0; i < INPUT_SIZE; i++) {
		int n;
		do {
			n = rand() % DATA_MAXVAL;
		} while (used[n]);
		used[n] = true;
		input[i] = n;
		bst_insert(root, n);
	}
			
	bst_print(root);



}