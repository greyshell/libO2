#!/bin/bash

# author: greyshell
# description: uninstall script

LIB_NAME="libO2"

# verify if the lib exists
ENTRY=$(ldconfig -p | grep $LIB_NAME.so | wc -l)

# removing the lib
if [ $ENTRY -gt 0 ]; then
  FOUND_LIB_PATH=$(find /usr/local -name $LIB_NAME.so)
  echo "[+] deleting $FOUND_LIB_PATH"
  rm -f $FOUND_LIB_PATH
fi

# removing the header files
# shellcheck disable=SC2044
# as there will be no space in the file name
for H_FILE_PATH in $(find ../include/ -iname "*.h"); do
  HEADER_FILE=$(echo $H_FILE_PATH | rev | cut -d "/" -f1 | rev)
  FOUND_PATH=$(find /usr/local -name $HEADER_FILE)
  echo "[+] deleting $FOUND_PATH"
  rm -f $FOUND_PATH
done

# reload ldconfig
echo "[+] reloading ldconfig"
ldconfig

echo "[+] delete all files under build/ directory"
rm -r ../build/*
