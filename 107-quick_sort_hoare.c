#include "sort.h"

/**
 * swap - swaps two eleents in an array
 * @a: index of element 1
 * @b: index of element 2
 * @array: array
 * @size: size of array
 */
void swap(int a, int b, int *array, int size)
{
	int tmp = array[a];

	array[a] = array[b];
	array[b] = tmp;
	print_array(array, size);
}

/**
 * partition - divides the array into 2 subarrays and sorts them
 * @array: pointer to array
 * @lo: low end index of array
 * @hi: high end index of array
 * @size: size of array
 *
 * Return: pivot
 */
int partition(int *array, int lo, int hi, int size)
{
	int i, j, pivot;

	pivot = array[hi];
	i = lo - 1;
	j = hi + 1;

	while (i < j)
	{
		do {
			i++;
		} while (array[i] < pivot);

		do {
			j--;
		} while (array[j] > pivot);

		if (i < j)
			swap(i, j, array, size);
	}
	return (i);
}

/**
 * sort - helper function to do recursion
 * @array: array
 * @lo: low end index of array
 * @hi: hi end index of array
 * @size: size of array
 */
void sort(int *array, int lo, int hi, int size)
{
	int p;

	if (hi - lo > 0)
	{
		p = partition(array, lo, hi, size);
		sort(array, lo, p - 1, size);
		sort(array, p, hi, size);
	}
}

/**
 * quick_sort_hoare - quick sorts using Hoare Partiton scheme
 * @array: pointer to array
 * @size: size of the array
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size <= 1)
		return;

	sort(array, 0, size - 1, size);
}
