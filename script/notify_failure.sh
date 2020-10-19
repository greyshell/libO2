#!/bin/bash

# author: greyshell
# description: notify the test FAIL message

curl -XPOST --data "payload={\"text\": \"> :x: Test Status for \`${TEST_LIB}\`: *FAILED* \"}" $SLACK_WEBHOOK_URL

