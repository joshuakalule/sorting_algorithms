#include "sort.h"

/**
 * counting_sort - sorts using counting sort algorithm
 * @array: pointer to array
 * @size: size of array
 */
void counting_sort(int *array, size_t size)
{
	size_t c_size, i;
	int tmp, *count, *new;

	if (!array || size <= 1)
		return;
	tmp = array[0]; /* max integer in array */
	for (i = 1; i < size; i++)
	{
		if (array[i] > tmp)
			tmp = array[i];
	}
	c_size = tmp + 1; /* size of count array */
	count = malloc(sizeof(*count) * c_size);
	if (!count)
		return;
	memset(count, 0, sizeof(*count) * c_size);
	new = malloc(sizeof(*new) * size);
	if (!new)
	{
		free(count);
		return;
	}
	for (i = 0; i < size; i++)
		count[array[i]] += 1;
	tmp = 0;
	for (i = 0; i < c_size; i++)
	{
		count[i] += tmp;
		tmp = count[i];
	}
	print_array(count, c_size);
	for (i = 0; i < size; i++)
	{
		count[array[i]]--;
		new[count[array[i]]] = array[i];
	}
	for (i = 0; i < size; i++)
		array[i] = new[i];
	free(count);
	free(new);
}
