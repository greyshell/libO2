#!/bin/bash

# author: greyshell
# description: upload the crash report to #dev-lib02


curl -XPOST --data "payload={\"text\": \"> \`CPPCheck\` report: $(pastebinit -b  https://paste.ubuntu.com < test/make_build_debug/cppcheck_report_${TEST_LIB})\"}" $SLACK_WEBHOOK_URL
