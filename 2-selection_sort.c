#include "sort.h"
#include <stdio.h>

/**
 * selection_sort - Swapping the elemnt in-turn with the lowest element
 * @array: The array to be printed
 * @size: Number of elements in @array
 */
void selection_sort(int *array, size_t size)
{
	int temp;
	size_t itr_min, itr, minm;

	if (array == NULL || size < 2)
		return;

	for (itr_min = 0; itr_min < size; itr_min++)
	{
		minm = itr_min;
		for (itr = itr_min + 1; itr < size; itr++)
		{
			if (array[minm] > array[itr])
				minm = itr;

			if (minm != itr_min)
			{
				temp = array[minm];
				array[minm] = array[itr_min];
				array[itr_min] = temp;
			}
		}
		print_array(array, size);
	}
}
