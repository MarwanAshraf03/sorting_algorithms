what is wrong with this code
#ifndef SORT_H
#define SORT_H
#include <stdlib.h>
#include <stdio.h>
/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

void print_array(const int *array, size_t size);
void print_list(const listint_t *list);
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void swap_b(listint_t *temp2);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
#endif
#include "sort.h"

/**
 * print_list - Prints a list of integers
 *
 * @list: The list to be printed
 */
void print_list(const listint_t *list)
{
    int i;

    i = 0;
    while (list)
    {
        if (i > 0)
            printf(", ");
        printf("%d", list->n);
        ++i;
        list = list->next;
    }
    printf("\n");
}

/**
 * print_array - Prints an array of integers
 *
 * @array: The array to be printed
 * @size: Number of elements in @array
 */
void print_array(const int *array, size_t size)
{
    size_t i;

    i = 0;
    while (array && i < size)
    {
        if (i > 0)
            printf(", ");
        printf("%d", array[i]);
        ++i;
    }
    printf("\n");
}
/**
 * insertion_sort_list - sorts a linked list using insertion sort algorithm
 * @list: list to be sorted
*/
void insertion_sort_list(listint_t **list)
{
	listint_t *temp1, *temp2, *temp3, *temp4;

	temp1 = (*list);
	while (temp1)
	{
		temp2 = temp1;
		while (temp2->prev)
		{
			temp3 = temp2->prev;
			temp4 = temp2->next;
			if (temp2->n < temp2->prev->n)
			{
				if (!(temp3->prev))
				{
					temp2->prev = NULL;
					*list = temp2;
					temp3->next = temp4;
					if (temp4)
						temp4->prev = temp3;
					temp2->next = temp3;
					temp3->prev = temp2;
				}
				else
					swap_b(temp2);
				print_list(*list);
			}
			else
				break;
		}
		temp1 = temp1->next;
	}
}
/**
 * swap_b - swaps temp2 with previous node
 * @temp2: node to be swapped
*/
void swap_b(listint_t *temp2)
{
	listint_t *temp3, *temp4;

	temp3 = temp2->prev;
	temp4 = temp2->next;
	if (temp3->prev)
	{
		temp3->prev->next = temp2;
		temp2->prev = temp3->prev;
		if (!temp4)
			temp3->next = NULL;
		else
		{
			temp3->next = temp4;
			temp4->prev = temp3;
		}
		temp2->next = temp3;
		temp3->prev = temp2;
	}
}
