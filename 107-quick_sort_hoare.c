#include "sort.h"
/**
 * swap - swaps two numbers
 * @first: first number
 * @second: second number
 * @array: array to be sorted
 * @size: size of the array to be sorted
*/
void swap(int *array, size_t size, int *first, int *second)
{
	int temp;

	if (*first != *second)
	{
		temp = *first;
		*first = *second;
		*second = temp;
		print_array(array, size);
	}

}
/**
 * quick_sort_hoare - sort array using quick sort algorithm
 * @array: array to be sorted
 * @size: size of the array to be sorted
*/
void quick_sort_hoare(int *array, size_t size)
{
	qq_hoare(array, size, 0, size - 1);
}
/**
 * partition_hoare - partition array using Hoare parition scheme
 * @array: array to be partitioned
 * @size: size of the array to be partitioned
 * @lbound: lower bound of array to be partitioned
 * @hbound: higher bound of array to be partitioned
 * Return: returns index of the pivot
*/
int partition_hoare(int *array, size_t size, int lbound, int hbound)
{
	int pivot = array[((hbound - lbound) / 2) + lbound];
	size_t j = hbound, i = lbound;

	while (1)
	{
		while (array[i] < pivot)
			i++;
		while (array[j] > pivot)
			j--;
		if (i < j)
			swap(array, size, &array[i], &array[j]);
		else
			return (j);
	}
	return (i);
}
/**
 * qq_hoare - quick sort algorithm
 * @array: array to be sorted
 * @size: size of the array to be sorted
 * @lbound: lower bound of array to be sorted
 * @hbound: higher bound of array to be sorted
*/
void qq_hoare(int *array, size_t size, int lbound, int hbound)
{
	int pivot;

	if ((lbound < hbound) && (lbound >= 0) && (hbound >= 0))
	{
		pivot = partition_hoare(array, size, lbound, hbound);
		qq_hoare(array, size, lbound, pivot);
		qq_hoare(array, size, pivot + 1, hbound);
	}
}
