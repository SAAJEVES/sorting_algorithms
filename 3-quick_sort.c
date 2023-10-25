#include "sort.h"


/**
 * swap_ints - Swap two integers in an array.
 *
 * @x: The first integer to swap.
 *
 * @y: The second integer to swap.
 *
 * Return: nothing
 */
void swap_ints(int *x, int *y)
{
	int tmp;

	tmp = *x;
	*x = *y;
	*y = tmp;
}

/**
 * lomuto_partition - implementation of lomuto_partition
 *
 * @array: array to implemrnt lomuto_partition
 *
 * @size: number of elements present
 *
 * @start: starting index of subset
 *
 * @end: ending index of subset
 *
 * Return: final partition index
 */
int lomuto_partition(int *array, size_t size, int start, int end)
{
	int *pivot, top, bottom;

	pivot = array + end;
	for (top = bottom = start; bottom < end; bottom++)
	{
		if (array[bottom] < *pivot)
		{
			if (top < bottom)
			{
				swap_ints(array + bottom, array + top);
				print_array(array, size);
			}
			top++;
		}
	}

	if (array[top] > *pivot)
	{
		swap_ints(array + top, pivot);
		print_array(array, size);
	}

	return (top);
}

/**
 * lomuto_sort - Implement the quicksort algorithm through recursion.
 *
 * @array: An array of integers to sort.
 *
 * @size: The size of the array.
 *
 * @left: The starting index of the array partition to order.
 *
 * @right: The ending index of the array partition to order.
 *
 * Return: nothing
 */
void lomuto_sort(int *array, size_t size, int left, int right)
{
	int part;

	if (right - left > 0)
	{
		part = lomuto_partition(array, size, left, right);
		lomuto_sort(array, size, left, part - 1);
		lomuto_sort(array, size, part + 1, right);
	}
}


/**
 * quick_sort - quick_sort implementation
 *
 * @array: the array to sort
 *
 * @size: number of elements in the array
 *
 * Return: nothing
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lomuto_sort(array, size, 0, size - 1);
}

