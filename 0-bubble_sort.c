#include "sort.h"
/**
 * bubble_sort - sorts an array using bubble sort algorithm
 * @array: array to be sorted
 * @size: size of the array
*/
void bubble_sort(int *array, size_t size)
{
	size_t swapped, temp, j;

	while (1)
	{
		swapped = 0;
		for (j = 0; j < size; j++)
		{
			if (array[j - 1] > array[j])
			{
				temp = array[j - 1];
				array[j - 1] = array[j];
				array[j] = temp;
				print_array(array, size);
				swapped = 1;
			}
		}
	if (!swapped)
		break;
	}
}

