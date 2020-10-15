#!/bin/bash

# author: greyshell
# description: install the afl fuzzer

wget https://lcamtuf.coredump.cx/afl/releases/afl-latest.tgz && tar xvf afl-latest.tgz
# shellcheck disable=SC2164
cd afl*/ && make && sudo make install
echo "core" | sudo tee /proc/sys/kernel/core_pattern