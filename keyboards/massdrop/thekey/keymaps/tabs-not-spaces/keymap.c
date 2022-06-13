/* Copyright 2021 Joe Maples <joe@maples.dev>
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
#include "enums.c"

qk_tap_dance_action_t tap_dance_actions[] = {
    [PWSH] = ACTION_TAP_DANCE_DOUBLE(KC_F8, KC_F5),
    [CSHARP] = ACTION_TAP_DANCE_DOUBLE(KC_F10, KC_F11),
    [AUDIOCPY] = ACTION_TAP_DANCE_DOUBLE(S(G(KC_A)), C(KC_C)),
    [VIDEOPST] = ACTION_TAP_DANCE_DOUBLE(S(G(KC_O)), C(KC_V)),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_CODE] = LAYOUT(
        MO(_TEAMS), TD(PWSH), TD(CSHARP)
    ),
    [_TEAMS] = LAYOUT(
        _______, TD(AUDIOCPY), TD(VIDEOPST)
    )
};

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        default:
            return TAPPING_TERM;
    }
}
