#!/bin/bash

# author: greyshell
# description: handle the fuzz status

FAILED_CASES=$(find test/test_build/${TEST_LIB}/fuzz/ -iname "id*" | grep ".*/crashes/*" | wc -l)
if [ $FAILED_CASES -gt 0 ]
then
  # upload the report to #dev-lib02
  for f in $(find test/test_build/${TEST_LIB}/fuzz/ -iname "id*" | grep ".*/crashes/*")
    do
      curl -XPOST --data "payload={\"text\": \"> :speaking_head_in_silhouette: Crash :bomb: found in \`${TEST_LIB}\` lib \n> Report: $(xxd $f | pastebinit -b  https://paste.ubuntu.com)\"}" $SLACK_WEBHOOK_URL
    done
  exit $FAILED_CASES
fi
exit $FAILED_CASES
