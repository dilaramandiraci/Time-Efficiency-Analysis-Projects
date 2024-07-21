/**
 * @file main.cpp
 * @author Dilara Mandıracı section 1 22101643
 * @brief 
 * @version 0.1
 * @date 2022-11-23
 * 
 * @copyright Copyright (c) 2022 
 */
#include "findMedian.h"
#include <iostream>
#include <ctime>
using namespace std;

int main()
{
    double duration;
    clock_t startTime;   
    //create the random array with size n 
    //because the size wanted to be so much bigger you need to store in heap 
    int size;
    cout << "Enter the size of the array that you want to analyze: " << endl;
    cin >> size;
    cout << endl;

    //create the array and fill it with integers from 1 to size
    int *array = new int [size];
    int ind=size/2;

    for(int i = 0; i<size; i++)
    {
        array[i] = ind-1;
        ind--;
    }

    //shuffle the array to destroy the sorted situation
    for(int i = 0; i<size; i++)
    {
        int index = rand()%size;
        int temp = array[i];
        array[i] = array[index];
        array[index] = temp;
    }

    //create the copy of the original array
    int *copyArray = new int [size];
    for(int i = 0; i<size; i++)
    {
        copyArray[i] = array[i];
    }

    cout << "FIND_MEDIAN_1 function is called" <<endl;
    //Store the starting time
    duration = 0;
    startTime = clock();
    FIND_MEDIAN_1( array, size);

    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "Execution took " << duration << " milliseconds." << endl; 
    cout<<endl;


    for(int i = 0; i<size; i++)
    {
        array[i] = copyArray[i];
    } 

    cout<<endl;
    cout << "FIND_MEDIAN_2 function is called" <<endl;
    duration = 0;
    startTime = clock();
    FIND_MEDIAN_2( array, size );

    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "Execution took " << duration << " milliseconds." << endl; 
    cout<<endl;


    for(int i = 0; i<size; i++)
    {
        array[i] = copyArray[i];
    }
    cout<<endl; 
    
    cout << "FIND_MEDIAN_3 function is called" <<endl;
    duration = 0;
    startTime = clock();
    FIND_MEDIAN_3( array, size);

    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "Execution took " << duration << " milliseconds." << endl;  

    cout<<endl; 

    delete[] array;
    delete[] copyArray;
    return 0;
}
