#include "sort.h"

/**
 * e_swap - swaps two elements in an array
 * @a: index for a
 * @b: index for b
 * @array: array
 * @size: size
 */
void e_swap(size_t a, size_t b, int *array, size_t size)
{
	int tmp;

	if (a == b)
		return;
	tmp = array[a];
	array[a] = array[b];
	array[b] = tmp;
	print_array(array, size);
}

/**
 * partition - partition the array
 * @lo: low index
 * @hi: high index
 * @array: array
 * @size: size of array
 *
 * Return: index of the pivot
 *
 * Description: Find the sorted position of the pivot(hi)
 * This is done by finding an element less than pivot and
 * finding an element greater than pivot, and switching them.
 */
size_t partition(size_t lo, size_t hi, int *array, size_t size)
{
	int pivot = array[hi];
	size_t i, j;

	i = lo - 1;

	for (j = lo; j <= hi - 1; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			e_swap(i, j, array, size);
		}
	}
	i++;
	e_swap(i, hi, array, size);
	return (i);
}

/**
 * sort - helper function to accomodate for recursion
 * @lo: lower bound
 * @hi: upper bound
 * @array: array
 * @size: size of array
 */
void sort(size_t lo, size_t hi, int *array, size_t size)
{
	size_t pivot;

	if (lo >= hi)
		return;
	pivot = partition(lo, hi, array, size);
	if (pivot > lo)
		sort(lo, pivot - 1, array, size);
	if (pivot < hi)
		sort(pivot + 1, hi, array, size);
}
/**
 * quick_sort - sorts using quick sort by Lomuto
 * @array: array
 * @size: size of array
 */
void quick_sort(int *array, size_t size)
{
	if (!array || !*array)
		return;

	sort(0, size - 1, array, size);
}

