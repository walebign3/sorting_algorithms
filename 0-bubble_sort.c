#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * array - array of unsorted data
 * size - size of array
 *
 * Return: Always 0
 */

void bubble_sort(int *array, size_t size)
{
	size_t i = 0, j = 0, tmp, f;

	for (i = 0; i < size; i++)
	{
		f = 0;
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				tmp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = tmp;
				print_array(array, size);
				f = 1;
			}
		}
		if (f == 0)
			break;
	}
}

