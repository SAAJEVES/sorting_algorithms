#include "sort.h"

/**
 * bubble_sort - implementation of bubble sort algorithm
 *
 * @array: the array to bubble sort
 *
 * @size: number of elements in the array
 *
 * Return: nothing
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int temp;
	bool swapped;

	if (size < 2)
	{
		return;
	}
	else
	{
		for (i = 0; i < (size - 1); i++)
		{
			swapped = false;
			for (j = 0; j < (size - i - 1); j++)
			{
				temp = array[j];
				if (array[j] > array[j + 1])
				{
					array[j] = array[j + 1];
					array[j + 1] = temp;
					swapped = true;
				}
			}
			print_array(array, size);
			if (!swapped)
				break;
		}
	}
}
