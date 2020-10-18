#!/bin/bash

# author: greyshell
# description: notify the test PASS message

curl -XPOST --data "payload={\"text\": \"> \`${TEST_LIB}\` :arrow_right: *PASSED* :white_check_mark: \"}" $SLACK_WEBHOOK_URL

