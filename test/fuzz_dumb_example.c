#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "../include/dumb_example.h"

#define SZ 10000

char buf[SZ];

int main(void)
{
    char *ptr;
    int bytes_read;
    bytes_read = read(0, buf, SZ-1);
    if (bytes_read <= 0) {
        return 0;
    }
    ptr = vuln_function(buf, bytes_read + 1);
    printf("Output: %s\n", ptr);
    free(ptr);
    return 0;
}