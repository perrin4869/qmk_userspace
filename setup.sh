#!/bin/sh

DIR=$( cd "$(dirname "$0")" ; pwd -P )

git submodule update --init --recursive

qmk_firmware/util/qmk_install.sh

mkdir -p ~/.config
ln -sf $DIR/config ~/.config/qmk
