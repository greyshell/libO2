#include <string.h>
#include <stdlib.h>
#include "../lib/Unity/src/unity.h"
#include "../include/stack_singly_linkedlist_int.h"

void setUp(void) {
    // set stuff up here
}

void tearDown(void) {
    // clean stuff up here
}

void test_push(void)
{
    stack s;
    int data = 10;
    int out_data = 0;
    bool return_type;
    initialize_stack(&s);
    return_type = push(&s, data);
    TEST_ASSERT_EQUAL_INT(true, return_type);

    return_type = peek(&s, &out_data);
    TEST_ASSERT_EQUAL_INT(data, out_data);
    delete_stack(&s);

}


int main(void)
{
    UNITY_BEGIN();
    RUN_TEST(test_push);
    return UNITY_END();
}