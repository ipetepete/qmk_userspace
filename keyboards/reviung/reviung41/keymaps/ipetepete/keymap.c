#include QMK_KEYBOARD_H

enum layer_names {
    _BASE,
    _LOWER,
    _RAISE,
    _ADJUST
};

#define LOWER  MO(_LOWER)
#define RAISE  MO(_RAISE)

// _______,  XXXXXXX

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT(
       KC_TAB,   KC_Q, KC_W, KC_E, KC_R, KC_T,   KC_Y, KC_U,  KC_I,     KC_O,   KC_P,    KC_BSPC,
       KC_LCTL,  KC_A, KC_S, KC_D, KC_F, KC_G,   KC_H, KC_J,  KC_K,     KC_L,   KC_SCLN, KC_QUOT,
       KC_LSFT,  KC_Z, KC_X, KC_C, KC_V, KC_B,   KC_N, KC_M,  KC_COMM, KC_DOT, KC_SLSH, RSFT_T(KC_ENT),
        GUI_T(KC_ESC), LT(_LOWER, KC_TAB), LT(_RAISE, KC_SPC), LT(_RAISE, KC_BSPC), ALT_T(KC_ENT)
  ),

  [_LOWER] = LAYOUT(
      KC_GRV,   KC_EXLM,   KC_AT,      KC_HASH, KC_DLR,  KC_PERC,       KC_CIRC,  KC_AMPR,  KC_ASTR,  KC_LPRN, KC_RPRN,  KC_BSLS,
      KC_TILD,  XXXXXXX,   XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX,       XXXXXXX,  KC_MINUS, KC_EQUAL, KC_LBRC, KC_RBRC,  KC_PIPE,
      XXXXXXX,  XXXXXXX,   XXXXXXX,    XXXXXXX, KC_LGUI, KC_LALT,       XXXXXXX,  KC_UNDS,  KC_PLUS,  KC_LCBR, KC_RCBR,  CW_TOGG,
                                 _______,   _______,   _______,   _______,  _______
  ),

  [_RAISE] = LAYOUT(
   _______,  KC_1,     KC_2,    KC_3,    KC_4,    KC_5,        KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL,
   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT,XXXXXXX, XXXXXXX,
   KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_RCTL, KC_RALT, KC_RGUI, XXXXXXX, XXXXXXX, KC_RSFT,
                                    _______,    _______,      KC_BSPC,        _______,      _______
  ),

  [_ADJUST] = LAYOUT(
   QK_BOOT, G(KC_1), G(KC_2),  G(KC_3),   G(KC_4),   G(KC_5),   G(KC_6),   G(KC_7),   G(KC_8),   G(KC_9),   G(KC_0), XXXXXXX,
   UG_TOGG, UG_VALU, UG_SATU, UG_HUEU, UG_NEXT, _______,  _______,  _______,  _______,  _______, XXXXXXX, XXXXXXX,
   KC_LSFT, UG_VALD, UG_SATD, UG_HUED, UG_PREV, _______,  KC_MPRV,  KC_VOLD,  KC_VOLU,  KC_MPLY, KC_MNXT,  XXXXXXX,
                  _______,      _______,       _______,        _______,      _______
  ),
};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}
