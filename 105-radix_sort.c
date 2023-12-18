#include "sort.h"

/**
 * free_buckets - frees buckets
 * @table: list of buckets
 */
void free_buckets(listint_t *table[])
{
	int i;
	listint_t *node, *next;

	for (i = 0; i < 10; i++)
	{
		node = table[i];
		while (node)
		{
			next = node->next;
			free(node);
			node = next;
		}
		table[i] = NULL;
	}
}

/**
 * print_hash - prints the buckects
 * @table: pointer to an array of listint_t buckets
 */
void print_hash(listint_t *table[])
{
	int i;
	listint_t *node;

	for (i = 0; i < 10; i++)
	{
		node = table[i];
		if (node == NULL)
			printf("[%d] NULL\n", i);
		else
		{
			printf("[%d] ", i);
			while (node)
			{
				printf("%d", node->n);
				node = node->next;
				if (node)
					printf(", ");
				else
					printf("\n");
			}
		}
	}
	printf("\n");
}

/**
 * rebuild_array - rebuilds array from buckects
 * @array: pointer to the array
 * @table: buckets list
 */
void rebuild_array(int *array, listint_t *table[])
{
	int i, j;
	listint_t *node;

	for (i = 0, j = 0; i < 10; i++)
	{
		node = table[i];
		while (node)
		{
			array[j++] = node->n;
			node = node->next;
		}
	}
}

/**
 * radix_sort - sorts using radix sort LSD algorithm
 * @array: pointer to an array
 * @size: size of the array
 */
void radix_sort(int *array, size_t size)
{
	size_t i, pass;
	int n = 1, num, mod;
	listint_t *buckets[10] = {NULL}, *new, *node;

	if (!array || size <= 1)
		return;
	for (pass = 1; n != 0; pass *= 10)
	{
		for (i = 0, n = 0; i < size; i++)
		{
			new = malloc(sizeof(listint_t));
			if (new != NULL)
			{
				new->n = array[i];
				new->next = NULL;
				new->prev = NULL;
			}
			num = array[i] / pass;
			mod = num % 10;
			if (buckets[mod] == NULL)
			{
				buckets[mod] = new;
			}
			else
			{
				node = buckets[mod];
				while (node->next)
					node = node->next;
				node->next = new;
				new->prev = node;
			}
			if (num > n)
				n = num;
		}
		rebuild_array(array, buckets); /* print_hash(buckets);*/
		free_buckets(buckets);
		if (n != 0)
			print_array(array, size);
	}
}
