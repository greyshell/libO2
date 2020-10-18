#!/bin/bash

# author: greyshell
# description: notify the test FAIL message

curl -XPOST --data "payload={\"text\": \"> :x: *FAILED* :arrow_right: \`${TEST_LIB}\`.\"}" $SLACK_WEBHOOK_URL

