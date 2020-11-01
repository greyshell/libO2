#!/bin/bash

# author: greyshell
# description: notify the test FAIL message

curl -XPOST --data "payload={\"text\": \"> :x: Unittest failed for *${TEST_LIB}* \"}" $SLACK_WEBHOOK_URL

