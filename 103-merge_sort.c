#include "sort.h"

/**
 * merge - merge from work_array to array
 * @ibegin: index of first element in array (Inclusive)
 * @imid: index of middle element in array
 * @iend: index of last element in array (Exclusive)
 * @work_array: array with sorted sub arrays to be merged
 * @array: array to merge into
 */
void merge(int *array, size_t ibegin, size_t imid, size_t iend,
			int *work_array)
{
	size_t i, j, k;

	i = ibegin;
	j = imid;

	for (k = ibegin; k < iend; k++)
	{
		if (i < imid && (j >= iend || array[i] <= array[j]))
		{
			work_array[k] = array[i];
			i++;
		}
		else
		{
			work_array[k] = array[j];
			j++;
		}
	}
}

/**
 * split - splits the array into two arrays
 * @ibegin: index of first element of array (Inclusive)
 * @iend: index of last element of array (exclusive)
 * @array: array to split
 * @work_array: array to accomodate merge applications
 */
void split(int *work_array, size_t ibegin, size_t iend,	int *array)
{
	size_t imid;

	if (iend - ibegin <= 1)
		return;

	imid = (iend + ibegin) / 2;

	split(array, ibegin, imid, work_array);

	split(array, imid, iend, work_array);

	merge(work_array, ibegin, imid, iend, array);
	printf("Merging...\n");
	printf("[left]: ");
	print_array(work_array + ibegin, imid - ibegin);
	printf("[right]: ");
	print_array(work_array + imid, iend - imid);
	printf("[Done]: ");
	print_array(array + ibegin, iend - ibegin);
}

/**
 * merge_sort - sorts using merge sort
 * @array: pointer to array
 * @size: size of array
 */
void merge_sort(int *array, size_t size)
{
	size_t i;
	int *work_array;

	if (!array || size <= 1)
		return;
	work_array = malloc(sizeof(*work_array) * size);
	if (!work_array)
		return;

	for (i = 0; i < size; i++)
		work_array[i] = array[i];

	split(work_array, 0, size, array);
	free(work_array);
}
