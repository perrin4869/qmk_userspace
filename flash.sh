#!/bin/sh

DIR=$( cd "$(dirname "$0")" ; pwd -P )

# symlinks don't work, #include fails
KEYMAP_DIR=qmk_firmware/keyboards/handwired/dactyl_manuform/4x5/keymaps/perrin4869
rm -rf $KEYMAP_DIR
cp -rf "$DIR/dactyl_manuform" $KEYMAP_DIR
( cd qmk_firmware && make handwired/dactyl_manuform/4x5:perrin4869:avrdude )
