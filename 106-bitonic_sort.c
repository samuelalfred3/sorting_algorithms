#include "sort.h"

/**
 * swap - Swaps two elements in an array and prints the array
 * @array: The array to be sorted
 * @i: Index of the first element
 * @j: Index of the second element
 * @dir: 1 for ascending order, 0 for descending order
 * @size: Number of elements in @array
 */
void swap(int *array, int i, int j, int dir, size_t size)
{
	if ((array[i] > array[j] && dir == 1) || (array[i] < array[j] && dir == 0))
	{
		int temp = array[i];

		array[i] = array[j];
		array[j] = temp;
		print_array(array, size);
	}
}
/**
 * bitonic_merge - Merges two halves of an array in specified order
 * @array: The array to be sorted
 * @low: Starting index of the first half
 * @count: Number of elements in the half
 * @dir: 1 for ascending order, 0 for descending order
 * @size: Number of elements in @array
 */
void bitonic_merge(int *array, int low, int count, int dir, size_t size)
{
	if (count > 1)
	{
		int k = count / 2;
		int i;

		for (i = low; i < low + k; i++)
		{
			swap(array, i, i + k, dir, size);
		}

		bitonic_merge(array, low, k, dir, size);
		bitonic_merge(array, low + k, k, dir, size);
	}
}

/**
 * bitonic_sort_recursive - Recursively sorts the bitonic sequence
 * @array: The array to be sorted
 * @low: Starting index of the sequence
 * @count: Number of elements in the sequence
 * @dir: 1 for ascending order, 0 for descending order
 * @size: Number of elements in @array
 */
void bitonic_sort_recursive(int *array, int low, int count, int dir, size_t size)
{
	if (count > 1)
	{
		int k = count / 2;

		bitonic_sort_recursive(array, low, k, 1, size);
		bitonic_sort_recursive(array, low + k, k, 0, size);
		bitonic_merge(array, low, count, dir, size);
	}
}

/**
 * bitonic_sort - Sorts an array of integers in ascending order using
 * the Bitonic sort algorithm.
 * @array: The array to be sorted.
 * @size: Number of elements in the array.
 *
 * Description: This function assumes that size is a power of 2.
 * It prints the array each time two elements are swapped.
 */
void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	bitonic_sort_recursive(array, 0, size, 1, size);
}
