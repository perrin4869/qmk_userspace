## Install

```bash
./setup.sh
```

## Dependencies

The linux installer correctly identifies Slackware,
but unfortunately uses `sboinstall` to install dependencies.

To install the dependencies in `slackware-current` with `sbopkg`:

```bash
sudo sbopkg -k -V SBo-git/current \
  -i arm-binutils \
  -i arm-gcc \
  -i avr-binutils \
  -i avr-gcc \
  -i avr-libc \
  -i avrdude \
  -i dfu-programmer \
  -i dfu-util \
  -i newlib
```

On the latest version of qmk, `hidapi` is required too:

```bash
sudo sbopkg -i hidapi
```

## Flash

`dactyl_manuform`:

```bash
./flash.sh
```

## QMK cli

Install and setup the cli:

```bash
python3 -m pip install --user qmk
qmk setup
```

Copy the keymap:

```bash
rm -rf ~/qmk_firmware/keyboards/handwired/dactyl_manuform/4x5/keymaps/perrin4869
cp -r ./dactyl_manuform ~/qmk_firmware/keyboards/handwired/dactyl_manuform/4x5/keymaps/perrin4869
```

Compile and flash (assuming `~/.config/qmk` was correctly installed):

```bash
qmk compile
qmk flash
```
