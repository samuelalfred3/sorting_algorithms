#ifndef SORT_H
#define SORT_H

#include <stdlib.h>
#include <stddef.h>
#include <stdbool.h>
#include <stdio.h>

/* Comparison direction macros for bitonic sort */
#define UP 0
#define DOWN 1

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

void print_list(const listint_t *list);
void print_array(const int *array, size_t size);
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
void shell_sort(int *array, size_t size);
void cocktail_sort_list(listint_t **list);
void counting_sort(int *array, size_t size);
int get_max(int *array, int size);
void merge_sort(int *array, size_t size);
void merge_subarray(int *subarray, int *buffer, size_t start, size_t mid, size_t end);
void merge_sort_recursive(int *subarray, int *buffer, size_t start, size_t end);
void bitonic_sort(int *array, size_t size);
void quick_sort_hoare(int *array, size_t size);
void quicksort_hoare(int *array, int low, int high);
int hoare_partition(int *array, int low, int high);
void radix_sort(int *array, size_t size);
int getCantRep(int num);
void swap(int *array, int i, int j, int dir, size_t size);
void bitonic_merge(int *array, int low, int count, int dir, size_t size);
void bitonic_sort_recursive(int *array, int low, int count, int dir, size_t size);
size_t lomuto_partition(int *array, ssize_t low, ssize_t high, size_t size);
void quicksort(int *array, ssize_t low, ssize_t high, size_t size);
void swap_nodes(listint_t **list, listint_t *a, listint_t *b);
void heap_sort(int *array, size_t size);
void swap_ints(int *a, int *b);
void max_heapify(int *array, size_t size, size_t base, size_t root);

#endif /* SORT_H */
