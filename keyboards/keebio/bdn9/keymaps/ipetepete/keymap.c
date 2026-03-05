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

enum macro_layers {
    MENU=0, // multi
    EDIT,   // edit
    DAW,    // gold
    AUTO,   // cyan
    MOV     // green
};

#define INIT_WS  C(G(S(KC_I)))
#define LFT_DESK C(G(KC_LEFT))
#define RGT_DESK C(G(KC_RIGHT))
#define ALT_TAB  A(KC_TAB)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [MENU] = LAYOUT(
        KC_MUTE, TO(MENU), KC_MPLY,
        TG(DAW), TG(EDIT), TG(AUTO),
        KC_MPRV, TG(MOV),  KC_MNXT
    ),
    [EDIT] = LAYOUT(
        _______, TO(MENU), _______,
        RCTL(KC_A), KC_PGUP, RCTL(KC_C),
        KC_HOME, KC_PGDN, KC_END
    ),
    [DAW] = LAYOUT(
        _______, TO(MENU), _______,
        _______, _______, _______,
        _______, _______, _______
    ),
    [AUTO] = LAYOUT(
        _______, TO(MENU), QK_BOOT,
        INIT_WS, _______, _______,
        LFT_DESK, ALT_TAB, RGT_DESK
    ),
    [MOV] = LAYOUT(
        _______, TO(MENU), _______,
        C(KC_LEFT), KC_UP,   C(KC_RIGHT),
        KC_LEFT,    KC_DOWN, KC_RIGHT
    ),
};

bool encoder_update_user(uint8_t index, bool clockwise) {
    uint8_t current_layer = get_highest_layer(layer_state);
    if (index == 0) {
       if (current_layer == DAW) {
            if (clockwise) {
                tap_code(MS_WHLL);
            } else {
                tap_code(MS_WHLR);
            }
       } else {
           if (clockwise) {
                tap_code(KC_PGDN);
            } else {
                tap_code(KC_PGUP);
            }
        }
    }
    else if (index == 1) {
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
        case AUTO:
            rgb_matrix_set_color_all(RGB_CYAN);
            rgb_matrix_set_color(1, RGB_ORANGE);
            break;
        case DAW:
            rgb_matrix_set_color_all(RGB_GOLD);
            rgb_matrix_set_color(1, RGB_ORANGE);
            break;
        case EDIT:
            rgb_matrix_set_color_all(RGB_RED);
            rgb_matrix_set_color(1, RGB_ORANGE);
            break;
        case MOV:
            rgb_matrix_set_color_all(RGB_GREEN);
            rgb_matrix_set_color(1, RGB_ORANGE);
            break;
        default:
            rgb_matrix_set_color_all(RGB_ORANGE);
            rgb_matrix_set_color(0, RGB_PURPLE);
            rgb_matrix_set_color(1, RGB_ORANGE);
            rgb_matrix_set_color(2, RGB_MAGENTA);
            rgb_matrix_set_color(3, RGB_GOLD);
            rgb_matrix_set_color(4, RGB_RED);
            rgb_matrix_set_color(5, RGB_CYAN);
            rgb_matrix_set_color(6, RGB_BLUE);
            rgb_matrix_set_color(7, RGB_GREEN);
            rgb_matrix_set_color(8, RGB_YELLOW);
            rgb_matrix_set_color(9, 0,0,0);
            rgb_matrix_set_color(10, 0,0,0);
            break;
    }
    return false;
}

