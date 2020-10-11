#include "dumb_example.h"

#include <string.h>

char *vuln_function(char *buf, size_t sz) {
    char stack_buf[20] = {0};
    if (sz < 1) {
        return NULL;
    }
    if (buf[0] == 'H') {
        strcpy(stack_buf, buf);
    }
    return strdup(stack_buf);
}