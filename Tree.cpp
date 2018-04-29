#include <iostream>
#include "Tree.h"

#include <assert.h>
#include <iomanip>

const int allLvL = 7;
const int linesall = 64;

int Tree::Push(Root *tree, int val)
{
    if (!tree)
    {
        return -1;
    }

    if (!tree->pRoot){
        tree->pRoot = new Tree::Node;
        tree->pRoot->val = new int(val);
        return 0;
    }
    return Tree::__PushNode(tree->pRoot, val);
}

int Tree::__PushNode(Node *node, int val)
{
    if (*node->val == val){
        return 1;
    }

    Node *child_node = nullptr;
    if (*node->val > val) {
        child_node = node->pLChild;
    } else {
        child_node = node->pRChild;
    }

    if (!child_node) {
        child_node = new Tree::Node;
        child_node->pParent = node;

        if (*node->val > val) {
            node->pLChild = child_node;
        } else {
            node->pRChild = child_node;
        }
        child_node->val = new int(val);
        return 0;
    }
    Tree::__PushNode(child_node, val);
}

bool Tree::__IsExist(Node *node, int val)
{
    if (!node) {
        return false;
    }
    if (*(node->val) == val) {
        return true;
    }

    return Tree::__IsExist(node->pRChild, val) ||
    Tree::__IsExist(node->pLChild, val);
}

bool Tree::IsExist(Root *tree, int val)
{
    if (!tree) {
        return false;
    }
    if (!tree->pRoot) {
        return false;
    }
    return Tree::__IsExist(tree->pRoot, val);
}


int levelSaves[allLvL][linesall];
int lev = 0;
int floors[allLvL];

void Tree::__PrintTree(Node *tree)
{
    if (*tree->val) {
        levelSaves[lev][floors[lev]] = *tree->val;
        floors[lev] = ++(floors[lev]);
    }
    if(!tree->pLChild)
    {
        floors[lev+1] = ++(floors[lev+1]);
        for (int i = lev+2, j = 1; i < allLvL; ++i)
        {
            j = j * 2;
            floors[i] = (floors[i]) + j;
        }
    }
    if(tree->pLChild)
    {
        ++lev;
        Tree::__PrintTree(tree->pLChild);
        --lev;
    }
    if(!tree->pRChild)
    {
        floors[lev+1] = ++(floors[lev+1]);
        for (int i = lev+2, j = 1; i < allLvL; ++i)
        {
            j = j * 2;
            floors[i] = (floors[i]) + j;
        }
    }
    if(tree->pRChild)
    {
        ++lev;
        Tree::__PrintTree(tree->pRChild);
        --lev;
    }

}

void Tree::PrintTree(Root *my_tree)
{
    Tree::__PrintTree(my_tree->pRoot);

    for (int i = 0; i < allLvL; ++i)
    {
        for (int j = 0; j < floors[i]; ++j)
        {
            if (levelSaves[i][j] != 0)
                std::cout << std::setw(4) << levelSaves[i][j] << " ";
        }
        std::cout << std::endl;
    }

}
