#ifndef SORT_H_
#define SORT_H_

#include <stdio.h>

#define N 200
#define elemType int

// active ptr
extern void (*sort_ptr)(elemType arr[], int n);

// global function
void swap(int *a, int *b);
void print_arr(elemType arr[], int n);

// stable sort algo
// bubble
void bubble_sort(elemType arr[], int n);

// insertion
void insertion_sort(elemType arr[], int n);

// merge
void merge_sort(elemType arr[], int n);

// counting
void counting_sort(elemType arr[], int n);

// bucket
void bucket_sort(elemType arr[], int n);

// radix
void radix_sort(elemType arr[], int n);

// unstable sort algo
// selection
void selection_sort(elemType arr[], int n);

// heap
void heap_sort(elemType arr[], int n);

// quick
void quick_sort(elemType arr[], int n);

// shell
void shell_sort(elemType arr[], int n);

#endif // SORT_H_
