#include "sort.h"

/**
 * swap - swaps 2 elements in an array
 * @a: index of a
 * @b: index of b
 * @array: pointer to array
 */
void swap(size_t a, size_t b, int *array)
{
	int tmp = array[a];

	array[a] = array[b];
	array[b] = tmp;
}

/**
 * shell_sort - execute shell sort using Knuth's sequence
 * @array: array
 * @size: size of array
 */
void shell_sort(int *array, size_t size)
{
	size_t h, i, j;

	if (!array || !*array || size <= 1)
		return;
	h = 1;
	while (h < size)
		h = (3 * h) + 1;
	if (h > size)
		h = (h - 1) / 3;

	/*printf("h: %ld\n", h);*/

	for (; h > 0; h = (h - 1) / 3)
	{
		for (j = h; j < size; j++)
		{
			/* printf("h: %ld j = %ld i = %ld\n", h, j, i);*/
			i = j - h;
			if (array[i] > array[j])
			{
				swap(i, j, array);
				while ((i >= h) && (array[i] < array[i - h]))
				{
					swap(i, i - h, array);
					i = i - h;
				}
			}
		}
		print_array(array, size);
	}
}
