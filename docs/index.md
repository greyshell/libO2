# Quickstart

[libO2](https://github.com/greyshell/libO2) is a collection of common `data structures` written in `C`

## How to install

- Check if you have the following dependencies:
    - [gcc](https://gcc.gnu.org/) version 9.2.1 or above
    - [cmake](https://cmake.org/) version 3.16.3 or above

- Clone the `git` repository and navigate into the directory.
```
git clone https://github.com/greyshell/libO2.git
cd libO2/
```

- Create the `build` directory and navigate into the directory.
```
mkdir build/ && cd build/
```

- Create the `build environment` via `cmake`.
```
cmake ..
```

- Install the `libO2` library. 
```
sudo make install
```

> Under the hood, it copies `.so` files inside `/usr/local/lib/` directory and `.h` files inside `/usr
/local/include/` directory.

- cache the most recently installed `shared` library.
```
sudo ldconfig
```

## How to use

- Write a sample program like `example_stack.c`
```
/*
 * author: greyshell
 * description: example stack
 * */

#include <stdio.h>
#include "stdbool.h"
#include "stack_singly_linkedlist_int.h"

int main(void) {
    int out_data = 0;
    bool return_type;
    stack s;

    // initialize the stack
    initialize_stack(&s);

    // check if the stack is empty
    return_type = is_empty_stack(&s);
    printf("is empty stack: %d \n", return_type);

    // push an element
    return_type = push(&s, 7);
    if (return_type){
        printf("element pushed \n");
    }
    else {
        printf("pushed failed \n");
    }

    // peek the stack top
    return_type = peek(&s, &out_data);
    if (return_type){
        printf("element peeked: %d \n", out_data);
    }
    else {
        printf("peek failed \n");
    }

    // display stack elements
    printf("stack elements: \n");
    display_stack(&s);
    printf("\n");

    // pop an element
    return_type = pop(&s, &out_data);
    if (return_type){
        printf("element popped: %d \n", out_data);
    }
    else {
        printf("pop failed \n");
    }

    // get the stack size
    return_type = get_stack_size(&s);
    printf("stack size: %d \n", return_type);

    // delete the stack
    delete_stack(&s);

    return 0;
}
```

- Compile the code with `gcc`.
```
gcc -Wall -o example_stack example_stack.c -lO2
```
- Run the binary.
```
./example_stack
```

## How to uninstall

Removes all `.so` files from `/usr/local/lib/` directory and `.h` files from `/usr
/local/include/` directory.
```
cd script/ 
sudo ./uninstall_lib.sh 
```

