#include QMK_KEYBOARD_H

/* Custom keycodes */
enum custom_keycodes {
    KC_00 = SAFE_RANGE   /* Double zero */
};

/* Layer definitions */
enum layers {
    _BASE,
    _FN
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * Base Layer (Numpad)
     *
     *        COL0    COL1    COL2    COL3    COL4
     * ┌─────┬─────┬─────┬─────┐
     * │ Tab │  /  │  *  │ BS  │          ROW0 (COL4なし)
     * ├─────┼─────┼─────┼─────┼─────┐
     * │  7  │  8  │  9  │  -  │Boot │    ROW1 (AUX=MagicBoot)
     * ├─────┼─────┼─────┼─────┼─────┤
     * │  4  │  5  │  6  │  +  │NmLk │    ROW2 (ext0=NumLock)
     * ├─────┼─────┼─────┼─────┼─────┤
     * │  1  │  2  │  3  │ Ent │  =  │    ROW3 (ext1=Equal)
     * ├─────┼─────┼─────┼─────┼─────┤
     * │  0  │ 00  │  .  │ Ent │ Fn  │    ROW4 (ext2=Fn)
     * └─────┴─────┴─────┴─────┴─────┘
     */
    [_BASE] = LAYOUT(
        /* ROW0 */ KC_TAB,  KC_PSLS, KC_PAST, KC_BSPC,
        /* ROW1 */ KC_P7,   KC_P8,   KC_P9,   KC_PMNS, QK_BOOT,
        /* ROW2 */ KC_P4,   KC_P5,   KC_P6,   KC_PPLS, KC_NUM,
        /* ROW3 */ KC_P1,   KC_P2,   KC_P3,   KC_PENT, KC_PEQL,
        /* ROW4 */ KC_P0,   KC_00,   KC_PDOT, KC_PENT, MO(_FN)
    ),

    /*
     * Function Layer
     * ┌─────┬─────┬─────┬─────┐
     * │ Esc │     │     │ Del │          ROW0
     * ├─────┼─────┼─────┼─────┼─────┐
     * │ F7  │ F8  │ F9  │ F11 │     │    ROW1
     * ├─────┼─────┼─────┼─────┼─────┤
     * │ F4  │ F5  │ F6  │ F12 │     │    ROW2
     * ├─────┼─────┼─────┼─────┼─────┤
     * │ F1  │ F2  │ F3  │     │     │    ROW3
     * ├─────┼─────┼─────┼─────┼─────┤
     * │ Ins │ F10 │     │     │     │    ROW4
     * └─────┴─────┴─────┴─────┴─────┘
     */
    [_FN] = LAYOUT(
        /* ROW0 */ KC_ESC,  XXXXXXX, XXXXXXX, KC_DEL,
        /* ROW1 */ KC_F7,   KC_F8,   KC_F9,   KC_F11,  XXXXXXX,
        /* ROW2 */ KC_F4,   KC_F5,   KC_F6,   KC_F12,  XXXXXXX,
        /* ROW3 */ KC_F1,   KC_F2,   KC_F3,   XXXXXXX, XXXXXXX,
        /* ROW4 */ KC_INS,  KC_F10,  XXXXXXX, XXXXXXX, _______
    )
};

/* Custom keycode handling */
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_00:
            if (record->event.pressed) {
                tap_code(KC_P0);
                tap_code(KC_P0);
            }
            return false;

        default:
            return true;
    }
}

/* OLED Display */
#ifdef OLED_ENABLE

oled_rotation_t oled_init_user(void) {
    return OLED_ROTATION_180;  /* Adjust if needed */
}

bool oled_task_user(void) {
    /* Line 1: Layer */
    oled_write_P(PSTR("Layer: "), false);
    switch (get_highest_layer(layer_state)) {
        case _BASE:
            oled_write_P(PSTR("Numpad\n"), false);
            break;
        case _FN:
            oled_write_P(PSTR("Function\n"), false);
            break;
        default:
            oled_write_P(PSTR("Unknown\n"), false);
    }

    /* Line 2: Lock status */
    led_t led_state = host_keyboard_led_state();
    oled_write_P(PSTR("NumLk: "), false);
    oled_write_P(led_state.num_lock ? PSTR("ON ") : PSTR("OFF"), false);
    oled_write_P(PSTR(" Caps: "), false);
    oled_write_P(led_state.caps_lock ? PSTR("ON\n") : PSTR("OFF\n"), false);

    /* Line 3: Keyboard name */
    oled_write_P(PSTR("RP2040 Numpad\n"), false);

    return false;
}

#endif
