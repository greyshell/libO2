#!/bin/bash

# author: greyshell
# description: notify the test FAIL message

curl -XPOST --data "payload={\"text\": \"> :speaking_head_in_silhouette: Test Status for \`${TEST_LIB}\` lib: :x: \"}" $SLACK_WEBHOOK_URL

