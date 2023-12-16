#include "stdio.h"

typedef struct TreeNode {
	int data;
	struct TreeNode* left, * right, * parent;
} TreeNode;
// G
// C F
// A B D E
TreeNode n1 = { 'A', NULL, NULL, NULL };
TreeNode n2 = { 'B', NULL, NULL, NULL };
TreeNode n3 = { 'C', &n1, &n2, NULL };
TreeNode n4 = { 'D', NULL, NULL, NULL };
TreeNode n5 = { 'E', NULL, NULL, NULL };
TreeNode n6 = { 'F', &n4, &n5, NULL };
TreeNode n7 = { 'G', &n3, &n6, NULL };
TreeNode* exp = &n7;

TreeNode* tree_successor(TreeNode* p) {
	TreeNode* node;

	//if p has right child
	if (p->right != NULL) {
		node = p->right;
		//move left until node becomes null
		while (node != NULL) {
			p = node;
			node = node->left;
		}
		//node = null, p = null's parent -> return p
		return p;
	}

	//if p does not have right child
	node = p->parent;
	while (node != NULL && p == node->right) {
		//move up until p is right child of node
		p = node;
		node = node->parent;
	}
	return node;
}


void main()
{
	TreeNode* q = exp;
	n1.parent = &n3;
	n2.parent = &n3;
	n3.parent = &n7;
	n4.parent = &n6;
	n5.parent = &n6;
	n6.parent = &n7;
	n7.parent = NULL;
	while (q->left) q = q->left; // Go to the leftmost node
	do
	{
		printf("%c\n", q->data); // Output data
		// Call the successor
		q = tree_successor(q);
	} while (q); // If not null
}