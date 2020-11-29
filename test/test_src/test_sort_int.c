/*
 * author: greyshell
 * description: unittest case
 * */

#include <string.h>
#include "../../lib/Unity/src/unity.h"
#include "../../include/sort_int.h"


size_t num_elements = 10;
int exp_arr[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
// sort duplicate numbers
int exp_arr2[10] = {0, 0, 1, 2, 2, 5, 7, 8, 9, 9};

// test array
int test_arr[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
int test_arr2[10] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
int test_arr3[10] = {0, 9, 1, 8, 2, 7, 3, 6, 4, 5};
int test_arr4[10] = {7, 3, 5, 1, 6, 2, 8, 0, 9, 4};
int test_arr5[10] = {7, 0, 5, 1, 9, 2, 8, 0, 9, 2};

// temporary array
int temp_arr[10];
int temp_arr2[10];
int temp_arr3[10];
int temp_arr4[10];
int temp_arr5[10];

// output array
int out_arr[10];


void array_copy(int *dest, int *src) {
    for (int i = 0; i < num_elements; i++) {
        dest[i] = src[i];
    }
}

void out_array_reset(void) {
    for (int i = 0; i < num_elements; i++) {
        out_arr[i] = 0;
    }
}

void temp_array_reset(void) {
    // clear the array
    for (int i = 0; i < num_elements; i++) {
        temp_arr[i] = 0;
        temp_arr2[i] = 0;
        temp_arr3[i] = 0;
        temp_arr4[i] = 0;
        temp_arr5[i] = 0;
        out_arr[i] = 0;
    }
}

void setUp(void) {
    // initialize the array
    array_copy(temp_arr, test_arr);
    array_copy(temp_arr2, test_arr2);
    array_copy(temp_arr3, test_arr3);
    array_copy(temp_arr4, test_arr4);
    array_copy(temp_arr5, test_arr5);
}

void tearDown(void) {
    // clear the array
    temp_array_reset();
}

#define TEST_SORT(func)                                                        \
  void test_##func(void) {                                                     \
    func(temp_arr, num_elements);                                              \
    TEST_ASSERT_EQUAL_INT_ARRAY(exp_arr, temp_arr, num_elements);              \
    func(temp_arr2, num_elements);                                             \
    TEST_ASSERT_EQUAL_INT_ARRAY(exp_arr, temp_arr2, num_elements);             \
    func(temp_arr3, num_elements);                                             \
    TEST_ASSERT_EQUAL_INT_ARRAY(exp_arr, temp_arr3, num_elements);             \
    func(temp_arr4, num_elements);                                             \
    TEST_ASSERT_EQUAL_INT_ARRAY(exp_arr, temp_arr4, num_elements);             \
    func(temp_arr5, num_elements);                                             \
    TEST_ASSERT_EQUAL_INT_ARRAY(exp_arr2, temp_arr5, num_elements);            \
  }

TEST_SORT(bubble_sort);

TEST_SORT(cocktail_sort);

TEST_SORT(quick_sort);

void test_counting_sort(void) {
    counting_sort(temp_arr, out_arr, num_elements);
    TEST_ASSERT_EQUAL_INT_ARRAY(exp_arr, out_arr, num_elements);
    out_array_reset();

    counting_sort(temp_arr2, out_arr, num_elements);
    TEST_ASSERT_EQUAL_INT_ARRAY(exp_arr, out_arr, num_elements);
    out_array_reset();

    counting_sort(temp_arr3, out_arr, num_elements);
    TEST_ASSERT_EQUAL_INT_ARRAY(exp_arr, out_arr, num_elements);
    out_array_reset();

    counting_sort(temp_arr4, out_arr, num_elements);
    TEST_ASSERT_EQUAL_INT_ARRAY(exp_arr, out_arr, num_elements);
    out_array_reset();

    // duplicate numbers
    counting_sort(temp_arr5, out_arr, num_elements);
    TEST_ASSERT_EQUAL_INT_ARRAY(exp_arr2, out_arr, num_elements);
    out_array_reset();
}


int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_bubble_sort);
    RUN_TEST(test_cocktail_sort);
    RUN_TEST(test_quick_sort);

    RUN_TEST(test_counting_sort);

    return UNITY_END();
}