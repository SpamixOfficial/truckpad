// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum layers {
    base,
    mod
}layers;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * ┌───┬───┬───┬───┬───┬───┐
     * │Enc│M1 │M2 │M3 │M4 │Enc│
     * └───┴───┴───┴───┴───┴───┘
     * Enc: Encoder switch
     * 
     */
    [base] = LAYOUT_def(TG(mod), KC_NO, KC_NO, KC_NO, KC_NO, KC_NO),
    [mod]  = LAYOUT_def(KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO)
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [base] = { ENCODER_CCW_CW(KC_NO, KC_NO) },
    [mod] = { ENCODER_CCW_CW(KC_NO, KC_NO) }
};
#endif

#ifdef OLED_ENABLE
bool oled_task_user(void) {
    // Host Keyboard Layer Status
    oled_write_P(PSTR("/:\\"), false);

    if (get_highest_layer(layers) == mod) {
        oled_write_P(PSTR("MOD :D\n"), false);
    };

    return false;
}
#endif

// set mod_led status
layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(layers)) {
        case mod:
            rgblight_setrgb_at(RGB_RED, 0);
            break;
        default:
            rgblight_setrgb_at(RGB_CYAN, 0);
            break;
    }
    return state;
};

// final init stuff
void keyboard_post_init_user(void) {
    // turn on status LED if everything went fine :D
    rgblight_setrgb_at(RGB_GREEN, 1);
}