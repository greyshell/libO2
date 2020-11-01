# Quickstart

[libO2](https://github.com/greyshell/libO2) is a collection of common `data structures` written in `C`

## How to install

- Clone the `git` repository.
```
git clone https://github.com/greyshell/libO2.git
```

- Install the following dependencies:
    - [gcc](https://gcc.gnu.org/) version 9.2.1 or above
    - [cmake](https://cmake.org/) version 3.16.3 or above

- Create the `build` directory.
```
mkdir build/
```

- Navigate to the `build` directory and create the `build environment` via `cmake`.
```
cd build/
cmake ..
```

- Install the library. 
```
make install
```

> Under the hood, it copies `.so` files into `/usr/local/lib/` directory and `.h` files into `/usr
/local/include/` directory.

- Reload / cache newly installed shared libraries.
```
ldconfig
```

## How to use

- Write a sample program like `sample/demo_stack_singly_linkedlist_int.c`
- Compile the code with `gcc`.
```
gcc -Wall -o demo_stack demo_stack_singly_linkedlist_int.c -lO2
```
- Run the binary.
```
./demo_stack
```

## How to uninstall

Removes all `.so` files from `/usr/local/lib/` directory and `.h` files from `/usr
/local/include/` directory.
```
cd script/ 
sudo ./uninstall_lib.sh 
```

