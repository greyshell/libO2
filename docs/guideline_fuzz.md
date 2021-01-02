# How to fuzz

You can `fuzz` the library using `afl` fuzzer.

- Install the `afl` fuzzer.
```
wget https://lcamtuf.coredump.cx/afl/releases/afl-latest.tgz && tar xvf afl-latest.tgz
cd afl*/ && make && sudo make install
echo "core" | sudo tee /proc/sys/kernel/core_pattern
```
- Write the `test` code inside `test/test_src` directory to fuzz all functions of a specific
 library.
    - Make sure the `filename` starts with `fuzz_` followed by the `library` name.
    - For example, `fuzz_stack_singly_linkedlist_int.c`.
- Start the fuzzer. You can control the fuzzing time using `FUZZ_TIME` variable.
```
cd test/
make fuzz TEST_LIB=stack_singly_linkedlist_int FUZZ_TIME=20m    
```
- It creates `test/test_build/<lib_name>/fuzz/` directory and saves all fuzz related artifacts
 over there.
 
## How to reproduce the crash
 
- `afl` writes all crashes inside `out/crashes/` directory. 
- Execute the fuzz binary with the test data.
- For example
```
cd test/test_build/stack_using_singly_linkedlist/fuzz/
./fuzz_stack_using_singly_linkedlist < out/crashes/id:000000,sig:06,src:000000,op:havoc,rep:64
```