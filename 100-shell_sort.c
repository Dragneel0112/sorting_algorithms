#include "sort.h"

/**
 * shell_sort - Sorts an array of integers using shell sort algorithm
 * @array: Array of integers
 * @size: Size of array
 */
void shell_sort(int *array, size_t size)
{
	size_t gap, ref;
	int aux, idx;

	if (array == NULL || size < 2)
	{
		return;
	}
	gap = 1;
	while (gap < size / 3)
	{
		gap = gap * 3 + 1;
	}
	while (gap > 0)
	{
		ref = gap;
		while (ref < size)
		{
			idx = (int)ref - (int)gap;
			while (idx >= 0)
			{
				if (array[ref] < array[idx])
				{
					aux = array[ref];
					array[ref] = array[idx];
					array[idx] = aux;
					ref = ref - gap;
				}
				idx = idx - (int)gap;
			}
			ref = ref + 1;
		}
		gap = (gap - 1) / 3;
		print_array(array, size);
	}
}
