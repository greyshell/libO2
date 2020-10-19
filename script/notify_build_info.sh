#!/bin/bash

# author: greyshell
# description: notify the build / commit info

BUILD_INFO=$(git log --name-status HEAD^..HEAD | grep commit | cut -c1-14)
curl -XPOST --data "payload={\"text\": \"> :warning: travis-ci pipeline is triggered for \`${BUILD_INFO}\` \n> Test Lib: \'${TEST_LIB}\` \n> ========================================\"}" $SLACK_WEBHOOK_URL
