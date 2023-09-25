#include "sort.h"
/**
 * quick_sort - sort array using quick sort algorithm
 * @array: array to be sorted
 * @size: size of the array to be sorted
*/
void quick_sort(int *array, size_t size)
{
	qq(array, size, 0, size - 1);
}
/**
 * partition - partition array using Lomuto parition scheme
 * @array: array to be partitioned
 * @size: size of the array to be partitioned
 * @lbound: lower bound of array to be partitioned
 * @hbound: higher bound of array to be partitioned
 * Return: returns index of the pivot
*/
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
	return (temp_piv_idx);
}
/**
 * qq - quick sort algorithm
 * @array: array to be sorted
 * @size: size of the array to be sorted
 * @lbound: lower bound of array to be sorted
 * @hbound: higher bound of array to be sorted
*/
void qq(int *array, size_t size, int lbound, int hbound)
{
	int pivot;

	if (lbound >= hbound || lbound < 0)
		return;
	pivot = partition(array, size, lbound, hbound);
	qq(array, size, lbound, pivot - 1);
	qq(array, size, pivot + 1, hbound);
}
