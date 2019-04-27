/**
 * @file    Array.cpp
 * @brief   Implementation for basic array with sorting features
 * @author  Cade Powers
 * @date    4/1/2019
 */ 

#include "Array.h"

/**
 * @brief   Constructor for array
 * @param   newSize     Desired size
 * @param   order       Desired order
 */ 
Array::Array(int newSize, int order)
{
    size = newSize;
    data = new int[size];
    for (int i = 0; i <= size - 1; i++)
        switch (order)
        {
        case RANDOM:
            data[i] = rand();
            break;
        case IN_ORDER:
            data[i] = i;
            break;
        case REVERSE_ORDER:
            data[i] = size - (i + 1);
            break;
        } // end switch
    return;
}

/**
 * @brief   Copy constructor for array
 * @param   original    Orginal array
 */ 
Array::Array(const Array &original)
{
    size = original.size;
    data = new int[size];
    for (int i = 0; i <= size - 1; i++)
        data[i] = original.data[i];
    return;
}

/**
 * @brief Releases the dynamic array
 */ 
Array::~Array()
{
    delete[] data;
}

/**
 * @brief   Writes the array to a stream
 * @param   outfile     File to write to
 * @param   sortname    Type of sort performed
 * @param   ordername   Order type of array
 */ 
void Array::write(std::ostream &outfile, const char *sortName, const char *orderName)
{
    outfile << "Sorted by:  " << sortName << std::endl;
    outfile << "Ordered by:  " << orderName << std::endl;
    for(int item = 0; item < size - 1; ++item){
        outfile << data[item] << " , ";
    }
    outfile << data[size - 1] << std::endl << std::endl;
}

/**
 * @brief   swaps two numbers
 * @param   a   one number
 * @param   b   second number
 */ 
void Array::swap(int &a, int&b)
{
    std::swap(a, b);
}

/**
 * @brief   Intializes array with shell sizes
 */ 
void Array::initShellH()
{
    shellH[0] = 1;
    for(int element = 1; element < 22; ++element){
        shellH[element] = 3 * shellH[element-1] + 1;
    }
}

/**
 * @brief   Sorts the array using Insertion Sort Algorithm 
 */ 
void Array::insertionSort()
{
    for(int iterator = 1; iterator < size; ++iterator){
        int currentIndex = iterator;
        while(currentIndex > 0 && data[currentIndex -1] > data[currentIndex]){
            swap(data[currentIndex], data[currentIndex - 1]);
            --currentIndex;
        }
    }
}

/**
 * @brief   Sorts the array using Selection Sort Algorithm
 */ 
void Array::selectionSort()
{
    for(int position = 0; position < size-1; ++position){
        int tempstorage = position;
        for(int search = position; search < size; ++search){
            if(data[tempstorage] > data[search])
                tempstorage = search;
        }
        swap(data[tempstorage], data[position]);
    }
}

/**
 * @brief   Sorts the array using Bubble Sort Algorithm
 */ 
void Array::bubbleSort()
{   
    bool swapped = false;
    int counter = 1;
    do
    {
        swapped = false;
        for(int current = 0; current < size - counter; ++current){
            if(data[current] > data[current+1]){
                swap(data[current], data[current+1]);
                swapped = true;
            }
        }
        counter++;
    } while (swapped);
}

/**
 * @brief   Sorts the array using Shell Sort Algorithm
 */ 
void Array::shellSort()
{
    initShellH();   //initilize shell size hierachy
    int stride = 0; //determine stride amount
    while(size < shellH[stride])
        ++stride;
    if (stride > 0) 
        --stride;

    stride = shellH[stride];    //final stride amount

    for(int shell = 0; shell < stride; ++shell){
        bool swapped = false;
        int counter = 1;
        do
        {
            swapped = false;
            for (int iteration = 0; iteration * stride + shell < size - stride; ++iteration)    //iteration * stride + shell calculates the indexes according to the stride
            {
                if (data[iteration*stride + shell] > data[(iteration+1) * stride + shell]){
                    swap(data[iteration * stride + shell], data[(iteration + 1) * stride + shell]);
                    swapped = true;
                }
            }
            counter++;
        } while (swapped);
    }

}

/**
 * @brief   Sorts the array using Heap Sort Algorithm
 */
void Array::heapSort()
{
    heap_sort(data, size);
}

/**
 * @brief   Sorts the array using Quick Sort Algorithm
 */
void Array::quickSort()
{
    quicksort(data, size-1);
}

/**
 * @brief   Sorts the array using Merge Sort Algorithm
 */
void Array::mergeSort()
{
    merge_sort(data, size);
}

/**
 * @brief   Sorts the array using Radix Sort Algorithm
 */
void Array::radixSort()
{
    int* bins[10];
    for(int binIndx = 0; binIndx < 10; ++binIndx)
        bins[binIndx] = new int[size];
    for(int digitIndx = 0; digitIndx < 10; ++digitIndx){
        int binCounts[10];
        for(int i = 0; i < 10; ++i)
            binCounts[i] = 0;
        for(int j = 0; j < size; ++j){
            int digit = data[j] / static_cast<int>(pow(10, digitIndx)) % 10;
            (bins[digit])[binCounts[digit]] = data[j];  //place data
            binCounts[digit]++;                         //update size
        }
        int currentPlace = 0;
        for(int i = 0; i <= 9; ++i){
            for(int digitIterator = 0; digitIterator < binCounts[i]; ++digitIterator){
                data[currentPlace] = (bins[i])[digitIterator];
                ++currentPlace;
            }            
        }
    }
    for (int binIndx = 0; binIndx < 10; ++binIndx)  //delete temporary storage arrays
        delete[] bins[binIndx];
}