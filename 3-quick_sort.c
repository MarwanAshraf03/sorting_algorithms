#include <stdio.h>
#include "sort.h"
void quick_sort(int *array, size_t size)
{
    qq(array, size, 0, size - 1);
}

int partition(int *array, size_t size, int lbound, int hbound)
{
    int pivot = array[hbound], temp_piv_idx = lbound - 1, j, temp;

    for (j = lbound; j < hbound; j++)
    {
        if (array[j] <= pivot)
        {
            temp_piv_idx++;
            temp = array[temp_piv_idx];
            array[temp_piv_idx] = array[j];
            array[j] = temp;
            print_array(array, size);
        } 
    }
    temp_piv_idx++;
    temp = array[temp_piv_idx];
    array[temp_piv_idx] = array[hbound];
    array[hbound] = temp;
    print_array(array, size);
    return temp_piv_idx;
}
void qq(int *array, size_t size, int lbound, int hbound)
{
    int pivot;

    if (lbound >= hbound || lbound < 0)
        return;
    pivot = partition(array, size, lbound, hbound);
    qq(array, size, lbound, pivot - 1);
    qq(array, size, pivot + 1, hbound);
}