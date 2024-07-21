/**
* Title: Binary Search Trees
* Author : Dilara Mandiraci
* ID: 22101643
* Section : 1
* Homework : 2
* Description : To construct binary tree we need special nodes named bstnode which has two pointer left and right */
#include "BSTNode.h"

BSTNode::BSTNode() {
    left = nullptr;
    right = nullptr;
    data = 0;
}

BSTNode::~BSTNode() {
    delete left;
    delete right;
}

BSTNode::BSTNode(const int& item){
    this->data = item;
    this->left = nullptr;
    this->right = nullptr;
}

BSTNode *BSTNode::getLeftPtr() {
    return left;
}

BSTNode *BSTNode::getRightPtr() {
    return right;
}

int BSTNode::getData() {
    return data;
}
