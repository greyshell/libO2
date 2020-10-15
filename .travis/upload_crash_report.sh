#!/bin/bash

# author: greyshell
# description: upload the crash report to the slack

for f in $(find ../test/make_build_debug/fuzz/ -iname "id*" | grep ".*/crashes/*")
do
  curl -XPOST --data "payload={\"text\": \"Found crash: $(xxd $f | pastebinit)\"}" \
    $SLACK_WEBHOOK_URL
done