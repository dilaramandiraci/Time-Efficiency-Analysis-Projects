/**
* Title: Algorithm analysis & Sorting
* Author : Dilara Mandiraci
* ID: 22101643
* Section : 1
* Homework : 1
* Description : This file contains the signatures of sorting algorithms. Which will be implemented in the sorting.cpp file */
#include <iostream>
using namespace std;

void insertionSort(int *arr, const int size, int &compCount, int &moveCount);
void bubbleSort(int *arr, const int size, int &compCount, int &moveCount);
void mergeSort(int *arr, const int size, int &compCount, int &moveCount);
void quickSort(int *arr, const int size, int &compCount, int &moveCount);
void hybridSort(int *arr, const int size, int &compCount, int &moveCount);
