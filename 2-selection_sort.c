#include <stdio.h>
#include "sort.h"

/**
 * selection_sort - selection_sort
 * @array: array
 * @size: number of elements
 *
 * Return: Always 0
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, swap, position;

	for (i = 0; i <= size - 2; i++)
	{
		position = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[position])
				position = j;
		}
		if (position != i)
		{
			swap = array[i];
			array[i] = array[position];
			array[position] = swap;
			print_array(array, size);
		}
	}
}
