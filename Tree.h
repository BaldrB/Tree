#pragma once
#include "LinkedList.h"

namespace Tree {
	struct Node;
	struct Root;

	struct Root {
		Node *pRoot = nullptr;
	};

	struct Node {
		Node *pParent = nullptr;
		Node *pLChild = nullptr;
		Node *pRChild = nullptr;
		int *val;
		//LinkedList::List *pNebours = nullptr;
	};

	int Push(Root *tree, int val);
	int __PushNode(Node*, int);
}