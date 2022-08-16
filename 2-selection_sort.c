#include <stdio.h>
#include "sort.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, swap, position;

	for(i = 0; i < size - 1; i++)
	{
		position = i;
		for(j = i + 1; j < size; j++)
		{
			if(array[position] > array[j])
			position = j;
		}
		swap = array[i];
		array[i] = array[position];
		array[position] = swap;
		print_array(array, size);
	}
}
