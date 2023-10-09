#include "ipetepete.h"

static uint16_t    next_keycode;
static keyrecord_t next_record;

//Associate our tap dance key with its functionality
tap_dance_action_t tap_dance_actions[] = {
  [TD_QESC]   = ACTION_TAP_DANCE_DOUBLE(KC_Q, KC_ESC),
  [TD_ATAB]   = ACTION_TAP_DANCE_DOUBLE(KC_A, KC_TAB),
  [TD_QUCO]   = ACTION_TAP_DANCE_DOUBLE(KC_QUOT, KC_COLN)
};


const uint16_t PROGMEM test_combo1[] = {KC_A, KC_B, COMBO_END};
combo_t key_combos[] = {
    COMBO(test_combo1, KC_ESC)
};

// stolen from https://github.com/filterpaper/qmk_userspace/blob/main/filterpaper.c
bool pre_process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        // Cache the next input for mod-tap decisions
        next_keycode = keycode;
        next_record  = *record;
    }
    return true;
}

bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
    // Hold Control and Shift with a nested key tap on the opposite hand
    return IS_BILATERAL_TAP(record, next_record) && IS_MOD_TAP_CS(keycode);
}


bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
    // Activate layer with another key press
    if (IS_QK_LAYER_TAP(keycode) && QK_LAYER_TAP_GET_LAYER(keycode)) {
        return true;
    }
    // When a mod-tap key overlaps with another non-Shift key on the same
    // hand without any other modifiers active, send its base keycode
    if (IS_UNILATERAL_TAP(record, next_record) && !IS_MOD_TAP_SHIFT(next_keycode) && !get_mods()) {
        record->keycode = keycode & 0xff;
        process_record(record);
        record->event.pressed = false;
        process_record(record);
    }
    return false;
}

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
  switch (keycode) {
    case KC_SFSY:
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
        case SFT_A:
        case CTL_S:
        case ALT_D:
        case GUI_F:
        case GUI_J:
        case ALT_K:
        case CTL_L:
        case SFT_QUO:
            return TAPPING_TERM * 2;
        default:
            return TAPPING_TERM;
    }
}
