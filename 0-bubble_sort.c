#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "sort.h"
/**
 * bubble_sort - Sort an array of integers in ascending order.
 * @array: An array of integers to sort.
 * @size: The size of the array.
 *
 * Description: Prints the array after each swap.
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, len;
	int temp;
	bool swapped = false;

	if (array == NULL || size < 2)
		return;

	for (len = 0; len < size - 1; len++)
	{
		for (i = 0; i < size - len - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				temp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = temp;
				print_array(array, size);
				swapped = true;
			}
		}
		if (swapped == false)
			return;
	}
}
