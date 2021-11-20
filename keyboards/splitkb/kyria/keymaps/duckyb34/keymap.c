/* Copyright 2019 Thomas Baart <thomas@splitkb.com>
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
#include "keymap_italian.h"

// Custom inputs
#define IT_GRV RALT(IT_QUOT) // BACKTICK / GRAVE

enum layers {
    _BASE = 0,
    _SYM,
    _EXT,
    _FNC,
    _SYM2,
    _ACC,
};

// COMBO | Activate accent layer by right thumb combo
const uint16_t PROGMEM accent_combo[] = { SFT_T(KC_SPC), OSL(_SYM), COMBO_END };
combo_t key_combos[COMBO_COUNT] = {
  COMBO(accent_combo, MO(_ACC))
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT(
      _______,   KC_Q,   IT_W,   IT_E,   IT_R, IT_T,                                         IT_Y,    IT_U,    IT_I,    IT_O,    IT_P,    _______,
      _______,   IT_A,   IT_S,   IT_D,   IT_F, IT_G,                                         IT_H,    IT_J,    IT_K,    IT_L,    IT_OGRV, _______,
      _______,   IT_Z,   IT_X,   IT_C,   IT_V, IT_B, _______, _______,     _______, _______, IT_N,    IT_M,    IT_COMM, IT_DOT,  IT_UGRV, _______,
              _______, _______, MO(_EXT), SFT_T(KC_SPC), _______,         _______, SFT_T(KC_SPC), OSL(_SYM), _______, _______ // KC_ENC
    ),
    [_SYM] = LAYOUT(
      _______, IT_1, IT_2, IT_3, IT_4, IT_5,                     IT_6, IT_7, IT_8, IT_9, IT_0, _______,
      _______, IT_LABK, IT_PERC, IT_LPRN, IT_LCBR, IT_LBRC,       IT_EQL, IT_QUES, IT_QUOT, IT_PLUS, IT_ASTR, _______,
      _______, S(IT_LABK), IT_DLR, IT_RPRN, IT_RCBR, IT_RBRC, _______, _______,    _______, _______, IT_AT, IT_EXLM, IT_DQUO, IT_MINS, IT_SLSH, _______,
                                 _______, _______, MO(_FNC), MO(_SYM2), _______,    _______, _______, _______, _______, _______
    ),
    [_EXT] = LAYOUT(
      _______, KC_ESC,  _______, _______, _______, _______,                           KC_PGUP, KC_HOME, KC_UP, KC_END, KC_CAPS, _______,
      _______, OSM(MOD_LALT),OSM(MOD_LGUI),OSM(MOD_LSFT),OSM(MOD_LCTL),OSM(MOD_RALT),      KC_PGDN, KC_LEFT, KC_DOWN, KC_RIGHT, KC_DEL, _______,
      _______, C(IT_Z), C(IT_X), C(IT_C), KC_TAB, C(IT_V), _______, _______,     _______, _______,  C(KC_BSPC), KC_BSPC, KC_LSFT, KC_RCTL, _______, _______,
                                 _______, _______, _______, _______, _______,    _______, KC_ENTER, MO(_FNC), _______, _______
    ),
    [_FNC] = LAYOUT(
      _______, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5,                       KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, _______,
      _______, OSM(MOD_LALT),OSM(MOD_LGUI),OSM(MOD_LSFT),OSM(MOD_LCTL),OSM(MOD_RALT),     KC_F11, KC_F12, KC_PSCREEN, _______, _______, _______,
      _______, RGB_HUI, RGB_HUD, RGB_VAI, RGB_VAD, _______, _______, _______,    _______, _______, _______, _______, _______, _______, _______, _______,
                                 _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______
    ),
    [_SYM2] = LAYOUT(
      _______, _______, IT_UNDS, IT_PND, IT_EURO, IT_HASH,                                         _______, _______, _______, _______, _______, _______,
      _______, IT_GRV, RALT(IT_IGRV), IT_BSLS, IT_PIPE, IT_AMPR,                                   _______, _______, _______, _______, _______, _______,
      _______, _______, KC_MPRV, KC_MPLY, KC_MNXT, KC_MSTP, _______, _______,    _______, _______, _______, _______, _______, _______, _______, _______,
                                 _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______
    ),
    [_ACC] = LAYOUT(
      _______, _______, _______, _______, RALT(S(IT_E)), _______,       _______, RALT(S(IT_A)), RALT(S(IT_O)), RALT(S(IT_U)), _______, _______,
      _______, IT_AGRV, IT_IGRV, IT_OGRV, IT_EGRV, IT_EACU,             _______, RALT(IT_A), RALT(IT_O), RALT(IT_U), RALT(IT_S), _______,
      _______, _______, _______, _______, IT_UGRV, _______, _______, _______,    _______, _______, _______, _______, _______, _______, _______, _______,
                                 _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______
    ),
};

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (clockwise) {
        tap_code16(C(KC_Y));
    } else {
        tap_code16(C(KC_Z));
    }
    return true;
}
