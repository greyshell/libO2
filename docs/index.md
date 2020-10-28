# Quickstart

A quick guide for installing and using [libO2](https://github.com/greyshell/libO2).


## Installation

Clone the `git` repository.

    $ git clone https://github.com/greyshell/libO2.git

Install the following dependencies:

- [gcc](https://gcc.gnu.org/) version 9.2.1 or above
- [cmake](https://cmake.org/) version 3.16.3 or above

[Unity](http://www.throwtheswitch.org/unity) is not required to use the library. You will need
 to install it if you wish to run the unittests.

Create the `build` directory under the parent(i.e. `libO2`) directory.

    $ mkdir libO2/build

Navigate into the `build` directory and create the build environment.

    $ cd libO2/build/
    $ cmake ..

Install the library. 

    $ make install

Under the hood, it copies `.so` files into `/usr/local/lib/` directory and `.h` files into `/usr
/local/include/` directory.

Reload / cache the shared libraries.

    $ ldconfig

## Usage

Write a sample program like `sample/demo_stack_singly_linkedlist_int.c`

Compile the code with `gcc`.

    $ gcc -Wall -o demo_stack demo_stack_singly_linkedlist_int.c -lO2

Run the binary.

    $ ./demo_stack
