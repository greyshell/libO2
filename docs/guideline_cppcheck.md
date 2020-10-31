## SCA using `cppcheck`

`cppcehck` finds the `security bug` in the source code.

## How to use
- Install `cppcehck`.
```
sudo apt-get install cppcheck less  -y
```
- Run the tool on the source. 
```
cd test/
make cppcheck-report TEST_LIB=queue_singly_linkedlist_int 
```