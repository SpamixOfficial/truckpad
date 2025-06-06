# truckpad

![truckpad](https://i.imgur.com/kyfCHeA.png)

The truckpad is a macropad with ETS2 kept in mind when designing!

* Keyboard Maintainer: [SpamixOfficial](https://github.com/SpamixOfficial)
* Hardware Supported: It has an encoder, OLED display, 4 buttons + a modifier button allowing up to 8 different macros spread across 2 layers!
* Hardware Availability: Check the [github repo](https://github.com/spamixofficial/truckpad) for a BOM and how to build it yourself

__It is recommended that you use the qmk cli to avoid any potential issues__
Make example for this keyboard (after setting up your build environment):

    qmk compile -kb truckpad -km default

Flashing example for this keyboard:

    qmk flash -kb truckpad -km default

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).

## Bootloader

* **Physical reset button**: Unscrew the case and click the reset button on the Seeed XIAO board inside!
