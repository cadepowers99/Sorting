/**
 * @file    QuickSort.cpp
 * @brief   Implementation of Quick Sort algorithm
 * @author  Cade Powers
 * @date    11/23/2018
 */

#ifndef QUICKSORT_CPP
#define QUICKSORT_CPP
#include <cstdlib>
#include <algorithm>

/**
 * @brief   Partitions the array
 * @param   a       The array to be partitioned
 * @param   left    The left hand side of the range
 * @param   right   The tight hand side of the range
 * @return  The index of the pivot
 */
template <typename t_value>
int partition( t_value a[], const int left, const int right)
{
    int pivot_index = (rand() % (right - left)) + left;
    t_value pivot_value = a[pivot_index];
    std::swap(a[pivot_index], a[right]);
    pivot_index = left;
    for (int i = left; i < right; ++i){
        if (a[i] < pivot_value){
            std::swap(a[i], a[pivot_index]);
            ++pivot_index;
        }
    }
    std::swap(a[pivot_index], a[right]);
    return pivot_index;
}

/**
 * @brief   Sorts the array using a recursive Quick Sort algorithm
 * @param   a       Array to be sorted
 * @param   left    The left hand side of the array
 * @param   right   The right hand side of the array
 */
template <typename t_value>
void quicksort(t_value a[], const int left, const int right)
{
    if (left < right){
        int division = partition(a, left, right);
        quicksort(a, left, division - 1);
        quicksort(a, division + 1, right);
    }
}

/**
 * @brief   User Friendly Quick Sort funtion
 * @param   a     Array to be sorted
 * @param   size  The size of the array
 */
template <typename t_value>
void quicksort(t_value a[], const int size)
{
    quicksort(a, 0, size);
}

#endif
