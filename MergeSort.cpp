/**
 * @file    MergeSort.cpp
 * @brief   Implementation for Merge Sort on a basic array
 * @author  Cade Powers
 * @date    4/1/2019
 */

#ifndef MERGESORT_CPP
#define MERGESORT_CPP

/**
 * @brief   Merges two sections of an array into one sorted portion
 * @param   a        The partially sorted array
 * @param   left     Start point of merge
 * @param   middle   Break point
 * @param   right    End of merge
 */ 
inline void merge(int a[], int left, int middle, int right)
{
   int array1[middle - left + 1];
   int array2[right - middle];
   int array1Counter, array2Counter;
   int current = right;

   //seperate the two sorted arrays into containers
   for(array1Counter = 0; array1Counter < middle - left + 1; ++array1Counter)       
      array1[array1Counter] = a[left + array1Counter];
   
   for(array2Counter= 0; array2Counter < right - middle; ++array2Counter)
      array2[array2Counter] = a[middle + 1 + array2Counter];

   --array1Counter;
   --array2Counter;

   //merge two containers into one sorted array
   while(array1Counter >= 0 && array2Counter >= 0){
      if(array1[array1Counter] >= array2[array2Counter]){
         a[current] = array1[array1Counter];
         --array1Counter;
      } 
      else{
         a[current] = array2[array2Counter];
         --array2Counter;
      }
      --current;
   }

   //clean up containers
   while(array1Counter >= 0){
      a[current] = array1[array1Counter];
      --array1Counter;
      --current;
   }
   while(array2Counter >= 0){
      a[current] = array2[array2Counter];
      --array2Counter;
      --current;
   }
}

/**
 * @brief   Recursive definition for Merge Sort Algorithm
 * @param   a        Unsorted Array
 * @param   left     Beginning of sort
 * @param   right    End of sort
 */ 
inline void merge_sort (int a[], int left, int right)
{
   if (right-left > 0)
   {
       int middle = (left + right) / 2;
       merge_sort (a, left, middle);
       merge_sort (a, middle+1, right);
       merge (a, left, middle, right);
   }
}

/**
 * @brief   User friendly function call
 */ 
inline void merge_sort (int a[], int n)
{
   merge_sort (a, 0, n-1);
}

#endif