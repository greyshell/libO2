#!/bin/bash

# author: greyshell
# description: notify the test FAIL message

curl -XPOST --data "payload={\"text\": \"> :x: \`${TEST_LIB}\` :arrow_right: *FAILED* \"}" $SLACK_WEBHOOK_URL

