#include "sort.h"

/**
 * comp_n_swap - compares and swaps
 * @array: pointer to array
 * @a: index of the first element
 * @b: index of the next element
 * @dir: direction
 *
 * Description:
 * Compares and swaps i and j according to the direction
 * eg. ------> <-------
 *        UP      DOWN
 */
void comp_n_swap(int *array, size_t a, size_t b, int dir)
{
	int tmp;

	if (dir == (array[a] > array[b]))
	{
		tmp = array[a];
		array[a] = array[b];
		array[b] = tmp;
	}
}

/**
 * merge - sorts and merges
 * @array: pointer to array
 * @low: index of first element in sub array
 * @cnt: number of elements in sub array
 * @dir: direction
 */
void merge(int *array, size_t low, size_t cnt, int dir)
{
	size_t k, i;

	if (cnt > 1)
	{
		k = cnt / 2;
		for (i = low; i < low + k; i++)
			comp_n_swap(array, i, i + k, dir);
		merge(array, low, k, dir);
		merge(array, low + k, k, dir);
	}
}

/**
 * sort - helper function to perform recusion
 * @array: pointer to array
 * @low: low end of array
 * @cnt: number of elements in this sub array
 * @dir: direction
 * @size: size of original array
 */
void sort(int *array, size_t low, size_t cnt, int dir, size_t size)
{
	size_t k;
	char *DIRECTION[] = {"DOWN", "UP"};

	if (cnt > 1)
	{
		printf("Merging [%ld/%ld] (%s):\n", cnt, size, DIRECTION[dir]);
		print_array(array + low, cnt);

		k = cnt / 2;

		/* sort in ascending for first half */
		sort(array, low, k, 1, size);

		/* sort in descending order for second half */
		sort(array, low + k, k, 0, size);

		/* merge in ascending order */
		merge(array, low, cnt, dir);
		printf("Result [%ld/%ld] (%s):\n", cnt, size, DIRECTION[dir]);
		print_array(array + low, cnt);
	}
}

/**
 * bitonic_sort - sorts using bitonic sort recursively
 * @array: pointer to array
 * @size: size of the array
 */
void bitonic_sort(int *array, size_t size)
{
	/**
	 * 1 - UP   ---->
	 * 1 - DOWN <----
	 */
	sort(array, 0, size, 1, size);
}

/**
 * iterative_bitonic_sort - sorts using bitonic sort iteratively
 * @array: pointer to array
 * @size: size of the array
 */
void iterative_bitonic_sort(int *array, size_t size)
{
	size_t k, j, i, l, a;
	int tmp;

	printf("Merging [%ld/%ld] (UP):\n", size, size);
	print_array(array, size);

	for (k = 2; k <= size; k *= 2) /* counting bitonic sequence */
	{
		for (j = k / 2; j > 0; j /= 2) /* comparison distance */
		{
			for (i = 0; i < size; i++)
			{
				/* l is index of element to compare with array[i]*/
				l = i ^ j;
				if (l > i) /* l should always be infront of i */
				{
					/* a = 0 if i is in first 1/2 of sub array of k elements*/
					a = k & i;
					/*printf("k[%ld] %ld:  %ld <-> %ld\n", k, k & i, i, l);*/
					tmp = array[i];
					if (a == 0 && array[i] > array[l]) /* ascending  ----> */
					{
						array[i] = array[l];
						array[l] = tmp;
					}
					if (a != 0 && array[i] < array[l]) /* descending <---- */
					{
						array[i] = array[l];
						array[l] = tmp;
					}
				}
			}
			/* printf("-----------------------------------------\n"); */
		}
		/* printf("****************************************\n"); */
	}
}
