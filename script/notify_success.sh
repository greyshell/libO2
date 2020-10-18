#!/bin/bash

# author: greyshell
# description: notify the test PASS message

curl -XPOST --data "payload={\"text\": \"> :white_check_mark: *PASS* => \`${TEST_LIB}\`.\"}" $SLACK_WEBHOOK_URL

