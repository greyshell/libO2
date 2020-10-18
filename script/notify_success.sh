#!/bin/bash

# author: greyshell
# description: notify the test PASS message

curl -XPOST --data "payload={\"text\": \"> :white_check_mark: \`${TEST_LIB}\` :arrow_right: *PASSED* \"}" $SLACK_WEBHOOK_URL

