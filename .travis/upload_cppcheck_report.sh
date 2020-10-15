#!/bin/bash

# author: greyshell
# description: upload the cppcheck report to the slack


curl -XPOST --data "payload={\"text\": \"CPPCheck Report: $(xxd $f | pastebinit)\"}" \
    $SLACK_WEBHOOK_URL