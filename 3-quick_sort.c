#include "sort.h"

/**
 * partition - the main function the chooses the pivot
 *
 * @array: the array we need to work on
 * @l: the most left element
 * @r: the most right element.
 * Return: the place of the pivot
 */

int partition(int *array, int l, int r)
{
	int itr;
	int pivot = array[r];
	int i = (l - 1);
	int temp;

	for (itr = l; itr <= r - 1; itr++)
	{
		if (array[itr] <= pivot)
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

/**
 * qs - recursive function to call partitiong function.
 *
 * @array: the array we need to work on
 * @l: the most left element
 * @r: the most right element.
 * Return: void
 */

void qs(int *array, int l, int r)
{
	int index;

	if (l >= r)
		return;

	index = partition(array, l, r);
	qs(array, l, index - 1);
	qs(array, index + 1, r);
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

	qs(array, 0, sizee - 1);
}
