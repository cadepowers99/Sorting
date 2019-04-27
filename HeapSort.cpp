/**
 * @file    HeapSort.cpp
 * @brief   Implementation for heap sort algorithm
 * @author  Cade Powers
 * @date    12/4/2018
 */

#ifndef HEAPSORT_H
#define HEAPSORT_H
#include "MaxHeap.cpp"

/**
 * @brief   Sorts an array using heap sort algorithm
 * @param   a     The array to be sorted
 * @param   size  The size of the array
 */
template <typename t_value>
void heap_sort(t_value a[], int size)
{
    makeMaxHeapBottomUp(a, size);           //heapifies the array to make it in a sortable condition
    int elementsRemaining = size;
    while (elementsRemaining > 1)
        heapRemove(a, elementsRemaining);   //removes one element from the array
}


#endif
