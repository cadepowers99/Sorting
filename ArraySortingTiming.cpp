/**
 * @file    ArraySortingTiming.cpp
 * @brief   Timing code for sorting algorithms desgined by Dr. E. T. Hammerand
 * @date    4/1/2019
 * @author  Cade Powers
 */

#include <ctime>
#include <iostream>
        using std::cout;
        using std::endl;
        using std::ios;
#include <iomanip>
        using std::setw;
        using std::setprecision;
#include <fstream>
#include "Array.h"

enum SORTS
{
    INSERTION,
    SELECTION,
    BUBBLE,
    SHELL,
    HEAP,
    QUICK,
    MERGE,
    RADIX
};
const char *SORT_NAMES[8] = {"Insertion", "Selection", "Bubble ", "Shell ",
                             "Heap ", "Quick ", "Merge ", "Radix "};

const char *ORDER_NAMES[3] = {"Random ", "InOrder", "Reverse"};

std::ofstream output{"output.txt"};

double sort(Array numbers, int sortType, int orderType)
{
    if (numbers.getSize() < 100) // debug small sorts only
        numbers.write(output , SORT_NAMES[sortType], ORDER_NAMES[orderType]);
    clock_t start = clock();
    switch (sortType)
    {
    case INSERTION:
        numbers.insertionSort();
        break;
    case SELECTION:
        numbers.selectionSort();
        break;
    case BUBBLE:
        numbers.bubbleSort();
        break;
    case SHELL:
        numbers.shellSort();
        break;
    case HEAP:
        numbers.heapSort();
        break;
    case QUICK:
        numbers.quickSort();
        break;
    case MERGE:
        numbers.mergeSort();
        break;
    case RADIX:
        numbers.radixSort();
        break;
    } // end switch
    clock_t finish = clock();
    if (numbers.getSize() < 100)
        numbers.write(output, SORT_NAMES[sortType], ORDER_NAMES[orderType]);
    return (finish - start) * 1.0 / CLOCKS_PER_SEC;
} // end function sort


int  main()
{
    srand(7);
    double epsilon = 0.0005;
    int size = 10;
    int sizeLimit = 1000;
    int multiplier = 5;
    double maxTime = 0;
    double timeLimit = 60;
    do
    {
        cout << setw(9) << size << " Random Inorder Reverse\n";
        Array *a[3]; // allocate dynamic arrays
        a[0] = new Array(size, RANDOM);
        a[1] = new Array(size, IN_ORDER);
        a[2] = new Array(size, REVERSE_ORDER);
        // enum SORTS: INSERTION, SELECTION, BUBBLE, SHELL, HEAP, QUICK, MERGE, RADIX
        for (int sortIndx = INSERTION; sortIndx <= RADIX; sortIndx++)
        {
            cout << SORT_NAMES[sortIndx] << " ";
            // enum ORDERS: RANDOM, IN_ORDER, REVERSE_ORDER
            for (int orderIndx = RANDOM; orderIndx <= REVERSE_ORDER; orderIndx++)
            {
                double time = sort(*a[orderIndx], sortIndx, orderIndx);
                if (maxTime < time)
                    maxTime = time;
                if (time > epsilon)
                    cout << setw(10) << setprecision(3)
                         << setiosflags(ios::showpoint | ios::fixed) << time;
                else // avoid distracting display of decimals for very small times
                    cout << " 0 ";
            } // end for orderIndx
            cout << endl;
        }                            // end for sortIndx
        for (int i = 0; i <= 2; i++) // free dynamic arrays
            delete a[i];
        size *= multiplier;                     // *5 or *2 for next array
        multiplier = (multiplier == 5) ? 2 : 5; // alternate multipliers
    }                                           // end do while
    while (maxTime < timeLimit && size <= sizeLimit);
    return 0;
} // end function