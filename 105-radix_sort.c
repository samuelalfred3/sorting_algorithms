#include "sort.h"

/**
 * radix_sort - Sort an array of integers using the Radix Sort algorithm.
 * @array: The array to be sorted.
 * @size: The size of the array.
 *
 * Description: This function sorts the array in ascending order using the
 * Radix Sort algorithm and prints the array after each significant digit
 * iteration.
 */
void radix_sort(int *array, size_t size)
{
	int i, j, x, y, cantRep, max, div = 1, t = 0;
	int buckets[10][1000];

	if (!array || size < 2)
		return;

	max = array[0];
	for (i = 1; i < (int)size; i++)
		if (array[i] > max)
			max = array[i];

	for (i = 0; i < 10; ++i)
		for (j = 0; j < 1000; ++j)
			buckets[i][j] = -1;

	cantRep = getCantRep(max);
	for (i = 0; i < cantRep; ++i)
	{
		for (j = 0; j < (int)size; ++j)
		{
			for (y = 0; buckets[(array[j] / div) % 10][y] != -1; y++)
				;
			buckets[(array[j] / div) % 10][y] = array[j];
		}
		div = div * 10;
		t = 0;

		for (x = 0; x < 10; ++x)
		{
			for (y = 0; buckets[x][y] != -1; y++)
			{
				array[t] = buckets[x][y];
				buckets[x][y] = -1;
				t++;
			}
		}
		print_array(array, size);
	}
}

/**
 * getCantRep - Count the number of digits in a given number.
 * @num: The number to count the digits of.
 * Return: The count of digits.
 */
int getCantRep(int num)
{
	bool flag = true;
	int cont = 0;

	while (flag)
	{
		flag = false;

		if (num > 0)
		{
			num = num / 10;
			cont++;
			flag = true;
		}
	}
	return (cont);
}
