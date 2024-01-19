#include "sort.h"

/**
 * merge - Merges two subarrays of the array.
 * @array: The array to be sorted.
 * @left: Start index of the left subarray.
 * @mid: Middle index.
 * @right: End index of the right subarray.
 */
static void merge(int *array, size_t left, size_t mid, size_t right)
{
	size_t i, j, k;
	size_t n1 = mid - left + 1;
	size_t n2 = right - mid;

	int *leftArray = malloc(sizeof(int) * n1);
	int *rightArray = malloc(sizeof(int) * n2);

	for (i = 0; i < n1; i++)
		leftArray[i] = array[left + i];
	for (j = 0; j < n2; j++)
		rightArray[j] = array[mid + 1 + j];

	i = 0;
	j = 0;
	k = left;
	while (i < n1 && j < n2)
	{
		if (leftArray[i] <= rightArray[j])
		{
			array[k] = leftArray[i];
			i++;
		} else
		{
			array[k] = rightArray[j];
			j++;
		}
		k++;
	}
	while (i < n1)
	{
		array[k] = leftArray[i];
		i++;
		k++;
	}
	while (j < n2)
	{
		array[k] = rightArray[j];
		j++;
		k++;
	}
	free(leftArray);
	free(rightArray);
}

/**
 * merge_sort_recursive - Recursive function to perform merge sort.
 * @array: The array to be sorted.
 * @left: Start index of the array.
 * @right: End index of the array.
 */
static void merge_sort_recursive(int *array, size_t left, size_t right)
{
	if (left < right)
	{
		size_t mid = left + (right - left) / 2;

		merge_sort_recursive(array, left, mid);
		merge_sort_recursive(array, mid + 1, right);
		merge(array, left, mid, right);
	}
}

/**
 * merge_sort - Sorts array of integers in ascending order using Merge sort.
 * @array: The array to be sorted.
 * @size: Number of elements in the array.
 */

void merge_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	merge_sort_recursive(array, 0, size - 1);
}
