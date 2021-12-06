#!/usr/bin/env bash

APP_DIR=$(dirname $0)

LD_LIBRARY_PATH=${APP_DIR} ./${APP_DIR}/myapp.exe
