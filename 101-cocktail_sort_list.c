#include "sort.h"

/**
 * swap - swaps two nodes in a list
 * @a: node 1
 * @b: node 2
 * @list: pointer to list
 */
void swap(listint_t *a, listint_t *b, listint_t **list)
{
	a->next = b->next;
	if (b->next)
		b->next->prev = a;

	b->prev = a->prev;
	if (a->prev)
		a->prev->next = b;
	else
		*list = b;

	a->prev = b;
	b->next = a;
}

/**
 * cocktail_sort_list - sorts using cocktail shaker sort algorithm
 * @list: pointer to pointer to a linked list
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *a, *b;
	int swapped;

	if (!list || !*list || !(*list)->next)
		return;

	b = (*list)->next;
	while (1)
	{
		swapped = 0;
		while (b)
		{
			a = b->prev;
			if ((a->n) > (b->n))
			{
				swap(a, b, list);
				print_list(*list);
				swapped = 1;
			}
			b = b->next;
		}

		if (swapped == 0)
			break;

		b = a;
		while (a)
		{
			b = a->next;
			if ((a->n) > (b->n))
			{
				swap(a, b, list);
				print_list(*list);
			}
			a = a->prev;
		}
	}
}
