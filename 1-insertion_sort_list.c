#include "sort.h"

/**
 * insertion_sort_list - sorts using Insertion sort
 * @list: pointer to list to sort
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *a, *b, *next;

	if (!list || !*list || !(*list)->next)
		return;
	a = *list;
	b = (*list)->next;
	next = b->next;
	while (b)
	{
		while (a && b && (a->n > b->n))
		{
			a->next = b->next;
			if (b->next)
				b->next->prev = a;
			b->prev = a->prev;
			if (a->prev)
				a->prev->next = b;
			else
				*list = b;
			b->next = a;
			a->prev = b;
			print_list(*list);
			a = b->prev;
		}
		b = next;
		if (next)
		{
			a = next->prev;
			next = next->next;
		}
	}
}
