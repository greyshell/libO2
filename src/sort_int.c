/*
 * author: greyshell
 * description: implementation of sorting algorithms
 * */

#include <stdio.h>
#include <stdlib.h>
#include <z3.h>
#include "../include/sort_int.h"

/*
 * =========================================================================
 *                          HELPER FUNCTIONS
 * =========================================================================
 */
static void _swap(int *a, int *b) {
    /*
     * time complexity: O(1) | space complexity: O(1)
     */
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

static int _find_max(int *arr, int n) {
    /*
     * time complexity: O(1) | space complexity: O(1)
     */
    int max = *(arr + 0);  // pointer notation 
    for (int i = 1; i < n; i++) {
        if (*(arr + i) > max) {
            max = *(arr + i);
        }
    }
    return max;
}

static int _find_min(int *arr, int n) {
    /*
     * time complexity: O(1) | space complexity: O(1)
     */
    int min = arr[0];  // array notation
    for (int i = 1; i < n; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    return min;
}

void display_array(int *arr, size_t n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

/*
 * =========================================================================
 *                          BUBBLE SORT
 * =========================================================================
 */

void bubble_sort(int *arr, size_t n) {
    /*
     * property:
     * =========
     * - compare adjacent elements and place the small element at the left.
     * - after 1st pass of the outer loop, the smallest element bubbles up at the 0th index.
     * - every passes of outer loop, builds up a small sorted array of small elements
     * from left to right.
     * - at any point of time if the program crashes then also we can get a sorted sub-array
     * where all elements are placed in their actual positions.
     * - in order to find kth smallest element, we need kth pass of the outer loop -> O(k*n)
     * - effective on array data_arr structure not linked list
     * - used for internal sorting: uses the main memory exclusively
     * - stable: preserves the relative order of the duplicate items / keys,
     *      - interchange only occurs when the right_element < left_element
     *      - due to that, for duplicate keys, interchange does not happen
     * - where cost (in terms of time complexity) of moving data_arr / swaps dominates
     * the cost of making comparisons
     * there bubble sort is not a good choice.
     * - cocktail sort is a variation of bubble sort. minor performance improvement through
     * bi-directional sort,
     * means bubbling up the smallest and the largest element in single pass.
     * although the all time complexities are same, but insertion sort takes less swaps
     * comparing to bubble sort.
     * - bubble is not use anywhere in real life.
     *
     *  time complexity:
     *  ================
     *  - worst case / tight upper bound: when the input array is reversely sorted -> o(n^2)
     *      - 1st pass -> n comparisons and at most n swaps
     *      - 2nd pass -> n - 1 comparisons and at most n - 1 swaps
     *      - total comparisons =  n + (n -1) + (n-2) + .. 1 -> n*(n-1)/2 -> n^2
     *      - total swaps = n^2
     *  - best case / tight lower bound: when the input array is already sorted -> Ω(n)
     *      - total comparisons = (n-1)
     *      - total swaps = 0
     *      - adaptive: algorithm takes the advantage of 'existing order of input' to
     *      reduce the running time.
     *  - average case: considering the random distribution of elements -> o(n^2)
     *      - total comparisons = n^2
     *      - total swaps = n^2
     *  - not an optimal algorithm as best and worst case time complexities are different
     *
     * space complexity:
     * =================
     *  - in-place / in-memory sorting: no auxiliary space is required
     *  - non recursive: call stack max depth -> none
     *  - takes constant time -> Θ(1): best and worst case space complexities are same.
     */
    int i, j;
    bool is_swapped;

    if (arr == NULL) {
        return;
    }

    for (i = 0; i < n; i++) {
        is_swapped = false;
        // after the 1st pass of the outer loop, the smallest element bubbles up in the 0th index
        // inner loop is used to compare the adjacent elements
        for (j = n - 1; j > i; j--) {
            // if the right element is smaller than the left element then perform _swap_heap_nodes
            if (arr[j] < arr[j - 1]) {
                _swap(&arr[j], &arr[j - 1]);
                is_swapped = true;
            }
        }
        // improvement: if the array is sorted then we don't need to perform another iteration
        if (is_swapped == false) {
            // no _swap_heap_nodes occurs inside the inner loop which means now the array is sorted
            break;
        }
    }
}

/*
 * =========================================================================
 *                          COCKTAIL SORT
 * =========================================================================
 */

void cocktail_sort(int *arr, size_t n) {
    /*
     * property:
     * =========
     * - bidirectional bubble sort / cocktail shaker sort / shuttle sort
     * - the algorithm extends the bubble sort by operating in two directions.
     * - time and space complexity is same as bubble sort
     * - it is just a minor performance improvement => cocktail sort < 2 * bubble sort
     */
    int is_swapped;
    int left_index = 0;
    int right_index = n - 1;

    if (arr == NULL) {
        return;
    }

    while (1) {
        is_swapped = 0;
        // objective: push the smaller element to the left most
        for (int i = right_index; i > left_index; i--) {
            // if the right element is smaller than the left element then perform _swap_heap_nodes
            if (arr[i] < arr[i - 1]) {
                _swap(&arr[i], &arr[i - 1]);
                is_swapped = 1;
            }
        }
        // improvement: if the array is sorted then we don't need to perform another iteration
        if (is_swapped == 0) {
            // no _swap_heap_nodes occurs inside the inner loop which means now the array is sorted
            break;
        }
        // resent the is_swapped flag
        is_swapped = 0;
        // left index has already the min value so increment the pointer
        left_index++;
        // objective: push the highest element to the right most
        for (int i = left_index; i < right_index; i++) {
            if (arr[i] > arr[i + 1]) {
                _swap(&arr[i], &arr[i + 1]);
                is_swapped = 1;
            }
        }

        if (is_swapped == 0) {
            // no _swap_heap_nodes occurs inside the inner loop which means now the array is sorted
            break;
        }

        right_index--;
    }
}

/*
 * =========================================================================
 *                          COUNTING SORT
 * =========================================================================
 */

void counting_sort(int *arr, int *output_arr, size_t n) {
    /*
     * property:
     * =========
     * - takes the advantage of special properties of keys
     * - perform the sorting by key indexing / using keys as indices
     * - another name: key-indexed counting sort
     * - present implementation supports the negative integers and use the dynamic array to build
     * the auxiliary array
     * - stable sorting algorithm, preserves the relative ordering of keys.
     * - this is not in-place sorting algorithm. however, an another variant uses
     * in-place sort to avoid the auxiliary array in the cost of compromising the stability factor.
     *
     * time complexity:
     * ================
     * - O(n) -> provided the range of the distinct key values is within a constant
     * factor of the file / input size.
     *
     * space complexity:
     * =================
     * - a auxiliary array -> O(k) and the output array -> O(n) is required
     *
     */
    int max = _find_max(arr, n); // O(n)
    int min = _find_min(arr, n); // O(n)
    size_t range = max - min + 1;

    if (arr == NULL || output_arr == NULL) {
        return;
    }

    // dynamically generates the auxiliary array using calloc(), default value is set to 0
    int *auxiliary_array = (int *) calloc(range, sizeof(int));

    // pick each key from the array and go to particular index of auxiliary array and track the total count_singly_linked_list
    for (int i = 0; i < n; i++) {
        auxiliary_array[arr[i] - min]++;
    }

    // prepare the cumulative sum
    for (int i = 1; i <= range; i++) {
        auxiliary_array[i] = auxiliary_array[i] + auxiliary_array[i - 1];
    }

    // calculate each key's last index
    for (int i = 0; i <= range; i++) {
        auxiliary_array[i] = auxiliary_array[i] - 1;
    }

    // start from picking up the last element
    // then place that element into it's last index of the output array
    for (int i = n - 1; i >= 0; i--) {
        output_arr[auxiliary_array[arr[i] - min]] = arr[i];
        auxiliary_array[arr[i] - min]--;
    }
}

/*
 * =========================================================================
 *                          QUICK SORT
 * =========================================================================
 */

static size_t _partition(int *arr, int left_index, int right_index) {
    /*
     * what is a pivot: an item that we want to find its home / final position in the partitioned
     * space / sorted array.
     * it can be any item but the we consider best pivot is the median of the array.
     * a bad pivot is a largest / smallest item of the partitioning space.
     *
     * partition() function splits the array in two halves:
     * items_less_than_pivot | pivot | items_greater_than_pivot
     * partition() return the final index of the pivot element.
     * so whenever the partition() is called, it sorts one element and that is the pivot element
     * */

    // select the last element as pivot
    int pivot = arr[right_index];
    // i variable will keep track of the "tail" of the section of items less than the pivot so that
    // at the end we can "sandwich" the pivot between the section less than it and
    // the section greater than it
    int i = left_index - 1;

    // scan from the left boundary to item before the right boundary or the pivot element
    int j;

    for (j = left_index; j < right_index; j++) {
        // if this item is less than the pivot then it needs to be moved to the section of items less than the pivot
        if (arr[j] <= pivot) {
            // move i forward so that we can swap the value at j into the tail of the items less than the pivot
            i++;
            _swap(&arr[i], &arr[j]);
        }
    }
    // after loop iteration, i points to the last the swapped element that is less than the pivot
    // at this point, (i + 1) -> element is greater than the pivot
    // swap the pivot / the last element with the (i + 1) so that it creates the desired partition
    // items less than pivot | pivot | items greater than pivot
    _swap(&arr[i + 1], &arr[right_index]);
    // return the pivot's actual position in the sorted array
    return i + 1;
}

static void _quick_sort_core_recursive_engine(int *arr, size_t left_index, size_t right_index) {
    /*
     * property:
     * =========
     * - divide rule: split the array in left and right halves based on the index of the pivot
     * element returned by the partition() function. pivots always gets it's final resting position.
     * - conquer rule: sort the left and right half of the array through recursion.
     * - in-place sorting
     * - it is not a stable sort
     *
     *
     * time complexity:
     * ================
     * best case scenario:
     *  - pivot element is chosen is such a way that splits the array into
     *  two equal halves every time.
     *  - O(n*log(n))
     *
     *  worst case scenario:
     *  - O(n**2), if every time the pivot is chosen is such a way that splits
     *  the array in 1:n-1 or n-1:1 ratio.
     *  when the array is sorted / reversely sorted.
     *
     *  average / expected case scenario:
     *  - O(n*log(n)) for randomized version, where the pivot element is selected randomly.
     *
     * space complexity:
     * =================
     * worst case scenario:
     * - O(1), in-memory sorting, no extra space is required.
     * */
    size_t pivot_final_resting_position;

    // this if block will not execute when the array is empty or 1 element
    // due to recursive call,
    if (left_index < right_index) {
        // case 1: when array has more than 1 element
        // partition the array into 2 halves
        // partition() function returns the actual home of the selected pivot in the sorted array
        pivot_final_resting_position = _partition(arr, left_index, right_index);

        if (pivot_final_resting_position > 0) {
            _quick_sort_core_recursive_engine(arr, left_index, pivot_final_resting_position - 1);
        }

        _quick_sort_core_recursive_engine(arr, pivot_final_resting_position + 1, right_index);
    }
}

void quick_sort(int *arr, size_t n) {
    _quick_sort_core_recursive_engine(arr, 0, n - 1);
}