/**
 * @file    Array.h
 * @brief   Class definition for an array containing different types of sorting algorithms
 * @author  Cade Powers 
 * @date    4/1/2019
 */

#ifndef ARRAY_H
#define ARRAY_H
#include <iostream>
#include <algorithm>
#include <cmath>
#include "HeapSort.cpp"
#include "QuickSort.cpp"
#include "MergeSort.cpp"

enum ORDERS
{
    RANDOM,
    IN_ORDER,
    REVERSE_ORDER
};

class Array
{
  public:
    Array(int size, int order);
    Array(const Array &original);
    ~Array();
    void write(std::ostream &outfile, const char *sortName, const char *orderName);
    int getSize() { return size; }

    void insertionSort();
    void selectionSort();
    void bubbleSort();
    void shellSort();
    void heapSort();
    void quickSort();
    void mergeSort();
    void radixSort();

  private:
    void swap(int &a, int &b);
    void initShellH();
    void moveDownHeap(int index, int size);

  private:
    int *data;
    int size;
    int shellH[20];
};

#endif