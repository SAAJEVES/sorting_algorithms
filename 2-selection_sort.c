#include "sort.h"

/**
 * selection_sort - implementation of selection sort
 *
 * @array: array
 *
 * @size: number of element
 *
 * Return: void
 */
void selection_sort(int *array, size_t size)
{
	int *low;
	int temp;
	size_t i, j;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		low = array + i;
		for (j = i + 1; j < size; j++)
			low = (array[j] < *low) ? (array + j) : low;
		if ((array + i) != low)
		{
			temp = array[i];
			array[i] = *low;
			*low = temp;
			print_array(array, size);
		}
	}
}

