/*
 * author: greyshell
 * description: unittest case
 * */

#include <string.h>
#include "../../lib/Unity/src/unity.h"
#include "../../include/binary_heap_dynamic_array_int.h"

# define ARRAY_SIZE 5

// create the data structure
heap h_max;
heap h_min;

void setUp(void) {
    // initialize the data structure
    initialize_heap(&h_max, 1, true);  // max heap
    initialize_heap(&h_min, 1, false);  // min heap
}

void tearDown(void) {
    // delete the data structure
    delete_heap(&h_max);
    delete_heap(&h_min);
}

void test_case01(void){
    int out_data = 0;

    TEST_ASSERT_EQUAL_INT(true, push_heap(&h_max, 40));
    TEST_ASSERT_EQUAL_INT(true, push_heap(&h_max, 90));
    TEST_ASSERT_EQUAL_INT(true, push_heap(&h_max, 10));
    TEST_ASSERT_EQUAL_INT(true, peek_heap(&h_max, &out_data));
    TEST_ASSERT_EQUAL_INT(90, out_data);
}

void test_case02(void){
    size_t heap_size;

    TEST_ASSERT_EQUAL_INT(true, push_heap(&h_max, 40));
    TEST_ASSERT_EQUAL_INT(true, push_heap(&h_max, 90));
    TEST_ASSERT_EQUAL_INT(true, push_heap(&h_max, 10));
    TEST_ASSERT_EQUAL_INT(true, get_heap_size(&h_max, &heap_size));
    TEST_ASSERT_EQUAL_INT(3, heap_size);

}

void test_case03(void){
    TEST_ASSERT_EQUAL_INT(true, is_empty_heap(&h_max));
    TEST_ASSERT_EQUAL_INT(true, push_heap(&h_max, 40));
    TEST_ASSERT_EQUAL_INT(true, push_heap(&h_max, 90));
    TEST_ASSERT_EQUAL_INT(false, is_empty_heap(&h_max));
}

void test_case04(void){
    int out_data = 0;

    TEST_ASSERT_EQUAL_INT(true, push_heap(&h_max, 40));
    TEST_ASSERT_EQUAL_INT(true, push_heap(&h_max, 90));
    TEST_ASSERT_EQUAL_INT(true, push_heap(&h_max, 10));
    TEST_ASSERT_EQUAL_INT(true, pop_heap(&h_max, &out_data));
    TEST_ASSERT_EQUAL_INT(90, out_data);
    TEST_ASSERT_EQUAL_INT(true, pop_heap(&h_max, &out_data));
    TEST_ASSERT_EQUAL_INT(40, out_data);
    TEST_ASSERT_EQUAL_INT(true, pop_heap(&h_max, &out_data));
    TEST_ASSERT_EQUAL_INT(10, out_data);

}

void test_case05(void){
    int out_data = 0;

    TEST_ASSERT_EQUAL_INT(true, push_heap(&h_min, 40));
    TEST_ASSERT_EQUAL_INT(true, push_heap(&h_min, 90));
    TEST_ASSERT_EQUAL_INT(true, push_heap(&h_min, 10));
    TEST_ASSERT_EQUAL_INT(true, peek_heap(&h_min, &out_data));
    TEST_ASSERT_EQUAL_INT(10, out_data);
}

void test_case06(void){
    int out_data = 0;

    TEST_ASSERT_EQUAL_INT(true, push_heap(&h_min, 40));
    TEST_ASSERT_EQUAL_INT(true, push_heap(&h_min, 90));
    TEST_ASSERT_EQUAL_INT(true, push_heap(&h_min, 10));
    TEST_ASSERT_EQUAL_INT(true, pop_heap(&h_min, &out_data));
    TEST_ASSERT_EQUAL_INT(10, out_data);
    TEST_ASSERT_EQUAL_INT(true, pop_heap(&h_min, &out_data));
    TEST_ASSERT_EQUAL_INT(40, out_data);
    TEST_ASSERT_EQUAL_INT(true, pop_heap(&h_min, &out_data));
    TEST_ASSERT_EQUAL_INT(90, out_data);
}

void test_case07(void){
    int test_arr[ARRAY_SIZE] = {5, 2, 1, 3, 4};
    int exp_arr[ARRAY_SIZE] = {1, 2, 3, 4, 5};

    heap_sort(test_arr, 5, true);
    TEST_ASSERT_EQUAL_INT_ARRAY(exp_arr, test_arr, ARRAY_SIZE);
}

void test_case08(void){
    int out_data = 0;
    int test_arr[7] = {10, 20, 30, 40, 150, 70, 160};
    int exp_arr[7] = {160, 150, 70, 40, 20, 10, 30};
    heap h;

    TEST_ASSERT_EQUAL_INT(true, build_heap(&h, true, test_arr, 7));
    TEST_ASSERT_EQUAL_INT_ARRAY(exp_arr, test_arr, 7);

    TEST_ASSERT_EQUAL_INT(true, peek_heap(&h, &out_data));
    TEST_ASSERT_EQUAL_INT(160, out_data);

    TEST_ASSERT_EQUAL_INT(true, pop_heap(&h, &out_data));
    TEST_ASSERT_EQUAL_INT(160, out_data);

    TEST_ASSERT_EQUAL_INT(true, pop_heap(&h, &out_data));
    TEST_ASSERT_EQUAL_INT(true, pop_heap(&h, &out_data));
    TEST_ASSERT_EQUAL_INT(true, pop_heap(&h, &out_data));
    TEST_ASSERT_EQUAL_INT(40, out_data);

    TEST_ASSERT_EQUAL_INT(true, delete_heap(&h));
}

void test_case09(void){
    int out_data = 0;
    size_t heap_size = 0;

    TEST_ASSERT_EQUAL_INT(false, peek_heap(&h_min, &out_data));
    TEST_ASSERT_EQUAL_INT(false, pop_heap(&h_min, &out_data));
    TEST_ASSERT_EQUAL_INT(0, out_data);

    TEST_ASSERT_EQUAL_INT(false, get_heap_size(&h_min, &heap_size));
    TEST_ASSERT_EQUAL_INT(0, heap_size);
}

int main(void){
    UNITY_BEGIN();
    RUN_TEST(test_case01);
    RUN_TEST(test_case02);
    RUN_TEST(test_case03);
    RUN_TEST(test_case04);
    RUN_TEST(test_case05);
    RUN_TEST(test_case06);
    RUN_TEST(test_case07);
    RUN_TEST(test_case08);
    RUN_TEST(test_case09);
    return UNITY_END();
}