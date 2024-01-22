#include "sort.h"

/**
 * quick_sort_hoare - Sorts an array of integers in ascending order
 * using the Quick sort algorithm (Hoare partition scheme)
 * @array: The array to be sorted
 * @size: Number of elements in @array
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quicksort_hoare(array, 0, size - 1);
}

/**
 * quicksort_hoare - Recursively sorts a partition of an array
 * using the Quick sort algorithm (Hoare partition scheme)
 * @array: The array to be sorted
 * @low: Starting index of the partition to be sorted
 * @high: Ending index of the partition to be sorted
 */
void quicksort_hoare(int *array, int low, int high)
{
	if (low < high)
	{
		int pivot_index = hoare_partition(array, low, high);

		print_array(array + low, high - low + 1);

		quicksort_hoare(array, low, pivot_index - 1);
		quicksort_hoare(array, pivot_index + 1, high);
	}
}

/**
 * hoare_partition - Partitions the array using the Hoare scheme
 * @array: The array to be partitioned
 * @low: Starting index of the partition
 * @high: Ending index of the partition
 *
 * Return: Index of the pivot after partitioning
 */
int hoare_partition(int *array, int low, int high)
{
	int pivot = array[high];
	int i = low - 1, j = high + 1;

	while (1)
	{
		do {
			i++;
		} while (array[i] < pivot);

		do {
			j--;
		} while (array[j] > pivot);

		if (i >= j)
			return (i);

		if (i != j)
		{
			int temp = array[i];

			array[i] = array[j];
			array[j] = temp;
		}
	}
}
