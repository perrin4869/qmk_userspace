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
make handwired/dactyl_manuform/4x5:perrin4869:avrdude
```
