#!/bin/bash

# author: greyshell
# description: upload the crash report to #dev-lib02

for f in $(find test/make_build_debug/fuzz/ -iname "id*" | grep ".*/crashes/*")
do
  curl -XPOST --data "payload={\"text\": \"> \`Crash\` found: $(xxd $f | \
    pastebinit -b  https://paste.ubuntu.com)\"}" $SLACK_WEBHOOK_URL
done
