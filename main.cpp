#include "Tree.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <conio.h>

int main(int argc, char *argv[])
{
    srand(time(NULL));
    Tree::Root *my_tree = new Tree::Root;

    Tree::Push(my_tree, 20);
    Tree::Push(my_tree, 4);
    Tree::Push(my_tree, 60);
    Tree::Push(my_tree, 5);
    Tree::Push(my_tree, 25);
    Tree::Push(my_tree, 14);

    Tree::Push(my_tree, 2);
    Tree::Push(my_tree, 18);
    Tree::Push(my_tree, 19);
    Tree::Push(my_tree, 30);
    Tree::Push(my_tree, 13);
    Tree::Push(my_tree, 9);
    Tree::Push(my_tree, 1);
    Tree::Push(my_tree, 6);
    Tree::Push(my_tree, 3);
    Tree::Push(my_tree, 65);
    Tree::Push(my_tree, 26);
    Tree::Push(my_tree, 27);
    Tree::Push(my_tree, 24);

    Tree::PrintTree(my_tree);

    delete my_tree;

    getch();

    return 0;
}
