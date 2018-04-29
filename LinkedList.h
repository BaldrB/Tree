#pragma once

namespace LinkedList{
	struct Node;
	struct List;

	struct List {
		Node *pHead;
	};
	struct Node {
		int val;
		Node *pNext;
		Node *pPrev;
	};
}