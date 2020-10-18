#!/bin/bash

# author: greyshell
# description: install python3.7

sudo apt install -y software-properties-common
sudo add-apt-repository -y ppa:deadsnakes/ppa
sudo apt update
sudo apt install -y python3.7
pip3.7 install -r requrements.txt
