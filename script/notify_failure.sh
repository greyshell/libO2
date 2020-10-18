#!/bin/bash

# author: greyshell
# description: notify the test FAIL message

curl -XPOST --data "payload={\"text\": \`${TEST_LIB}\` :arrow_right: *FAILED* :x: \"}" $SLACK_WEBHOOK_URL

