#!/bin/sh

DIR=$( cd "$(dirname "$0")" ; pwd -P )

mkdir -p ~/.config
ln -sf $DIR/config ~/.config/qmk

mkdir -p ~/.local/share/qmk
ln -sf $DIR ~/.local/share/qmk/qmk_userspace
ln -sf $DIR/qmk_firmware ~/.local/share/qmk/qmk_firmware

qmk setup
