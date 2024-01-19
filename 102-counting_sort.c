#include "sort.h"

/**
 * counting_sort - Sorts an array of integers in ascending order using
 * the Counting sort algorithm
 * @array: The array to be sorted
 * @size: Size of the array
 */
void counting_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	int max = array[0];

	for (size_t i = 1; i < size; ++i)
	{
		if (array[i] > max)
			max = array[i];
	}

	int *counting_array = malloc(sizeof(int) * (max + 1));

	if (counting_array == NULL)
		return;

	for (int i = 0; i <= max; ++i)
		counting_array[i] = 0;

	for (size_t i = 0; i < size; ++i)
		counting_array[array[i]]++;

	size_t index = 0;

	for (int i = 0; i <= max; ++i)
	{
		while (counting_array[i] > 0)
		{
			array[index++] = i;
			counting_array[i]--;
		}
	}
	print_array(counting_array, max + 1);

	free(counting_array);
}
