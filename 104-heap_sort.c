#include "sort.h"

/**
 * swap - swap the elements at index a and b
 * @a: index of element a
 * @b: index of element b
 * @array: pointer to array
 * @N: original size of array
 */
void swap(size_t a, size_t b, int *array, size_t N)
{
	int tmp;

	if (a == b)
		return;
	tmp = array[a];
	array[a] = array[b];
	array[b] = tmp;
	print_array(array, N);
}

/**
 * heapify - move the top most element to its rightful position in the heap
 * @x: top element
 * @array: pointer to array
 * @size: current size of the array
 * @N: original size of the array
 */
void heapify(size_t x, int *array, size_t size, size_t N)
{
	size_t largest, left, right;

	largest	= x;
	left = 2 * x + 1;
	right = 2 * x + 2;

	if (left < size && array[left] > array[largest])
		largest = left;
	if (right < size && array[right] > array[largest])
		largest = right;

	if (largest != x)
	{
		swap(x, largest, array, N);

		heapify(largest, array, size, N);
	}
}

/**
 * heap_sort - sorts using the Heap sorting algorithm
 * @array: pointer to the array
 * @size: size of the array
 */
void heap_sort(int *array, size_t size)
{
	int i;

	if (!array || size <= 1)
		return;

	for (i = size / 2 - 1; i >= 0; i--)
		heapify(i, array, size, size);

	for (i = size - 1; i >= 0; i--)
	{
		swap(i, 0, array, size);

		heapify(0, array, i, size);
	}
}
