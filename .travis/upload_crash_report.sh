#!/bin/bash

# author: greyshell
# description: upload the crash report to the slack

for f in $(find ../test/make_build_debug/fuzz/ -iname "id*" | grep ".*/crashes/*")
do
  # shellcheck disable=SC2006
  curl -XPOST --data "payload={\"text\": \"`Crash` found: $(xxd $f | pastebinit)\"}" $SLACK_WEBHOOK_URL
done