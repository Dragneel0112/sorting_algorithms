#include "sort.h"

/**
 * swap - Swap values in an array
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
 * partition - Sorts an array based on a pivot on the last position
 * @arr: Array of integers to sort
 * @low: First index of the array to sort
 * @high: Last index of the array to sort
 * @size: Size of the array
 *
 * Return: int, Index of the pivot sorted
 */
int partition(int arr[], int low, int high, size_t size)
{
	int pivot = arr[high];
	int i = (low - 1), j;

	for (j = low; j <= high - 1; j++)
	{
		if (arr[j] < pivot)
		{
			i++;
			if (arr[i] != arr[j])
			{
				swap(&arr[i], &arr[j]);
				print_array(arr, size);
			}
		}
	}
	if (arr[i + 1] != arr[high])
	{
		swap(&arr[i + 1], &arr[high]);
		print_array(arr, size);
	}
	return (i + 1);
}
/**
 * quickSort - Sorts an array of int using recursive quicksort
 * @arr: Array of integers to sort
 * @low: First index of the array to sort
 * @high: Last index of the array to sort
 * @size: Size of the array
 */
void quickSort(int arr[], int low, int high, size_t size)
{
	int pivot_index;

	if (low < high)
	{
		pivot_index = partition(arr, low, high, size);
		quickSort(arr, low, pivot_index - 1, size);
		quickSort(arr, pivot_index + 1, high, size);
	}
}
/**
 * quick_sort - Sorts an array of integers using quick sort algorithm
 * @array: Array of integers
 * @size: Size of array
 */
void quick_sort(int *array, size_t size)
{
	if (array != NULL)
	{
		quickSort(array, 0, size - 1, size);
	}
}
