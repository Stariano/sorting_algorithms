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
        size_t itr_min, itr;


        if (array == NULL || size < 2)
                return;

        for (itr_min = 0; itr_min < size; itr_min++)
        {
                for (itr = itr_min + 1; itr < size; itr++)
                {
                        if (array[itr_min] > array[itr])
                        {
                                temp = array[itr_min];
                                array[itr_min] = array[itr];
                                array[itr] = temp;
                        }
                }
                print_array(array, size);
	}
}
