/**
* Title: Algorithm analysis & Sorting
* Author : Dilara Mandiraci
* ID: 22101643
* Section : 1
* Homework : 1
* Description : This is the main file that makes available to see the results of the each sorting algorithm. It has array generator methods and also a
 * main section to run the code. In the main section there are codes to calculate running time in miliseconds. */
#include <cmath>
#include <iostream>
#include <ctime>
#include "Dilara_Mandiraci_22101643_sorting.h"
using namespace std;

/**
 * This function is used to break the sorted situtation in between the given indices. For example an array [1,2,3,4,5,6] and given indices are 0 and 2
 * It will distribute the numbers between 0 and 2 which are 1,2,3 in random order. i.e, 2, 1, 3.
 * It enables that with first accepting the sorted array and then shuffling indices, and swappping the random numbers in between those indices.
 * @param array
 * @param start
 * @param end
 */
void indexBasedShuffler(int *array, int start, int end)
{
    int size = end-start+1;
    int indeces[size];
    int starttemp = start;

    for(int i = 0; i<size; i++ )
    {
        indeces[i] = starttemp;
        starttemp++;
    }

    for(int i = start; i<end+1; i++)
    {
        srand(time(NULL));
        int indexarr = rand() % size;
        int index = indeces[indexarr];
        int temp = array[i];
        array[i] = array[index];
        array[index] = temp;
    }
}

/**
 * I used my "own previous code" for that purpose.(To generate randomly distributed array)
 * It first creates a sorted array in the range of 0 to size-1
 * Then shuffles indices and swaps the elements from that randomly chosen indices.
 * @param array
 * @param size
 */
void randomArrayGenerator(int *array, int size){

    int ind=size/2;
    for(int i = 0; i<size; i++)
    {
        array[i] = ind-1;
        ind--;
    }

    //shuffle the array to destroy the sorted situation
    for(int i = 0; i<size; i++)
    {
        int index = rand() % size;
        int temp = array[i];
        array[i] = array[index];
        array[index] = temp;
    }
}

/**
 * First fills the array with ascending order starting from 0 to size-1
 * and calls index based shuffler function for a specific range (log(size)).
 * It makes this array partially ascending.
 * @param array
 * @param size
 */
void partiallyAscendingGenerator(int *array, int size){
    for(int i = 0; i<size; i++)
    {
        array[i] = i;
    }
    int range = log2(size);
    int start = 0 ;
    int end = range-1;

    while(start<=end)
    {
        indexBasedShuffler(array,start,end);
        start = start + range;
        end = end + range;

        if(end > size-1)
        {
            end = size-1;

        }
    }
}

/**
 * First fills the array with descending order starting from size-1 to 0.
 * and calls index based shuffler function for a specific range (log(size)).
 * It makes this array partially descending.
 * @param array
 * @param size
 */
void partiallyDescendingGenerator(int *array, int size){
    int sizzz = size-1;
    for(int i = 0; i<size; i++)
    {
        array[i] = sizzz--;
    }

    int range = log2(size);
    int start = 0 ;
    int end = range-1;

    while(start<=end)
    {
        indexBasedShuffler(array,start,end);
        start = start + range;
        end = end + range;

        if(end > size-1)
        {
            end = size-1;

        }
    }
}

int main() {
    double duration;
    clock_t startTime;

    int compCount, moveCount;
    int sizes[] = {1000,5000,10000,20000};


    for(int j = 0; j<3; j++)
    {
        if(j==0)
            cout << "                         Part 2-b-1: Performance analysis of random integers array" << endl;
        else if(j==1)
            cout << "                     Part 2-b-2: Performance analysis of partially ascending integers array" << endl;
        else
            cout << "                     Part 2-b-3: Performance analysis of partially descending integers array" << endl;

        for(int size2b : sizes)
        {
            cout << "---------------------------------------------------------------------------------------------------------"<<endl;
            cout << "                            Elapsed time                  Comp. count               Move count" <<endl;
            cout << "Array Size: " << size2b <<endl;

            int* array = new int [size2b];
            if(j==0)
                randomArrayGenerator(array,size2b);
            if(j==1)
                partiallyAscendingGenerator(array, size2b);
            if(j==2)
                partiallyDescendingGenerator(array,size2b);

            //create the copy of the original array
            int *copyArray1 = new int [size2b];
            int *copyArray2 = new int [size2b];
            int *copyArray3 = new int [size2b];
            int *copyArray4 = new int [size2b];
            int *copyArray5 = new int [size2b];
            for(int i = 0; i < size2b; i++)
            {
                int el = array[i];
                copyArray1[i] = el;
                copyArray2[i] = el;
                copyArray3[i] = el;
                copyArray4[i] = el;
                copyArray5[i] = el;
            }

            /*
             * !!! Note: I got the code snippets for "calculating time" (duration calculation formula) from my own past cs201 homework. !!!
             */

            //INSERTION SORT
            compCount = 0, moveCount = 0, duration = 0;
            startTime = clock();
            insertionSort(copyArray1, size2b, compCount, moveCount);
            duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
            printf("%-28s%-30.3f%-26d%-32d\n", "Insertion Sort", duration, compCount, moveCount);

            //BUBBLE SORT
            compCount = 0, moveCount = 0, duration = 0;
            startTime = clock();
            bubbleSort(copyArray2, size2b, compCount, moveCount);
            duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
            printf("%-28s%-30.3f%-26d%-32d\n", "Bubble Sort", duration, compCount, moveCount);

            //MERGE SORT
            compCount = 0, moveCount = 0, duration = 0;
            startTime = clock();
            mergeSort(copyArray3, size2b, compCount, moveCount);
            duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
            printf("%-28s%-30.3f%-26d%-32d\n", "Merge Sort", duration, compCount, moveCount);

            //QUICK SORT
            compCount = 0, moveCount = 0, duration = 0;
            startTime = clock();
            quickSort(copyArray4, size2b, compCount, moveCount);
            duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
            printf("%-28s%-30.3f%-26d%-32d\n", "Quick Sort", duration, compCount, moveCount);

            //HYBRID SORT
            compCount = 0, moveCount = 0, duration = 0;
            startTime = clock();
            hybridSort(copyArray5, size2b, compCount, moveCount);
            duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
            printf("%-28s%-30.3f%-26d%-32d\n", "Hybrid Sort", duration, compCount, moveCount);

            //deleting all the arrays that we previously created so that not do have any memory leaks!
            delete[] array;
            delete[] copyArray1;
            delete[] copyArray2;
            delete[] copyArray3;
            delete[] copyArray4;
            delete[] copyArray5;
        }
    }

    return 0;
}

