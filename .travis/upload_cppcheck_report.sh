#!/bin/bash

# author: greyshell
# description: upload the crash report to #dev-lib02


curl -XPOST --data "payload={\"text\": \"> \`CPPCheck\` report for ${TEST_LIB}: $(cat test/make_build_debug/cppcheck_report_*.txt | \
    pastebinit -b  https://paste.ubuntu.com)\"}" $SLACK_WEBHOOK_URL
