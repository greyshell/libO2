#!/bin/bash

# author: greyshell
# description: handle the cppcheck report

FAILED_CASES=$(cat test/test_build/${TEST_LIB}/cppcheck_report_${TEST_LIB}.txt | wc -l)
if [ $FAILED_CASES -gt 1 ]
then
  # upload the report to #dev-lib02
  curl -XPOST --data "payload={\"text\": \"> :negative_squared_cross_mark: cppcheck failed for *${TEST_LIB}* \n> Report: $(cat test/test_build/${TEST_LIB}/cppcheck_report_*.txt | pastebinit -b  https://paste.ubuntu.com)\"}" $SLACK_WEBHOOK_URL
fi
