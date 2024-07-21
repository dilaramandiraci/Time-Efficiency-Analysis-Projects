/* Title: Algorithm analysis & Sorting
* Author : Dilara Mandiraci
* ID: 22101643
* Section : 1
* Homework : 1
* Description : This is the sorting.cpp file which has implementations of the sprting functions declared in the sorting.h. This file also includes
 * additional methods that sorting functions uses such as "merge" and "partition". Also this file includes some helper functions to make implementations
 * easier. Since every functions signature are same in the sorting.h it would be harder to implement. Instead of modifiyng codes to that specific signature
 * I used helper functions with appropriate and straightforward signatures. I got helped from the cs202 slides because this algorithms are general facts there is no
 * any creativity except for making them suitable to our code.*/

#include "Dilara_Mandiraci_22101643_sorting.h"

void insertionSort(int *arr, const int size, int &compCount, int &moveCount){

    for (int unsorted = 1; unsorted < size; ++unsorted) {

        int nextItem = arr[unsorted];
        moveCount++;

        int loc = unsorted;

        while (loc > 0 && arr[loc - 1] > nextItem){

            compCount++; //for while part

            arr[loc] = arr[loc - 1];
            loc--;

            moveCount++; //for moving data from arr[loc-1] to arr[loc]

        }
        compCount++; //for the last while check

        arr[loc] = nextItem;
        moveCount++;

    }
}

void bubbleSort(int *arr, const int size, int &compCount, int &moveCount){
    bool sorted = false;

    for (int pass = 1; (pass < size) && !sorted; ++pass) {
        sorted = true;
        for (int index = 0; index < size-pass; ++index) {
            int nextIndex = index + 1;

            compCount++; //for below if part
            if (arr[index] > arr[nextIndex]) {

                int temp = arr[index];
                arr[index] = arr[nextIndex];
                arr[nextIndex] = temp;

                moveCount += 3; //3 move for swap operation
                sorted = false; // signal exchange
            }
        }
    }
}



void merge(int* array, int first, int mid, int last, int &compCount, int &moveCount, int size) {
    int tempArray[size];    // temporary array

    int first1 = first;    // beginning of first subarray
    int last1 = mid;        // end of first subarray
    int first2 = mid + 1;    // beginning of second subarray
    int last2 = last;        // end of second subarray
    int index = first1; // next available location in tempArray

    for (; (first1 <= last1) && (first2 <= last2); ++index) {

        if (array[first1] < array[first2]) {
            tempArray[index] = array[first1];
            ++first1;
        } else {
            tempArray[index] = array[first2];
            ++first2;
        }

        compCount += 1; // for the if statement in every step
        moveCount +=1; //for data movement in if or else part
    }

    // finish off the first subarray, if necessary
    for (; first1 <= last1; ++first1, ++index){
        tempArray[index] = array[first1];
        moveCount++;
    }

    // finish off the second subarray, if necessary
    for (; first2 <= last2; ++first2, ++index){
        tempArray[index] = array[first2];
        moveCount++;
    }

    // copy the result back into the original array
    for (index = first; index <= last; ++index){
        array[index] = tempArray[index];
        moveCount++;
    }

}

void mergeSortHelper(int *array, int first, int last, int &compCount, int &moveCount, int size) {

    if (first < last) {

        int mid = (first + last)/2; 	// index of midpoint

        mergeSortHelper(array, first, mid, compCount, moveCount, size);

        mergeSortHelper(array, mid+1, last, compCount, moveCount, size);

        // merge the two halves
        merge(array, first, mid, last, compCount, moveCount, size);
    }
}

/**
 * code is taken from slides cs 202, minor changes made due to compatibility with the signature of the given functions
 * @param arr
 * @param size
 * @param compCount
 * @param moveCount
 */
void mergeSort(int *arr, const int size, int &compCount, int &moveCount){

    mergeSortHelper(arr, 0, size-1, compCount, moveCount, size);
}

void partition(int* theArray, int first, int last,int &pivotIndex,int &compCount, int &moveCount) {

    int pivot = theArray[first]; // copy pivot
    moveCount++;

    // initially, everything but pivot is in unknown
    int lastS1 = first;           // index of last item in S1
    int firstUnknown = first + 1; // index of first item in unknown

    // move one item at a time until unknown region is empty
    for (  ; firstUnknown <= last; ++firstUnknown) {
        // Invariant: theArray[first+1..lastS1] < pivot
        //            theArray[lastS1+1..firstUnknown-1] >= pivot

        // move item from unknown to proper region
        compCount= compCount+1;
        if (theArray[firstUnknown] < pivot) {  	// belongs to S1
            ++lastS1;
            swap(theArray[firstUnknown], theArray[lastS1]);
            moveCount+=3;
        }	// else belongs to S2
    }
    // place pivot in proper position and mark its location
    swap(theArray[first], theArray[lastS1]);
    moveCount+=3;
    pivotIndex = lastS1;
}


void quickSortHelper(int* theArray, int first, int last,int &compCount, int &moveCount) {
// Precondition: theArray[first..last] is an array.
// Postcondition: theArray[first..last] is sorted.

    int pivotIndex;

    if (first < last) {

        // create the partition: S1, pivot, S2
        partition(theArray, first, last, pivotIndex,compCount,moveCount);

        // sort regions S1 and S2
        quickSortHelper(theArray, first, pivotIndex-1,compCount,moveCount);
        quickSortHelper(theArray, pivotIndex+1, last,compCount,moveCount);
    }
}


void quickSort(int *arr, const int size, int &compCount, int &moveCount){
    quickSortHelper(arr, 0, size-1, compCount, moveCount);
}

void hybridSortHelper(int* theArray, int first, int last,int &compCount, int &moveCount ){
    if(last-first <= 20)
    {
        int* small = &theArray[first];
        bubbleSort(small, last-first+1, compCount,moveCount);
        return;
    }
    int pivotIndex;
    if (first < last) {

        // create the partition: S1, pivot, S2
        partition(theArray, first, last, pivotIndex,compCount,moveCount);

        // sort regions S1 and S2
        hybridSortHelper(theArray, first, pivotIndex-1,compCount,moveCount);
        hybridSortHelper(theArray, pivotIndex+1, last,compCount,moveCount);
    }
}

void hybridSort(int *arr, const int size, int &compCount, int &moveCount){
    hybridSortHelper(arr,0,size-1,compCount,moveCount);
}





