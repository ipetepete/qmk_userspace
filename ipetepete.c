#include "ipetepete.h"

//Associate our tap dance key with its functionality
tap_dance_action_t tap_dance_actions[] = {
  [TD_QESC]   = ACTION_TAP_DANCE_DOUBLE(KC_Q, KC_ESC),
  [TD_ATAB]   = ACTION_TAP_DANCE_DOUBLE(KC_A, KC_TAB),
  [TD_QUCO]   = ACTION_TAP_DANCE_DOUBLE(KC_QUOT, KC_COLN)
};


bool process_record_user(uint16_t keycode, keyrecord_t* record) {
  switch (keycode) {
    case KC_GSYM:
      if (record->tap.count > 0) {  // Replace tap behavior with OSL.
        if (!record->event.pressed) {
          set_oneshot_layer(SYM, ONESHOT_OTHER_KEY_PRESSED);
        } else {
        clear_oneshot_layer_state(ONESHOT_PRESSED);
        }
        return false;
      }
      break;
  }

  return true;
}


uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch(keycode) {
        case ALT_D:
        case CTL_F:
        case CTL_J:
        case ALT_K:
            return TAPPING_TERM * 2;
        default:
            return TAPPING_TERM;
    }
}


