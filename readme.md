# cheap_rp2040zero_keys

5x5 matrix numpad keyboard using RP2040-Zero (Waveshare).

* Keyboard Maintainer: [qmk](https://github.com/qmk)
* Hardware Supported: RP2040-Zero, SSD1306 128x32 OLED
* Hardware Availability: Handwired

Make example for this keyboard (after setting up your build environment):

    qmk compile -kb handwired/cheap_rp2040zero_keys -km default
    qmk flash -kb handwired/cheap_rp2040zero_keys -km default

Bootloader: hold BOOTSEL while plugging in USB.

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information.
