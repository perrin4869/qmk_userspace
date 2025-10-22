# Setup

To compile and flash qmk firmware onto a ProMicro, we need the following dependencies.
On slackware64-current these can be installed with `sbopkg`.

## Dependencies

To install the dependencies in `slackware64-current` with `sbopkg`, run:

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

On the latest version of qmk, `hidapi` is required too. It is both available via `sbopkg`:

```bash
sudo sbopkg -i hidapi
```

and also the [`slackers.it`](https://slackers.it/) repository, setup via `slackpkg+`.

## Notes

`qmk_firmware` ships with an [install script](https://github.com/qmk/qmk_firmware/blob/master/util/install/slackware.sh) for slackware, which is invoked by [qmk_install.sh](https://github.com/qmk/qmk_firmware/blob/d0db38cbdc9410dd58e6c83d18bca2232b823d24/util/qmk_install.sh#L35).
However, the script uses `sboinstall` and it is targeted for slackware 15.0.
