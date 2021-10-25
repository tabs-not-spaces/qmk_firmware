/* Copyright 2020 Paul James
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

#include "lumberjack.h"
#include "enums.c"

bool isFlashing = false;
static uint16_t recording_timer;

bool process_record_kb(uint16_t keycode, keyrecord_t *record) {
    writePin(LED1, record->event.pressed);

    return process_record_user(keycode, record);
}

layer_state_t layer_state_set_kb(layer_state_t state) {
    switch (get_highest_layer(state | default_layer_state)) {
        case _QWERTY:
            led_set_state(false, false);
            break;
        case _RAISE:
            led_set_state(true, true);
            break;
        case _ADJUST:
            recording_timer = timer_read();
        default:
            led_set_state(false, true);
            break;
    }
    return layer_state_set_user(state);
}

void led_set_state(bool led1, bool led2) {
    led1 ? writePin(LED1, true) : writePinLow(LED1);
    led2 ? writePin(LED2, true) : writePinLow(LED2);
}

void matrix_scan_user(void) {
    if (IS_LAYER_ON(_ADJUST)) {
            if (timer_elapsed(recording_timer) > 250) {
                isFlashing = !isFlashing;
                recording_timer = timer_read();
            }
            if (isFlashing) {
                writePin(LED1, true);
                writePin(LED2, true);
            }
            else {
                writePinLow(LED1);
                writePinLow(LED2);
            }
        }
}

