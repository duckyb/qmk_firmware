#include QMK_KEYBOARD_H

// Use italian layout
#include "keymap_italian.h"
// Custom inputs
#define IT_GRV RALT(IT_QUOT) // BACKTICK / GRAVE

enum unicode_names {
    ARR_UP,
    ARR_DOWN,
    ARR_LEFT,
    ARR_RIGHT,
};

const uint32_t PROGMEM unicode_map[] = {
    [ARR_UP]    = 0x2191,
    [ARR_DOWN]  = 0x2193,
    [ARR_LEFT]  = 0x2190,
    [ARR_RIGHT] = 0x2192,
};

// Naming the layers
enum ferris_layers {
    _BASE,
    _EXT,
    _SYM,
    _FNC,
    _SYM2,
    _ACC,
    _FPS,
    _MOBA,
};

// COMBO | Activate accent layer by right thumb combo
const uint16_t PROGMEM accent_combo[] = { SFT_T(KC_SPC), OSL(_SYM), COMBO_END };
combo_t key_combos[COMBO_COUNT] = {
  COMBO(accent_combo, MO(_ACC))
};

// Layouts
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_FPS] = LAYOUT(
    KC_TAB, IT_Q, IT_W, IT_E, IT_R,        IT_T,       IT_G,   KC_UP,  _______, DF(_BASE),
    KC_LSFT, IT_A, IT_S, IT_D, IT_F,       _______, KC_LEFT, KC_DOWN, KC_RIGHT,   _______,
    KC_LCTL, IT_Z, IT_X, IT_C, IT_V,       OSL(_BASE), OSL(_FNC), _______, _______, _______,
                        KC_LALT, KC_SPC, KC_ENTER, KC_ESC
  ), 
  [_BASE] = LAYOUT(
    IT_Q,    IT_W,    IT_E,    IT_R,    IT_T,            IT_Y,    IT_U,  IT_I,    IT_O,   IT_P,
    IT_A,    IT_S,    IT_D,    IT_F,    IT_G,            IT_H,    IT_J,    IT_K,   IT_L,  IT_OGRV,
    IT_Z,    IT_X,    IT_C,    IT_V,    IT_B,            IT_N,    IT_M,  IT_COMM, IT_DOT, IT_UGRV,
                          MO(_EXT), SFT_T(KC_SPC), SFT_T(KC_SPC), OSL(_SYM)
  ),
  [_EXT] = LAYOUT(
    KC_ESC,  _______, _______, _______, _______,                           KC_PGUP, KC_HOME, KC_UP, KC_END, KC_CAPS,
    OSM(MOD_LALT),OSM(MOD_LGUI),OSM(MOD_LSFT),OSM(MOD_LCTL),OSM(MOD_RALT),      KC_PGDN, KC_LEFT, KC_DOWN, KC_RIGHT, KC_DEL,
    C(IT_Z), C(IT_X), C(IT_C), KC_TAB, C(IT_V),                            C(KC_BSPC), KC_BSPC, KC_LSFT, KC_RCTL, _______,
                                    _______, _______, KC_ENTER, MO(_FNC)
  ),
  [_SYM] = LAYOUT(
    IT_1, IT_2, IT_3, IT_4, IT_5,                     IT_6, IT_7, IT_8, IT_9, IT_0,
    IT_LABK, IT_PERC, IT_LPRN, IT_LCBR, IT_LBRC,       IT_EQL, IT_QUES, IT_QUOT, IT_PLUS, IT_ASTR,
    S(IT_LABK), IT_DLR, IT_RPRN, IT_RCBR, IT_RBRC,       IT_AT, IT_EXLM, IT_DQUO, IT_MINS, IT_SLSH,
                                  MO(_FNC), MO(_SYM2), _______, _______
  ),
  // [_SYM] = LAYOUT(
  //   IT_AT, IT_EXLM, IT_DQUO, IT_QUOT, IT_PERC,        IT_EQL, IT_7, IT_8, IT_9, IT_PLUS,
  //   IT_LABK, IT_QUES, IT_LCBR, IT_LPRN, IT_LBRC,       IT_ASTR, IT_4, IT_5, IT_6, IT_MINS,
  //   S(IT_LABK), IT_DLR, IT_RCBR, IT_RPRN, IT_RBRC,       IT_0, IT_1, IT_2, IT_3, IT_SLSH,
  //                                 MO(_FNC), MO(_SYM2), _______, _______
  // ),
  [_FNC] = LAYOUT(
    KC_F1, KC_F2, KC_F3, KC_F4, KC_F5,                       KC_F6, KC_F7, KC_F8, KC_F9, KC_F10,
    OSM(MOD_LALT),OSM(MOD_LGUI),OSM(MOD_LSFT),OSM(MOD_LCTL),OSM(MOD_RALT),     KC_F11, KC_F12, KC_PSCREEN, _______, DF(_FPS),
    _______, _______, _______, _______, _______,                          _______, _______, _______, _______, DF(_MOBA),
                                          _______, _______, _______, _______
  ),
  [_SYM2] = LAYOUT(
    _______, IT_UNDS, IT_PND, IT_EURO, IT_HASH,                _______, _______, X(ARR_UP), _______, _______,
    IT_GRV, RALT(IT_IGRV), IT_BSLS, IT_PIPE, IT_AMPR,       KC_VOLU, X(ARR_LEFT), X(ARR_DOWN), X(ARR_RIGHT), _______,
    _______, KC_MPRV, KC_MPLY, KC_MNXT, KC_MSTP,             KC_VOLD, _______, _______, _______, _______,
                                      _______, _______, _______, _______
  ),
  [_ACC] = LAYOUT(
    _______, _______, _______, RALT(S(IT_E)), _______,       _______, RALT(S(IT_A)), RALT(S(IT_O)), RALT(S(IT_U)), _______,
    IT_AGRV, IT_IGRV, IT_OGRV, IT_EGRV, IT_EACU,             _______, RALT(IT_A), RALT(IT_O), RALT(IT_U), RALT(IT_S),
    _______, _______, _______, IT_UGRV, _______,             _______, _______, _______, _______, _______,
                                       _______, _______, _______, _______
  ),
  [_MOBA] = LAYOUT(
    _______, _______, _______, _______, _______,       _______, _______, _______, _______, DF(_BASE),
    _______, _______, _______, _______, _______,       _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______,       _______, _______, _______, _______, _______,
                                  _______, _______, _______, _______
  ),
  // [_______] = LAYOUT(
  //   _______, _______, _______, _______, _______,       _______, _______, _______, _______, _______,
  //   _______, _______, _______, _______, _______,       _______, _______, _______, _______, _______,
  //   _______, _______, _______, _______, _______,       _______, _______, _______, _______, _______,
  //                                 _______, _______, _______, _______
  // ),
};
