/**
* Title: Binary Search Trees
* Author : Dilara Mandiraci
* ID: 22101643
* Section : 1
* Homework : 2
* Description : description of your code */
#include <iostream>
#include "BST.h"
#include "analysis.h"
using namespace std;

void inorder(int* arr, BSTNode* root, int &index){
    if (root==nullptr)
    {
        return;
    }

    inorder(arr, root->getLeftPtr(), index);
    arr[index++] = root->getData();
    inorder(arr, root->getRightPtr(), index);
}

BST* merge(const BST& tree1, const BST& tree2){
    int size2 = tree2.getNodeNumber();
    int* arr2 = new int[size2];
    int index = 0;

    inorder(arr2, tree2.getRoot(),index);

    int size1 = tree1.getNodeNumber();
    int* arr1 = new int[size1];
    int index1 = 0;
    inorder(arr1, tree1.getRoot(),index1);

    BST* mergedTree = new BST();

    for(int i = 0; i<size2; i++)
    {
        mergedTree->insertItem(arr2[i]);
    }
    for(int i = 0; i<size1; i++)
    {
        mergedTree->insertItem(arr1[i]);
    }

    delete[] arr2;
    delete[] arr1;
    return mergedTree;
}

void printArray(int* arr, int size)
{
    for(int i = 0; i<size; i++)
    {
        cout << arr[i] << "," ;
    }
    cout << endl;
}

void printMessageCheck(bool result)
{
    if(result)
    {
        cout<<"TRUE" <<endl;
    }
    else
    {
        cout<< "FALSE" <<endl;
    }
    cout<<endl;
}


int main() {

    cout <<"!----------------------------------------------------------------------!" <<endl;
    cout <<"------------------Insertion and Deletion check starts-------------------" <<endl;
    cout <<"------------------------------------------------------------------------" <<endl;
    cout<<endl;


    BST tree1;
    BST tree2;

    tree1.insertItem(30);
    tree1.insertItem(50);
    tree1.insertItem(15);
    tree1.insertItem(20);
    tree1.insertItem(10);
    tree1.insertItem(40);

    int n = tree1.getNodeNumber();
    int* testarr = tree1.inorderTraversal(n);
    cout << "Inorder traversal of the tree after only inserting some values in the order of 30-50-15-20-10-40" <<endl;
    printArray(testarr, n);
    delete[] testarr;

    //delete leaf
    tree1.deleteItem(40);

    n = tree1.getNodeNumber();
    testarr = tree1.inorderTraversal(n);
    cout << "After deleting a leaf node with value 40: " <<endl;
    printArray(testarr, n);
    delete[] testarr;

    //delete element with 1 node
    tree1.deleteItem(50);

    n = tree1.getNodeNumber();
    testarr = tree1.inorderTraversal(n);
    cout << "After deleting a node with one child whose value is 50: " <<endl;
    printArray(testarr, n);
    delete[] testarr;

    //delete element with 2 node
    tree1.deleteItem(30);

    n = tree1.getNodeNumber();
    testarr = tree1.inorderTraversal(n);
    cout << "After deleting a node with two children whose value is 30: " <<endl;
    printArray(testarr, n);
    delete[] testarr;

    cout<< "Trying to delete an element that is not in the BST: " <<endl;
    tree1.deleteItem(567);


    tree1.insertItem(30);
    tree1.insertItem(40);
    tree1.insertItem(50);

    cout <<"!----------------------------------------------------------------------!" <<endl;
    cout <<"----------------------Merge method check starts-------------------------" <<endl;
    cout <<"------------------------------------------------------------------------" <<endl;
    cout<<endl;


    int tr1size = tree1.getNodeNumber();
    int* tree1inorder = tree1.inorderTraversal(tr1size);
    cout << "Inorder traversal of tree 1: " <<endl;
    printArray(tree1inorder, tr1size);


    tree2.insertItem(1);
    tree2.insertItem(555);
    tree2.insertItem(777);
    tree2.insertItem(2);

    int tr2size = tree2.getNodeNumber();
    int* tree2inorder = tree2.inorderTraversal(tr2size);
    cout << "Inorder traversal of tree 2: " <<endl;
    printArray(tree2inorder, tr2size);


    BST* tree3 = merge(tree1, tree2);
    int msize = tree3->getNodeNumber();
    int* mergedInorder = tree3->inorderTraversal(msize);
    cout<< "Inorder traversal of merged tree generated from tree 1 and tree 2:" <<endl;
    printArray(mergedInorder, msize);

    cout << endl;


    cout <<"!----------------------------------------------------------------------!" <<endl;
    cout <<"------------------Has sequence method check starts----------------------" <<endl;
    cout <<"------------------------------------------------------------------------" <<endl;
    cout<<endl;

    BST SequenceTree;

    SequenceTree.insertItem(8);
    SequenceTree.insertItem(4);
    SequenceTree.insertItem(13);
    SequenceTree.insertItem(12);
    SequenceTree.insertItem(15);
    SequenceTree.insertItem(10);
    SequenceTree.insertItem(14);
    SequenceTree.insertItem(3);
    SequenceTree.insertItem(6);
    SequenceTree.insertItem(1);
    SequenceTree.insertItem(5);
    SequenceTree.insertItem(2);

    int sequenceTreeLength = 12;
    int* inorderOfSequenceTree = SequenceTree.inorderTraversal(sequenceTreeLength);

    cout << "Inorder traversal of sequence tree:" <<endl;
    printArray(inorderOfSequenceTree, sequenceTreeLength);
    cout << endl;

    int length1 = 6;
    int* sequence1 = new int[length1];

    sequence1[0] = 1;
    sequence1[1] = 2;
    sequence1[2] = 3;
    sequence1[3] = 4;
    sequence1[4] = 5;
    sequence1[5] = 6;


    cout<< "Check if the tree has the sequence: " ;
    printArray(sequence1,length1);

    bool result1 = SequenceTree.hasSequence(sequence1, length1);
    printMessageCheck(result1);


    int length2 = 4;
    int* sequence2 = new int[length2];

    sequence2[0] = 10;
    sequence2[1] = 12;
    sequence2[2] = 13;
    sequence2[3] = 15;

    cout<< "Check if the tree has the sequence: " ;
    printArray(sequence2,length2);

    bool result2 = SequenceTree.hasSequence(sequence2, length2);
    printMessageCheck(result2);


    int length = 3;
    int* sequence3 = new int[length];

    sequence3[0] = 10;
    sequence3[1] = 11;
    sequence3[2] = 12;

    cout<< "Check if the tree has the sequence: " ;
    printArray(sequence3,length);

    bool result3 = SequenceTree.hasSequence(sequence3, length);
    printMessageCheck(result3);

    cout<<endl;
    cout <<"!----------------------------------------------------------------------!" <<endl;
    cout <<"-----------------------Time Analysis check starts----------------------" <<endl;
    cout <<"------------------------------------------------------------------------" <<endl;
    cout<<endl;
    timeAnalysis();

    delete[] sequence1;
    delete[] sequence2;
    delete[] sequence3;
    delete[] inorderOfSequenceTree;

    delete[] mergedInorder;
    delete[] tree1inorder;
    delete[] tree2inorder;
    delete tree3;

    return 0;
}
