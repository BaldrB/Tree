#include "Tree.h"
#include <iostream>

#include <set>




int main() {
	std::multiset<int> m_set = {5,4,6,2,1,3};
	for (auto it : m_set) {
		std::cout << it << ' ';
	}
	std::cout << std::endl;
	m_set.insert(3);
	for (auto it : m_set) {
		std::cout << it << ' ';
	}
	std::cout << std::endl;

	Tree::Root *my_tree = new Tree::Root;
	Tree::Push(my_tree, 5);
	Tree::Push(my_tree, 4);
	Tree::Push(my_tree, 6);
	
	Tree::Push(my_tree, 2);
	Tree::Push(my_tree, 1);
	Tree::Push(my_tree, 3);
	//Tree::Free(my_tree);
	delete my_tree; //todo delete all chids before
	return 0;
}