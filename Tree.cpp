#include "Tree.h"

int Tree::Push(Root *tree, int val)
{
	if (!tree) {
		return -1; // tree not init
	}

	if (!tree->pRoot) { //empty tree
		tree->pRoot = new Tree::Node;
		tree->pRoot->val = new int(val);
		return 0; // all is ok
	}
	return Tree::__PushNode(tree->pRoot, val);
}

int Tree::__PushNode(Node *node, int val)
{
	if (*node->val == val) {
		return 1; // already exists
	}

	Node *child_node = nullptr;
	if (*node->val > val) { // go left
		child_node = node->pLChild;
	}
	else {
		child_node = node->pRChild; // go right
	}

	if (!child_node) {
		child_node = new Tree::Node;
		child_node->pParent = node;

		if (*node->val > val) { 
			node->pLChild = child_node;
		}
		else {
			node->pRChild = child_node;
		}
		child_node->val = new int(val);
		return 0;
	}
	Tree::__PushNode(child_node, val); //repeat)
}
