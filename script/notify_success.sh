#!/bin/bash

# author: greyshell
# description: notify the test PASS message

curl -XPOST --data "payload={\"text\": \"> :white_check_mark: *PASSED* :arrow_right: \`${TEST_LIB}\`.\"}" $SLACK_WEBHOOK_URL

