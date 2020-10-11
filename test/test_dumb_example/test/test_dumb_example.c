#include "../../lib/Unity/src/unity.h"
#include "../../src/dumb_example.h"

#include <string.h>
#include <stdlib.h>

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
    TEST_ASSERT_EQUAL_STRING(buf, res);
    free(res);
}

void test_vuln_function_should_not_copy_string(void)
{
    char buf[] = "";
    TEST_ASSERT_EQUAL_STRING(NULL, vuln_function(buf, strlen(buf)));
}

int main(void)
{
    UNITY_BEGIN();
    RUN_TEST(test_vuln_function_should_copy_string);
    RUN_TEST(test_vuln_function_should_not_copy_string);
    return UNITY_END();
}