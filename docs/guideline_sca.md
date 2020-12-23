# Static code analysis

_Author: greyshell_

## CPPCheck

Scan the code with `cppcehck` to find the `security` bugs.

### How to use
- Install `cppcehck`.
```
sudo apt-get install cppcheck less  -y
```
- Run the tool on the source. 
```
cd test/
make cppcheck-report TEST_LIB=queue_singly_linkedlist_int 
```