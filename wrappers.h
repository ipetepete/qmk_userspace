#pragma once

enum layers {
  ALPH,//abc's
  NUM, //NUMBER,
  SYM, //SYMBOLS,
  OPR, //OPERATOR,
  GNV, //GUINAV
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

// thumb mods
#define CTLESC    LCTL_T(KC_ESC)
#define GUITAB    LGUI_T(KC_TAB)
#define SFTALT    LSFT_T(KC_LALT)
#define NUMBKS    LT(NUM, KC_BSPC)

// begin tapdances
#define KC_QESC     TD(TD_QESC)
#define KC_CESC     LCTL_T(KC_ESC)

// oneshots
#define KC_OSFT   OSM(MOD_LSFT)
#define KC_SFSY   LSFT_T(KC_1) // placeholder, see below used as OSL when tapped

// layer changing
#define KC_ONUM   LT(NUM, KC_BSPC)
#define KC_SPFN   LT(OPR, KC_SPC)
#define KC_ZSYM   LT(SYM, KC_Z)
#define KC_SLSY   LT(SYM, KC_SLSH)
#define ENT_GNV   LT(GNV, KC_ENT)

// Left-hand home row mods
#define SFT_A LSFT_T(KC_A)
#define CTL_S LCTL_T(KC_S)
#define ALT_D LALT_T(KC_D)
#define GUI_F LGUI_T(KC_F)

// Right-hand home row mods
#define GUI_J RGUI_T(KC_J)
#define ALT_K RALT_T(KC_K)
#define CTL_L RCTL_T(KC_L)
#define SFT_QUO RSFT_T(KC_QUOT)

//#if (defined(KEYBOARD_hazel_bad_wings))
#define LAYOUT_wrap_split_3x5_3(...) LAYOUT_split_3x5_3(__VA_ARGS__)
//#endif
#define LAYOUT_wrap_planck_grid(...) LAYOUT_planck_grid(__VA_ARGS__)


#define __________ALPHA_L1__________   KC_QESC,    KC_W,       KC_E,       KC_R,       KC_T
#define __________ALPHA_L2__________   KC_A,      CTL_S,      ALT_D,      GUI_F,      KC_G
#define __________ALPHA_L3__________   KC_ZSYM,    KC_X,       KC_C,       KC_V,       KC_B

#define __________ALPHA_R1__________   KC_Y,       KC_U,       KC_I,       KC_O,       KC_P
#define __________ALPHA_R2__________   KC_H,       GUI_J,      ALT_K,      CTL_L,      KC_QUOT
#define __________ALPHA_R3__________   KC_N,       KC_M,       KC_COMM,    KC_DOT,     KC_SLSY

#define __________SYMBL_L1__________   KC_EXLM,    KC_AT,      KC_HASH,    KC_DLR,     KC_PERC
#define __________SYMBL_L2__________   KC_GRV,     KC_TILD,    KC_LBRC,    KC_LCBR,    KC_LPRN
#define __________SYMBL_L3__________   KC_ZSYM,    KC_NO,      KC_RBRC,    KC_RCBR,    KC_RPRN

#define __________SYMBL_R1__________   KC_CIRC,     KC_AMPR,   KC_ASTR,    KC_PIPE,    KC_BSLS
#define __________SYMBL_R2__________   KC_NO,       KC_UNDS,   KC_EQL ,    KC_SCLN,    KC_COLN
#define __________SYMBL_R3__________   KC_PLUS,     KC_MINS,   KC_LABK,    KC_RABK,    KC_SLSY

#define __________NUGUI_L1__________   G(KC_1),    G(KC_2),    G(KC_3),    G(KC_4),    G(KC_5)
#define __________NUGUI_L2__________   G(KC_6),    G(KC_7),    G(KC_8),    G(KC_9),    G(KC_0)
#define __________NUGUI_L3__________   KC_LSFT,    KC_NO,      KC_NO,      KC_PLUS,    KC_EQL

#define __________NUGUI_R1__________   KC_1,       KC_2,       KC_3,       KC_4,       KC_5
#define __________NUGUI_R2__________   KC_6,       KC_7,       KC_8,       KC_9,       KC_0
#define __________NUGUI_R3__________   KC_MINS,    KC_ASTR,    KC_NO,      TO(NUM),    TO(ALPH)

#define __________GUINV_L1__________   G(S(KC_1)), G(S(KC_2)), G(S(KC_3)), G(S(KC_4)), G(S(KC_5))
#define __________GUINV_L2__________   KC_F1,      KC_F2,      KC_F3,      KC_F4,      KC_F5
#define __________GUINV_L3__________   G(KC_BTN1), G(KC_BTN2), G(KC_BTN3), KC_NO,      KC_NO

#define __________GUINV_R1__________   G(S(KC_6)), G(S(KC_7)), G(S(KC_8)), G(S(KC_9)), G(S(KC_0))
#define __________GUINV_R2__________   KC_F6,      KC_F7,      KC_F8,      KC_F9,      KC_F10
#define __________GUINV_R3__________   G(KC_BTN1), G(KC_BTN2), G(KC_BTN3), KC_NO,      KC_NO

#define __________OPER8_L1__________   KC_TAB,     KC_F1,      KC_F2,      KC_F3,      KC_LALT
#define __________OPER8_L2__________   KC_CAPS,    KC_F4,      KC_F5,      KC_F6,      KC_LCTL
#define __________OPER8_L3__________   KC_LSFT,    KC_F7,      KC_F8,      KC_F9,      KC_LGUI

#define __________OPER8_R1__________   KC_RALT,      KC_HOME,    KC_UP,      KC_END,     KC_BSPC
#define __________OPER8_R2__________   KC_RCTL,      KC_LEFT,    KC_DOWN,    KC_RIGHT,   KC_VOLU
#define __________OPER8_R3__________   KC_RGUI,      KC_MPRV,    KC_MPLY,    KC_MNXT,    KC_VOLD

#define __________3KEY_LFT__________   CTLESC,     GUITAB,      KC_SFSY
#define __________3KEY_RGT__________   KC_SPFN,    NUMBKS,     ENT_GNV

#define _________3KEY_LNUM__________   KC_LCTL,    KC_LALT,    KC_OSFT
#define _________3KEY_RNUM__________   LSG_T(KC_SPC), KC_ONUM,    KC_ENT

#define _________3KEY_LOP8__________   KC_BTN1,    KC_BTN2,    KC_DEL
#define _________3KEY_ROP8__________   KC_SPFN,    KC_NO,     QK_BOOT

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

#define GUINAV \
__________GUINV_L1__________, __________GUINV_R1__________, \
__________GUINV_L2__________, __________GUINV_R2__________, \
__________GUINV_L3__________, __________GUINV_R3__________, \
__________3KEY_LFT__________, __________3KEY_RGT__________


// Convert 3x5_3 to 48-key
#define C_48(k) CONV_48(k)
#define CONV_48( \
         l01, l02, l03, l04, l05,   r01, r02, r03, r04, r05, \
         l06, l07, l08, l09, l10,   r06, r07, r08, r09, r10, \
         l11, l12, l13, l14, l15,   r11, r12, r13, r14, r15, \
                   l16, l17, r16,   r17, r18, r19                 \
) \
KC_TAB,  l01, l02, l03, l04, l05,   r01, r02, r03, r04, r05, KC_BSPC, \
KC_CESC, l06, l07, l08, l09, l10,   r06, r07, r08, r09, r10, KC_SCLN, \
KC_LSFT, l11, l12, l13, l14, l15,   r11, r12, r13, r14, r15, RSFT_T(KC_ENT),                                                                       \
BL_TOGG,BL_STEP,OSL(SYM),l16, l17, r16, r17, r18, r19, KC_VOLD, KC_VOLU, KC_MPLY

// Convert 3x5_3 to 48-key
#define C_60(k) CONV_60(k)
#define CONV_60( \
         l01, l02, l03, l04, l05,   r01, r02, r03, r04, r05, \
         l06, l07, l08, l09, l10,   r06, r07, r08, r09, r10, \
         l11, l12, l13, l14, l15,   r11, r12, r13, r14, r15, \
                   l16, l17, r16,   r17, r18, r19                 \
) \
KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_DEL, \
KC_TAB,  l01, l02, l03, l04, l05,   r01, r02, r03, r04, r05, KC_BSPC, \
KC_CESC, l06, l07, l08, l09, l10,   r06, r07, r08, r09, r10, KC_SCLN, \
KC_LSFT, l11, l12, l13, l14, l15,   r11, r12, r13, r14, r15, RSFT_T(KC_ENT),                                                                       \
BL_TOGG,BL_STEP,OSL(SYM),l16, l17, r16, r17, r18, r19, KC_VOLD, KC_VOLU, KC_MPLY
