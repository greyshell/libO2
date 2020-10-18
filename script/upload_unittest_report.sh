#!/bin/bash

# author: greyshell
# description: handle the unittest status

FAILED_CASES=$(grep -w "FAIL:" test/debug/${TEST_LIB}/unittest_build/results/test_${TEST_LIB}.txt | wc -l)
if [ $FAILED_CASES -gt 0 ]
then
  # upload the report to #dev-lib02
  curl -XPOST --data "payload={\"text\": \"> *Unittest* report for \`${TEST_LIB}\`: \
   $(cat test/debug/${TEST_LIB}/unittest_build/results/test_${TEST_LIB}.txt | pastebinit -b  https://paste.ubuntu.com)\"}" $SLACK_WEBHOOK_URL
  exit $FAILED_CASES
fi
exit $FAILED_CASES