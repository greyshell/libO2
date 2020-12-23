# How to run unittest

_Author: greyshell_

You can run the `unittest` in your local system.

- Create a directory - `lib/` and install [Unity](http://www.throwtheswitch.org/unity).
```
mkdir lib
git clone https://github.com/ThrowTheSwitch/Unity.git lib/
```
- Write the `unitiest` code inside `test/test_src` directory to test all functions of a specific
 library.
    - Make sure the `filename` starts with `test_` followed by the `library` name.
    - For example, `test_stack_singly_linkedlist_int.c`.
- Run the test.
```
cd test/
make test TEST_LIB=stack_singly_linkedlist_int
```
- It creates `test/test_build/<lib_name>/unittest/` directory and saves all test related
 artifacts over there.

- Clean the test artifacts
```
make clean TEST_LIB=stack_singly_linkedlist_int
```