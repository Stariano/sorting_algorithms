#include "sort.h"

/**
 * swap_ints - Swap two integers in an array.
 * @a: The first integer to swap.
 * @b: The second integer to swap.
 */
void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * partition - the main function the chooses the pivot
 *
 * @array: the array we need to work on
 * @l: the most left element
 * @r: the most right element.
 * Return: the place of the pivot
 */

int partition(int *array, int l, int r, size_t size)
{
	int itr;
	int pivot = array[r];
	int i = (l - 1);
	int temp;

	for (itr = l; itr < r; itr++)
	{
		if (array[itr] < pivot)
		{
			i++;
			temp = array[i];
			array[i] = array[itr];
			array[itr] = temp;
		}
	}
	temp = array[i + 1];
	array[i + 1] = array[r];
	array[r] = temp;
	return (i + 1);
}

int partition(int *array, int left, int right, size_t size)
{
	int *pivot, above, below;

	pivot = array + right;
	for (above = below = left; below < right; below++)
	{
		if (array[below] < *pivot)
		{
			if (above < below)
			{
				swap_ints(array + below, array + above);
				print_array(array, size);
			}
			above++;
		}
	}

	if (array[above] > *pivot)
	{
		swap_ints(array + above, pivot);
		print_array(array, size);
	}

	return (above);
}
/**
 * qs - recursive function to call partitiong function.
 *
 * @array: the array we need to work on
 * @l: the most left element
 * @r: the most right element.
 * Return: void
 */

void qs(int *array, int l, int r, size_t size)
{
	int index;

	if (l >= r)
		return;

	index = partition(array, l, r, size);
	qs(array, l, index - 1, size);
	qs(array, index + 1, r, size);
}

/**
 * quick_sort - the main function the calls the recursive function.
 *
 * @array: the array we need to work on
 * @size: size of the array
 */

void quick_sort(int *array, size_t size)
{
	int sizee = size;

	if (!array || size < 2)
		return;

	qs(array, 0, sizee - 1, size);
}
