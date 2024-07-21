/**
* Title: Binary Search Trees
* Author : Dilara Mandiraci
* ID: 22101643
* Section : 1
* Homework : 2
* Description : This file includes the function implementations of anaylsis.h  */
#include "analysis.h"

void arrayShuffler(int* array, int& size)
{
    for(int i = 0; i<size; i++)
    {
        int index = rand() % size;
        int temp = array[i];
        array[i] = array[index];
        array[index] = temp;
    }
}
void randomArrayGenerator(int* array, int& size){

    for(int i = 0; i<size; i++)
    {
        array[i] = i+1;
    }
    arrayShuffler(array,size);
}

void timeAnalysis(){

    int arrsize = 15000;
    int* array = new int[arrsize];
    randomArrayGenerator(array,arrsize);
    BST tree;

    double duration;
    clock_t startTime;

    int counter=0;
    int currSize=0;

    cout<<"Part e - Time analysis of Binary Search Tree - part1"<<endl;
    cout<<"----------------------------------------------"<<endl;
    cout<<"Tree Size----------------Time Elapsed---------"<<endl;
    cout<<"----------------------------------------------"<<endl;

    for(int i = 0; i<15000; i++)
    {
        if(counter ==0)
        {
            duration=0;
            startTime = clock();
        }
        int element = array[i];
        tree.insertItem(element);
        counter++;
        currSize++;

        if(counter == 1500)
        {
            duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
            printf("%-25d%-25.3f\n", currSize, duration);
            counter = 0;
        }
    }

    arrayShuffler(array,arrsize);

    counter=0;
    currSize=15000;


    cout<<"Part e - Time analysis of Binary Search Tree - part2"<<endl;
    cout<<"----------------------------------------------"<<endl;
    cout<<"Tree Size----------------Time Elapsed---------"<<endl;
    cout<<"----------------------------------------------"<<endl;

    for(int i = 0; i<15000; i++)
    {
        if(counter ==0)
        {
            duration=0;
            startTime = clock();
        }
        int element = array[i];
        tree.deleteItem(element);
        counter++;
        currSize--;

        if(counter == 1500)
        {
            duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
            printf("%-25d%-25.3f\n", currSize, duration);
            counter = 0;
        }
    }

    delete[] array;
}