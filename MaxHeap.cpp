/**
 * @file    MaxHeap.cpp
 * @brief   Implementations of Max Heap funtionality
 * @author  Cade Powers
 * @date    12/4/2018
 */

#ifndef MAXHEAP_CPP
#define MAXHEAP_CPP
#include <algorithm>

/**
 * @brief   Inserts into a max heap
 * @param   v     The value to be inserted
 * @param   heap  The heap
 * @param   size  The size of the heap
 */
template <typename t_value>
void maxHeapInsert(t_value v, t_value heap[], int& size)
{
    int current = size;
    heap[current] = v;
    while (current > 0 && heap[current] > heap[static_cast<int>((current-1)/2)]){ //while current isn't at the beggining and value of current is greater than the value of the parent
        std::swap(heap[current], heap[static_cast<int>((current-1)/2)]);          //swap the numbers
        current = static_cast<int>((current-1)/2);                                //walk up the heap
    }
    size++;
}

/**
 * @brief   Restores the heap property of an array using the sift down algorithm
 * @param   heap          The heap being restored
 * @param   left_index    The bottom of the range
 * @param   right_index   The top of the range
 */
template <typename t_value>
void maxHeapSiftDown(t_value heap[], int left_index, int right_index)
{
    bool done = false;
    int current = left_index;
    while (!done && 2 * current + 1 <= right_index){                                            //while not done and not at end
        int maxChild = 2 * current + 1;
        if (2 * current + 2 <= right_index && heap[2 * current + 2] > heap[2 * current + 1])    //if right child isn't past the end and right child's value is larger than the left child
            maxChild = 2 * current + 2;                                                         //find bigger child
        if (heap[maxChild] > heap[current]){                                                    //if value at maxChild is larger than value at current
            std::swap(heap[maxChild], heap[current]);                                           //swap them
            current = maxChild;                                                                 //move down tree
        }
        else                                                                                    //swap didn't occure and the heap is restored
            done = true;
    }
}

/**
 * @brief   Simple user interface that calls the three param version
 * @param   heap    Heap to be restored
 * @param   size    The size of the heap
 */
template <typename t_value>
void maxHeapSiftDown(t_value heap[], int size)
{
    maxHeapSiftDown(heap, 0, size - 1);
}

/**
 * @brief   Removes a value from the top of the heap
 * @param   Heap    The heap
 * @param   Size    The size of the heap
 * @return  The value that was removed from the heap
 */
template <typename t_value>
t_value heapRemove(t_value heap[], int& size)
{
    t_value removed = heap[0];          //store to be returned later
    std::swap(heap[0], heap[size - 1]); //push it to end
    size--;
    maxHeapSiftDown(heap, size);        //restore heap
    return removed;
}

/**
 * @brief   Restores heap by using top down approach
 * @param   a     The heap
 * @param   size  The size of the heap
 */
template <typename t_value>
void makeMaxHeapTopDown(t_value a[], int size)
{
    int heap_size = 0;
    while (heap_size < size)
        maxHeapInsert(a[heap_size], a, heap_size);  //insert until the heap is full
}

/**
 * @brief   Heapifies using bottom-up algorithm
 * @param   a     The heap
 * @param   Size  The size of the heap
 */
template <typename t_value>
void makeMaxHeapBottomUp(t_value a[], int size)
{
    int subroot = static_cast<int>((size-1 - 1) / 2);
    while (subroot >= 0){
        maxHeapSiftDown(a, subroot, size - 1);
        subroot--;
    }
}

#endif
