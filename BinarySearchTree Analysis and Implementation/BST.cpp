/**
* Title: Binary Search Trees
* Author : Dilara Mandiraci
* ID: 22101643
* Section : 1
* Homework : 2
* Description : This file includes the function implementations of BST.h class */
#include "BST.h"

BST::BST() {
    nodeNumber = 0;
    root = nullptr;
}

BST::~BST() {
    delete root;
}

int BST::getNodeNumber() const {
    return nodeNumber;
}

BSTNode *BST::getRoot() const {
    return root;
}

void BST::insertItem(int key){

    BSTNode* addedNode = new BSTNode(key);

    if(root == nullptr){
        nodeNumber++;
        root = addedNode;
        return;
    }

    BSTNode* prev = nullptr;
    BSTNode* curr = root;

    while(curr != nullptr)
    {
        if(curr->data < key)
        {
            prev = curr;
            curr = curr->right;
        }
        else if(curr->data>key) //curr->data > key
        {
            prev = curr;
            curr = curr->left;
        }
        else
        {
            delete addedNode;
            return;
        }

    }

    if (prev->data > key){
        prev->left = addedNode;
    }
    else{
        prev->right = addedNode;
    }
    nodeNumber++;
}

void BST::deleteItem(int key) {
    deleteNode(root, key);
}

void BST::processLeftmost(BSTNode *&nodePtr, int &treeItem) {

    if (nodePtr->left == nullptr) {
        treeItem = nodePtr->data;
        BSTNode *delPtr = nodePtr;
        nodePtr = nodePtr->right;
        delPtr->right = nullptr;
        delete delPtr;
    }
    else
        processLeftmost(nodePtr->left, treeItem);
}

void BST::deleteNode(BSTNode *&bstNode, int key) {
    if(bstNode == nullptr)
    {
        cout << "deletion failed" <<endl;
        return;
    }
    if(key == bstNode->data)
    {
        nodeNumber--;
        //deletion
        BSTNode* dltNode;
        int repItem;

        if(bstNode->left == nullptr && bstNode->right == nullptr) //if leaf: can directly delete dltNode
        {
            delete bstNode;
            bstNode = nullptr;
        }

        //if it has only one child(left or right then after deleting node, replace it with that child)
        else if(bstNode->left == nullptr) //no left child
        {
            dltNode = bstNode;
            bstNode = bstNode->right;
            dltNode->right = nullptr;
            delete dltNode;
        }

        else if(bstNode->right == nullptr) //no right child
        {
            dltNode = bstNode;
            bstNode = bstNode->left;
            dltNode->left = nullptr;
            delete dltNode;
        }

        else //has two children
        {
            processLeftmost(bstNode->right, repItem);
            bstNode->data = repItem;
        }

    }
    else if(key < bstNode->data)
    {
        deleteNode(bstNode->left, key);
    }
    else
    {
        deleteNode(bstNode->right, key);
    }
}

void BST:: inorder(int* arr, BSTNode* root, int &index){
    if (root==nullptr)
    {
        return;
    }

    inorder(arr, root->left, index);
    arr[index++] = root->data;
    inorder(arr, root->right, index);
}

int* BST::inorderTraversal(int &length){
    length = nodeNumber;
    int* result = new int[length];
    int ind = 0;
    inorder(result, root, ind);
    return result;
}

bool isInTheArray(int*seq, int size, int element)
{
    for(int i = 0; i<size; i++)
    {
        if(seq[i] == element)
        {
            return true;
        }
    }
    return false;
}

void BST:: helperSeq(BSTNode* curr, int& n, int* seq, int size, int min, int max){
    if(curr == nullptr)
    {
        return;
    }
    int currel = curr->getData();
    cout << "visited element is: " << currel << endl;
    bool isCount = isInTheArray(seq, size, currel);
    if(currel >= min && currel <=max && !isCount)
    {
        n++;
    }
    if(isCount)
    {
        n++;
    }
    if(min < currel && max <= currel)
    {
         helperSeq(curr->getLeftPtr(), n ,seq, size, min, max);
    }
    else if(min>=currel && max>currel)
    {
         helperSeq(curr->getRightPtr(), n ,seq, size, min, max);
    }
    else{
        helperSeq(curr->getLeftPtr(), n ,seq, size, min, max);
        helperSeq(curr->getRightPtr(), n ,seq, size, min, max);
    }

}

bool BST::hasSequence(int *seq, int length) {
    BSTNode* current = root;
    int found = 0;
    int min = seq[0];
    int max = seq[length-1];
    helperSeq(current, found, seq, length, min, max);
    if(found == length)
    {
        return true;
    }
    return false;
}


