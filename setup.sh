#!/bin/sh

DIR=$( cd "$(dirname "$0")" ; pwd -P )

git submodule update --init --recursive

qmk_firmware/util/qmk_install.sh

# symlinks don't work, #include fails
KEYMAP_DIR=qmk_firmware/keyboards/handwired/dactyl_manuform/4x5/keymaps/perrin4869
rm -rf $KEYMAP_DIR
cp -rf "$DIR/dactyl_manuform" $KEYMAP_DIR
