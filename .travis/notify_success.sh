#!/bin/bash

# author: greyshell
# description: notify the test PASS message

curl -XPOST --data "payload={\"text\": \"> :speaking_head_in_silhouette: Test Status for \`${TEST_LIB}\` lib: :white_check_mark: \"}" $SLACK_WEBHOOK_URL

