#!/bin/bash

# author: greyshell
# description: notify the build info

BUILD_INFO=$(git log --name-status HEAD^..HEAD | grep commit | cut -c1-14)
curl -XPOST --data "payload={\"text\": \"> :speaking_head_in_silhouette: Testing **${TEST_LIB}** on *${BUILD_INFO}* \"}" $SLACK_WEBHOOK_URL
