#include "sort.h"
#include <stdio.h>

/**
 * selection_sort - Swapping the elemnt in-turn with the lowest element
 * @array: The array to be printed
 * @size: Number of elements in @array
 */
void selection_sort(int *array, size_t size)
{
	size_t i, itr, minm, key, itr2;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		minm = i;
		for (itr = i + 1; itr < size; itr++)
			if (array[minm] > array[itr])
				minm = itr;

		key = array[minm];
		for (itr2 = minm; itr2 > i; itr2--)
		{
			array[itr2] = array[itr2 - 1];
			array[i] = key;
		}
		print_array(array, size);
	}
}
