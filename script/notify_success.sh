#!/bin/bash

# author: greyshell
# description: notify the test PASS message

curl -XPOST --data "payload={\"text\": \"> :white_check_mark: Test Status for \`${TEST_LIB}\`: *PASSED* \"}" $SLACK_WEBHOOK_URL

