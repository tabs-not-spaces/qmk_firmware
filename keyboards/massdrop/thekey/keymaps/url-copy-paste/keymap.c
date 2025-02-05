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

enum custom_keycodes {
    TK_URL = SAFE_RANGE,
    TK_COPY,
    TK_PASTE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [0] = LAYOUT(
        TK_URL,    TK_COPY,    TK_PASTE
    ),

};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case TK_URL:
            if (record->event.pressed) {
                // when keycode TK_URL is pressed
                SEND_STRING("https://stackoverflow.com/");
            }
            break;
        case TK_COPY:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL("c"));
            }
            break;
        case TK_PASTE:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL("v"));
            }
        default:
            break;
    }
    return true;
}
