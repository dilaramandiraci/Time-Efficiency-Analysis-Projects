/**
* Title: Binary Search Trees
* Author : Dilara Mandiraci
* ID: 22101643
* Section : 1
* Homework : 2
* Description : Class of binary search tree */
#ifndef _BST_H
#define _BST_H

#include "BSTNode.h"
#include <iostream>
using namespace std;

class BST{
public:
    BST();
    ~BST();
    void insertItem(int key);
    void deleteItem(int key);
    int* inorderTraversal(int& length);
    bool hasSequence(int* seq, int length);
    int getNodeNumber() const;
    BSTNode* getRoot() const;

private:
    BSTNode* root;
    int nodeNumber;
    void inorder(int* arr, BSTNode* root, int& index);
    void deleteNode(BSTNode* &bstNode, int key);
    void processLeftmost(BSTNode *&nodePtr,  int& treeItem);
    void helperSeq(BSTNode* curr, int& n, int* seq, int size, int min, int max);
};

#endif //_BST_H
