/**
* Title: Binary Search Trees
* Author : Dilara Mandiraci
* ID: 22101643
* Section : 1
* Homework : 2
* Description : description of your code */

#ifndef CS202HW2_BSTNODE_H
#define CS202HW2_BSTNODE_H

#include <iostream>
using namespace std;

class BSTNode{
    public:
        BSTNode();
        ~BSTNode();
        BSTNode(const int& item);
        BSTNode* getLeftPtr();
        BSTNode* getRightPtr();
        int getData();

    private:
    int data;
    BSTNode *left;
    BSTNode *right;

    friend class BST;
};
#endif //CS202HW2_BSTNODE_H
