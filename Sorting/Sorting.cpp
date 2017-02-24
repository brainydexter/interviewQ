#include "Sorting.h"

extern int (*gPrintFn)( const char * format, ... );

void InsertionSort(int* a, int size)
{
    for (int i = 0; i < size - 1; ++i)
    {
        // ar is sorted from 0 to j - 1
        int j = i + 1;

        int temp = a[j];

        while(j > 0 && temp < a[j - 1]){
            a[j] = a[j-1];
            j--;
        }
        a[j] = temp;
    }
}