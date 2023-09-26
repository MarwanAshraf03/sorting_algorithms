#include "sort.h"
/**
 * counting_sort - sorts an array using counting sort algorithm
 * @array: array to be sorted
 * @size: size of the array
*/
void counting_sort(int *array, size_t size)
{
	int *count, *sorted = malloc(sizeof(int) * size), j, max = array[0];
	size_t i;

	if (size < 2)
		return;
	for (i = 1; i < size; i++)
		if (array[i] > max)
			max = array[i];
	count = malloc(sizeof(int) * (max + 1));
	for (j = 0; j < max + 1; j++)
		count[j] = 0;
	for (i = 0; i < size; i++) /* count occurunces */
		count[array[i]]++;
	for (j = 1; j < max + 1; j++) /* cumulative sum */
		count[j] += count[j - 1];
	print_array(count, max + 1);
	for (i = 0; i < size; i++)
		sorted[i] = 0;
	for (i = size - 1; i > 0; i--)
	{
		sorted[count[array[i]] - 1] = array[i];
		count[array[i]]--;
	}
	sorted[count[array[i]]] = array[i];
	count[array[i]]--;
	for (i = 0; i < size; i++)
		array[i] = sorted[i];
	free(sorted);
	free(count);
}
