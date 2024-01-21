#include "sort.h"
/**
 * swap_ints - Swap two integers in an array.
 * @a: Pointer to the first integer.
 * @b: Pointer to the second integer.
 *
 * Description: Swaps the values at two given memory locations.
 */
void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * max_heapify - Maintain the max heap property of a binary tree.
 * @array: Array representing the binary tree.
 * @size: Size of the array/binary tree.
 * @base: Index of the base row of the tree.
 * @root: Index of the root node.
 *
 * Description: Checks and corrects the max heap property for a subtree.
 * If the heap property is violated, it swaps elements and recursively
 * calls itself on the affected subtree.
 */
void max_heapify(int *array, size_t size, size_t base, size_t root)
{
	size_t left, right, large;

	left = 2 * root + 1;
	right = 2 * root + 2;
	large = root;

	if (left < base && array[left] > array[large])
		large = left;
	if (right < base && array[right] > array[large])
		large = right;

	if (large != root)
	{
		swap_ints(array + root, array + large);
		print_array(array, size);
		max_heapify(array, size, base, large);
	}
}

/**
 * heap_sort - Sort an array of integers in ascending order using heap sort.
 * @array: Array of integers to be sorted.
 * @size: Size of the array.
 *
 * Description: Implements the heap sort algorithm, transforming the input
 * array into a max heap and repeatedly extracting the maximum element.
 * Prints the array after each swap.
 */
void heap_sort(int *array, size_t size)
{
	int i;

	if (array == NULL || size < 2)
		return;

	for (i = (size / 2); i > 0; i--)
		max_heapify(array, size, size, i - 1);

	for (i = size - 1; i > 0; i--)
	{
		swap_ints(array, array + i);
		print_array(array, size);
		max_heapify(array, size, i, 0);
	}
}
