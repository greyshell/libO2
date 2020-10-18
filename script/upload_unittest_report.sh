#!/bin/bash

# author: greyshell
# description: handle the unittest status

FAILED_CASES=$(make test TEST_LIB=${TEST_LIB} | grep -w "FAIL:" | wc -l)
if [ $FAILED_CASES -gt 0 ]
then
  # upload the report to #dev-lib02
  curl -XPOST --data "payload={\"text\": \"> *Unittest* report for \`${TEST_LIB}\`: \
   $(pastebinit -b  https://paste.ubuntu.com)\"}" $SLACK_WEBHOOK_URL
  exit 0
fi
exit $FAILED_CASES