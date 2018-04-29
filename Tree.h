#pragma once
#include "LinkedList.h"

namespace Tree {
	struct Node;
	struct Root;
	struct Iterator;

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
	bool IsExist(Root *tree, int val);
	int __PushNode(Node*, int);
	bool __IsExist(Node*, int);

	void __PrintTree(Node *tree);
	void PrintTree(Root *my_tree);


	// struct Iterator {
	// 	Node* next;
	// };
	// Node *GetNext(Iterator &it) {
	// 	Node *result = it.next;
	// 	it.next = it.next->pLChild;
	// 	return result;
	// }

}