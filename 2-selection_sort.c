#include "sort.h"

/**
 * swap - Swaps values in array
 * @x: Int to swap
 * @y: Int to swap
 */
void swap(int *x, int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

/**
 * selection_sort - Sorts an array using selection sort
 * @array: Array to be sorted
 * @size: Size of array
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, index;

	for (i = 0; i < size - 1; i++)
	{
		index = i;
		for (j = i + 1; j < size; j++)
			if (array[j] < array[index])
				index = j;

		if (index != i)
		{
			swap(&array[index], &array[i]);
			print_array(array, size);
		}
	}
}
