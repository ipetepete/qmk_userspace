#pragma once

enum layers {
  _ALPHA,
  _NUMBER,
  _SYMBOL,
  _OPERATOR,
  LAYER_LENGTH
};

enum {
  SINGLE_TAP = 1,
  SINGLE_HOLD = 2,
  DOUBLE_TAP = 3
};

enum tapdances {
  TD_QESC,
  TD_ATAB,
  TD_QUCO,
  TAPDANCE_LENGTH
};


// begin tapdances
#define KC_QESC     TD(TD_QESC)
#define KC_ATAB     TD(TD_ATAB)
#define KC_QUCO     TD(TD_QUCO)
#define KC_GUIX     LGUI_T(KC_X)
#define KC_ALTC     LALT_T(KC_C)

// oneshots
#define KC_OSFT   OSM(MOD_LSFT)
#define KC_OALT   OSM(MOD_LALT)
#define KC_GSYM   LGUI_T(KC_1) // placeholder, see below used as OSL when tapped

// layer changing
#define KC_OSYM   OSL(_SYMBOL)
#define KC_ONUM   LT(_NUMBER, KC_BSPC)
#define KC_SPFN   LT(_OPERATOR, KC_SPC)
#define KC_ZSYM   LT(_SYMBOL, KC_Z)
#define KC_SLSY   LT(_SYMBOL, KC_SLSH)

// Left-hand home row mods
#define ALT_D LALT_T(KC_D)
#define CTL_F LCTL_T(KC_F)

// Right-hand home row mods
#define CTL_J RCTL_T(KC_J)
#define ALT_K LALT_T(KC_K)
#if (defined(KEYBOARD_hazel_bad_wings))
#define LAYOUT_wrap_split_3x5_3(...) LAYOUT_split_3x5_3(__VA_ARGS__)
#endif

#define __________ALPHA_L1__________   KC_QESC,    KC_W,       KC_E,       KC_R,       KC_T
#define __________ALPHA_L2__________   KC_ATAB,    KC_S,       ALT_D,      CTL_F,      KC_G
#define __________ALPHA_L3__________   KC_ZSYM,    KC_X,       KC_C,       KC_V,       KC_B

#define __________ALPHA_R1__________   KC_Y,       KC_U,       KC_I,       KC_O,       KC_P
#define __________ALPHA_R2__________   KC_H,       CTL_J,      ALT_K,      KC_L,       KC_QUCO
#define __________ALPHA_R3__________   KC_N,       KC_M,       KC_COMM,    KC_DOT,     KC_SLSY

#define __________SYMBL_L1__________   KC_EXLM,    KC_AT,      KC_HASH,    KC_DLR,     KC_PERC
#define __________SYMBL_L2__________   KC_GRV,     KC_TILD,    KC_NO,      KC_NO,      KC_NO  
#define __________SYMBL_L3__________   KC_ZSYM,    KC_NO,      KC_NO,      KC_NO,      KC_NO

#define __________SYMBL_R1__________   KC_CIRC,     KC_AMPR,   KC_ASTR,    KC_PIPE,    KC_BSLS
#define __________SYMBL_R2__________   KC_NO,       KC_UNDS,   KC_EQL ,    KC_COLN,    KC_SCLN
#define __________SYMBL_R3__________   KC_PLUS,     KC_MINS,   KC_LABK,    KC_RABK,    KC_SLSY

#define __________NUGUI_L1__________   G(KC_1),    G(KC_2),    G(KC_3),    G(KC_4),    G(KC_5)  
#define __________NUGUI_L2__________   KC_1,       KC_2,       KC_3,       KC_4,       KC_5     
#define __________NUGUI_L3__________   KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO    

#define __________NUGUI_R1__________   G(KC_6),    G(KC_7),    G(KC_8),    G(KC_9),    G(KC_0)    
#define __________NUGUI_R2__________   KC_6,       KC_7,       KC_8,       KC_9,       KC_0
#define __________NUGUI_R3__________   KC_NO,      KC_NO,      KC_NO,      KC_DOT,     KC_NO

#define __________OPER8_L1__________   KC_TAB,     KC_F1,      KC_F2,      KC_F3,      KC_LBRC
#define __________OPER8_L2__________   KC_CAPS,    KC_F4,      KC_F5,      KC_F6,      KC_LCBR
#define __________OPER8_L3__________   KC_LSFT,    KC_F7,      KC_F8,      KC_F9,      KC_LPRN

#define __________OPER8_R1__________   KC_RBRC,      KC_HOME,    KC_UP,      KC_END,     KC_BSPC
#define __________OPER8_R2__________   KC_RCBR,      KC_LEFT,    KC_DOWN,    KC_RIGHT,   KC_VOLU
#define __________OPER8_R3__________   KC_RPRN,      KC_MPRV,    KC_MPLY,    KC_MNXT,    KC_VOLD

#define __________3KEY_LFT__________   KC_LCTL,    KC_LGUI,    KC_OSFT   
#define __________3KEY_RGT__________   KC_SPFN,     KC_ONUM,    KC_ENT

#define _________3KEY_LNUM__________   KC_LCTL,    KC_LALT,    KC_OSFT
#define _________3KEY_RNUM__________   LSG_T(KC_SPC), KC_ONUM,    KC_ENT

#define _________3KEY_LOP8__________   KC_BTN1,    KC_BTN2,    LCA_T(KC_BTN3)
#define _________3KEY_ROP8__________   KC_SPFN,      KC_ONUM,    QK_BOOT

#define ALPHA \
__________ALPHA_L1__________, __________ALPHA_R1__________, \
__________ALPHA_L2__________, __________ALPHA_R2__________, \
__________ALPHA_L3__________, __________ALPHA_R3__________, \
__________3KEY_LFT__________, __________3KEY_RGT__________

#define NUGUI \
__________NUGUI_L1__________, __________NUGUI_R1__________, \
__________NUGUI_L2__________, __________NUGUI_R2__________, \
__________NUGUI_L3__________, __________NUGUI_R3__________, \
_________3KEY_LNUM__________, _________3KEY_RNUM__________

#define SYMBOLS \
__________SYMBL_L1__________, __________SYMBL_R1__________, \
__________SYMBL_L2__________, __________SYMBL_R2__________, \
__________SYMBL_L3__________, __________SYMBL_R3__________, \
__________3KEY_LFT__________, __________3KEY_RGT__________

#define OPERATOR \
__________OPER8_L1__________, __________OPER8_R1__________, \
__________OPER8_L2__________, __________OPER8_R2__________, \
__________OPER8_L3__________, __________OPER8_R3__________, \
_________3KEY_LOP8__________, _________3KEY_ROP8__________ 
