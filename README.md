# libO2

[![Build Status](https://travis-ci.org/greyshell/libO2.svg?branch=main)](https://travis-ci.org/greyshell/libO2)
[![License: GPL v3](https://img.shields.io/badge/License-GPLv3-blue.svg)](https://www.gnu.org/licenses/gpl-3.0)

A library of common data structures written in C.

### How to install
```
mkdir build && cd build
cmake ..
make install
ldconfig
```

### How to use
```
cd sample/
gcc -Wall -o demo_stack_singly_linkedlist_int demo_stack_singly_linkedlist_int.c -lO2
./demo_stack_singly_linkedlist_int
```