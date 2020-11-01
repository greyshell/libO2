#!/bin/bash

# author: greyshell
# description: handle the unittest report, if FAILs then skip the fuzz test

FAILED_CASES=$(grep -w "FAIL:" test/test_build/${TEST_LIB}/unittest/results/test_${TEST_LIB}
.txt | wc -l)
if [ $FAILED_CASES -gt 0 ]
then
  # upload the report to #dev-lib02
  curl -XPOST --data "payload={\"text\": \"> :no_entry_sign: Unittest failed for *${TEST_LIB}* \n> Report: $(cat test/test_build/${TEST_LIB}/unittest/results/test_${TEST_LIB}.txt | pastebinit -b https://paste.ubuntu.com) \"}" $SLACK_WEBHOOK_URL
  exit $FAILED_CASES
fi
exit $FAILED_CASES
