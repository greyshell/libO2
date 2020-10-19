#!/bin/bash

# author: greyshell
# description: handle the cppcheck report

FAILED_CASES=$(cat test/debug/${TEST_LIB}/cppcheck_report_${TEST_LIB}.txt | wc -l)
if [ $FAILED_CASES -gt 1 ]
then
  # upload the report to #dev-lib02
  curl -XPOST --data "payload={\"text\": \"> :speaking_head_in_silhouette: CPPCheck :negative_squared_cross_mark: for \`${TEST_LIB}\` lib \n> Report: $(cat test/debug/${TEST_LIB}/cppcheck_report_*.txt | pastebinit -b  https://paste.ubuntu.com)\"}" $SLACK_WEBHOOK_URL
fi
