#include <string.h>
#include <stdlib.h>
#include "../lib/Unity/src/unity.h"
#include "../include/dumb_example.h"

void setUp(void) {
    // set stuff up here
}

void tearDown(void) {
    // clean stuff up here
}

void test_vuln_function_should_copy_string(void)
{
    char buf[] = "Hello World!";
    char *res = vuln_function(buf, strlen(buf));
    printf("Output: %s\n", res);
    TEST_ASSERT_EQUAL_STRING("KK", res);
    free(res);
}

void test_vuln_function_should_not_copy_string(void)
{
    char buf[] = "";
    char negative[] = "KOOL";
    TEST_ASSERT_EQUAL_STRING(negative, vuln_function(buf, strlen(buf)));
}

int main(void)
{
    UNITY_BEGIN();
    RUN_TEST(test_vuln_function_should_copy_string);
    RUN_TEST(test_vuln_function_should_not_copy_string);
    return UNITY_END();
}