#include "sort.h"
/**
 * insertion_sort_list - sorts a linked list using insertion sort algorithm
 * @list: list to be sorted
*/
void insertion_sort_list(listint_t **list)
{
	listint_t *temp1, *temp2, *temp3, *temp4;

	if (!list || !*list || !(*list)->next)
		return;
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
