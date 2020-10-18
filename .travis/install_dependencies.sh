#!/bin/bash

# author: greyshell
# description: install all dependencies

sudo apt-get update
sudo apt-get install cppcheck less  -y

sudo .travis/install_afl.sh
sudo .travis/install_unity.sh