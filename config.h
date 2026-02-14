// Copyright 2024 Handwired
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

// I2C configuration for OLED (I2C1)
#define I2C_DRIVER I2CD1
#define I2C1_SDA_PIN GP10
#define I2C1_SCL_PIN GP11

/* OLED Configuration */
#define OLED_DISPLAY_128X32
#define OLED_BRIGHTNESS 255
#define OLED_TIMEOUT 0           /* 0 = no timeout */
#define OLED_UPDATE_INTERVAL 50  /* ms */

/* Optional: OLED flipped if mounted upside down */
// #define OLED_DISPLAY_FLIP

/* Matrix has an AUX port at ROW1-COL4 (XH/PH 2pin connector, no physical key) */
/* Assigned to QK_BOOT (MagicBoot) for entering bootloader mode */