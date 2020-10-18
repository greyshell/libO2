#!/bin/bash

# author: greyshell
# description: handle the fuzz status

NO_CRASHES_FLAG=$(find test/debug/${TEST_LIB}/fuzz/ -iname "id*" | grep ".*/crashes/*" | wc -l)
exit $NO_CRASHES_FLAG