#!/bin/bash

# author: greyshell
# description: notify the success message

curl -XPOST --data "payload={\"text\": \"> :ballot_box_with_check: All tests are *PASSED* for \`${TEST_LIB}\`.\"}" $SLACK_WEBHOOK_URL

