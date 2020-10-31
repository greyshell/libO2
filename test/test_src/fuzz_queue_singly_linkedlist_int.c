/*
 * author: greyshell
 * description: fuzz the stack api through AFL
 * */

#include <stdio.h>
#include "stdbool.h"
#include <stdint.h>
#include <unistd.h>
#include <string.h>
#include "../../include/queue_singly_linkedlist_int.h"

/*
 * =======================================================
 * Helper functions for fuzzing
 * =======================================================
 */
void readn(void *s, int n) {
    int bytes_read;
    bytes_read = read(0, s, n);
    if (bytes_read == n) {
        return;
    }
    if (bytes_read == 0 || bytes_read == -1) {
        memset(s, 0, n);
        return;
    }
    memset(&((char *) s)[bytes_read], 0, n - bytes_read);
}

uint8_t read8() {
    uint8_t i;
    readn(&i, sizeof(i));
    return i;
}

int read_int() {
    int i;
    readn(&i, sizeof(i));
    return i;
}

size_t read_size_t() {
    size_t i;
    readn(&i, sizeof(i));
    return i;
}

void my_display(void *data) {
    /*
     * display elements: datatype -> int
     */
    printf("%d ", *(int *) data);
    fflush(stdout);
}

bool my_compare(void *data, void *key) {
    /*
     * data format: int
     */
    if (*(int *) data == *(int *) key) {
        return true;
    }
    return false;
}

/*
 * =========== End of the Helper Functions ================
 */

int main(void) {
    int data, out_data = 0;
    size_t choice, stack_size;
    bool return_type;
    queue q;
    uint8_t number_operations;
    uint8_t operation_type;

    // nos of functions / operations to test
    size_t ops_count = 5;
    ops_count = ops_count + 1;  // as the case starts from 0
    // initialize
    initialize_queue(&q);

    // randomize the nos of operations and get the input through fuzzer
    number_operations = read8();
    printf("number of operations: %d \n", number_operations);

    for (int i = 0; i < number_operations; i++) {
        // choose the random operation
        operation_type = read8();
        switch (operation_type % ops_count) {
            case 0:
                data = read_int();
                printf("operation: enqueue, data: %d \n", data);
                return_type = enqueue(&q, data);
                if (return_type == true) {
                    printf("enqueued \n");
                } else {
                    printf("unable to enqueue \n");
                }
                break;
            case 1:
                printf("operation: dequeue \n");
                return_type = dequeue(&q, &out_data);
                if (return_type == true) {
                    printf("dequeued %d \n", out_data);
                } else {
                    printf("unable to dequeue \n");
                }
                break;
            case 2:
                printf("operation: peek at front \n");
                return_type = peek_at_front(&q, &out_data);
                if (return_type == true) {
                    printf("peek at front: %d \n", out_data);
                } else {
                    printf("unable to peek at front \n");
                }
                break;
            case 3:
                printf("operation: peek at rear \n");
                return_type = peek_at_rear(&q, &out_data);
                if (return_type == true) {
                    printf("peek at rear: %d \n", out_data);
                } else {
                    printf("unable to peek at rear \n");
                }
                break;
            case 4:
                printf("operation: get_stack_size \n");
                stack_size = get_queue_size(&q);
                printf("queue size: %zu \n", stack_size);
                break;
            case 5:
                printf("operation: is_empty_queue \n");
                return_type = is_empty_queue(&q);
                printf("is empty: %d \n", return_type);
                break;
            default:
                printf("wrong choice \n");

        }
    }
    // delete the ADT
    delete_queue(&q);
    return 0;
}