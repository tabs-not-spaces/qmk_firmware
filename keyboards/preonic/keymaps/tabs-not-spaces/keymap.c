/* Copyright 2015-2017 Jack Humbert
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

enum preonic_layers {
    _QWERTY,
    _LOWER,
    _RAISE,
    _ADJUST
};

enum preonic_keycodes {
    LOWER,
    RAISE
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Standard QWERTY */
	[_QWERTY] = LAYOUT_ortho_5x12(
        KC_GRV,     KC_1,   KC_2,       KC_3,       KC_4,       KC_5,   KC_6,   KC_7,       KC_8,    KC_9,    KC_0,    KC_BSPC, \
        KC_TAB,     KC_Q,   KC_W,       KC_E,       KC_R,       KC_T,   KC_Y,   KC_U,       KC_I,    KC_O,    KC_P,    KC_DEL,  \
        KC_ESC,     KC_A,   KC_S,       KC_D,       KC_F,       KC_G,   KC_H,   KC_J,       KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
        KC_LSFT,    KC_Z,   KC_X,       KC_C,       KC_V,       KC_B,   KC_N,   KC_M,       KC_COMM, KC_DOT,  KC_SLSH, KC_ENT,  \
        KC_LCTL,    RGB_TOG, KC_LALT,   KC_LGUI,    MO(_LOWER), KC_SPC, KC_SPC, MO(_RAISE), KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
    ),

    /* LOWER */
	[_LOWER] = LAYOUT_ortho_5x12(
        KC_TILD,      KC_EXLM,    KC_AT,      KC_HASH,    KC_DLR,     KC_PERC, KC_CIRC, KC_AMPR,       KC_ASTR,       KC_MINS,      KC_EQL,     KC_MINS, \
        LSFT(KC_TAB), KC_EXLM,    KC_AT,      LCTL(KC_E), KC_DLR,     KC_PERC, KC_CIRC, KC_AMPR,       KC_ASTR,       KC_LPRN,      KC_RPRN,    KC_DEL,  \
        KC_DEL,       LCTL(KC_A), LCTL(KC_S), KC_F3,      KC_F4,      KC_F5,   KC_F6,   KC_UNDS,       KC_PLUS,       KC_LCBR,      KC_RCBR,    KC_PIPE, \
        _______,      LCTL(KC_Z), LCTL(KC_X), LCTL(KC_C), LCTL(KC_V), KC_F11,  KC_F12,  LSFT(KC_NUHS), LSFT(KC_NUBS), KC_HOME,      KC_END,     _______, \
        _______,      RGB_MOD,    _______,    _______,    _______,    _______, _______, MO(_ADJUST),   KC_MNXT,       LCA(KC_DOWN), LCA(KC_UP), KC_MPLY
    ),

    /* RAISE */
	[_RAISE] = LAYOUT_ortho_5x12(
        KC_F1,    KC_F2,    KC_F3,   KC_F4,   KC_F5,       KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  \
        KC_GRV,   KC_1,     KC_2,    KC_3,    KC_4,        KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL,  \
        KC_DEL,   _______,  _______, _______, _______,     _______, _______, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS, \
        _______,  _______,  _______, _______, _______,     _______, _______, KC_NUHS, KC_NUBS, KC_PGUP, KC_PGDN, _______, \
        _______,  RGB_RMOD, _______, _______, MO(_ADJUST), _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY
    ),

    /* LOWER + RAISE */
	[_ADJUST] = LAYOUT_ortho_5x12(
        KC_F1,    KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,    KC_F10,   KC_F11,   KC_F12,  \
        _______,  RESET,   DEBUG,   _______, _______, _______, _______, TERM_ON, TERM_OFF, _______,  _______,  KC_DEL,  \
        _______,  _______, MU_MOD,  AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, DF(0),   _______,  _______,  _______,  _______, \
        _______,  MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  _______, _______,  _______,  _______,  _______, \
        _______,  _______, _______, _______, _______, _______, _______, _______, _______,  _______,  _______,  _______
    )
};
