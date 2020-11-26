/*
 * author: greyshell
 * */

#ifndef SORT_H__
#define SORT_H__

#include <z3.h>

void display_array(int *arr, size_t n);

void bubble_sort(int *, size_t);

void cocktail_sort(int *, size_t);

void selection_sort(int *, size_t);

void insertion_sort(int *, size_t);

void shell_sort(int *, int);

void quick_sort(int *, int);

void merge_sort(int *, int);

void counting_sort(int *, int *, size_t);

#endif // _SORT_H__
