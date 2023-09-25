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
 * partition - partition array using Lomuto parition scheme
 * @array: array to be partitioned
 * @size: size of the array to be partitioned
 * @lbound: lower bound of array to be partitioned
 * @hbound: higher bound of array to be partitioned
 * Return: returns index of the pivot
*/
int partition(int *array, size_t size, int lbound, int hbound)
{
	int pivot = array[hbound], j, i = lbound - 1;

	for (j = lbound; j < hbound; j++)
		if (array[j] < pivot)
			swap(array, size, &array[j], &array[++i]);
	swap(array, size, &array[j], &array[++i]);
	return (i);
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
