/*
 * author: greyshell
 * description: unittest case
 * */

#include <string.h>
#include "../../lib/Unity/src/unity.h"
#include "../../include/sort_int.h"

# define ARRAY_SIZE 10


int exp_arr[ARRAY_SIZE] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
size_t num_elements = ARRAY_SIZE;

int arr[ARRAY_SIZE] = {5, 3, 7, 1, 6, 2, 8, 10, 9, 4};
int temp_arr[ARRAY_SIZE];

void array_copy(int *dest, int *src, size_t n) {
    for (int i = 0; i < n; i++) {
        dest[i] = src[i];
    }
}

void setUp(void) {
    // initialize the array
    array_copy(temp_arr, arr, num_elements);
}

void tearDown(void) {
    // clear the array
    for (int i = 0; i < ARRAY_SIZE; i++) {
        temp_arr[i] = 0;
    }
}

void test_bubble_sort(void) {
    bubble_sort(temp_arr, num_elements);
    TEST_ASSERT_EQUAL_INT_ARRAY(exp_arr, temp_arr, num_elements);
}

void test_cocktail_sort(void) {
    cocktail_sort(temp_arr, num_elements);
    TEST_ASSERT_EQUAL_INT_ARRAY(exp_arr, temp_arr, num_elements);
}

void test_counting_sort(void) {
    int out_arr[ARRAY_SIZE] = {0};
    counting_sort(temp_arr, out_arr, num_elements);
    TEST_ASSERT_EQUAL_INT_ARRAY(exp_arr, out_arr, num_elements);
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_bubble_sort);
    RUN_TEST(test_cocktail_sort);
    RUN_TEST(test_counting_sort);

    return UNITY_END();
}