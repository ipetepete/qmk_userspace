/* Copyright 2019 Danny Nguyen <danny@keeb.io>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H

enum encoder_names {
  _LEFT,
  _RIGHT,
  _MIDDLE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
        | Knob 1: Vol Dn/Up |      | Knob 2: Page Dn/Up |
        | Press: Mute       | Home | Press: Play/Pause  |
        | Hold: Layer 2     | Up   | RGB Mode           |
        | Left              | Down | Right              |
     */
    [0] = LAYOUT(
        KC_MUTE, KC_HOME, KC_MPLY,
        MO(1)  , KC_UP  , RGB_MOD,
        KC_LEFT, KC_DOWN, KC_RGHT
    ),
    /*
        | QK_BOOT          | N/A  | Media Stop |
        | Held: Layer 2  | Home | RGB Mode   |
        | Media Previous | End  | Media Next |
     */
    [1] = LAYOUT(
        QK_BOOT  , BL_STEP, KC_STOP,
        _______, KC_HOME, RGB_MOD,
        KC_MPRV, KC_END , KC_MNXT
    ),
    [2] = LAYOUT(
        _______, _______, QK_BOOT,
        _______, _______, _______,
        _______, _______, _______
    ),
};

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
       if (clockwise) {
            tap_code(KC_PGDN);
        } else {
            tap_code(KC_PGUP);
        }    }
    else if (index == 1) {
        if (clockwise) {
            tap_code(KC_DOWN);
        } else {
            tap_code(KC_UP);
        }
    }
    else if (index == 2) {
         if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }

    }
    return false;
}

/**
 * Layer Switch
 */
bool rgb_matrix_indicators_user(void) {
    uint8_t current_layer = get_highest_layer(layer_state);
    switch (current_layer) {
        case 3:
            rgb_matrix_set_color_all(RGB_CYAN);
            break;
        case 2:
            rgb_matrix_set_color_all(RGB_CORAL);
            break;
        case 1:
            rgb_matrix_set_color_all(RGB_RED);
            break;
        default:
            rgb_matrix_set_color_all(RGB_ORANGE);
            break;
    }
    return false;
}
/*
bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    rgb_matrix_mode(RGB_MATRIX_SOLID_COLOR);
    for (uint8_t i = led_min; i < led_max; i++) {
        switch(get_highest_layer(layer_state|default_layer_state)) {
            case 0:
            #if defined(RGBLIGHT_ENABLE)
                rgb_matrix_set_color(i, HSV_TEAL);
            #endif
                break;
            case 1:
            #if defined(RGBLIGHT_ENABLE)
                rgb_matrix_set_color(i, HSV_CYAN);
            #endif
                break;
            case 2:
            #if defined(RGBLIGHT_ENABLE)
                rgb_matrix_set_color(i, HSV_AZURE);
            #endif
                break;
            default:
            #if defined(RGBLIGHT_ENABLE)
                rgb_matrix_set_color(i, HSV_RED);
            #endif
                break;
        }
    }
    return false;
}

*/
