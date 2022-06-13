#include "defines.c"

qk_tap_dance_action_t tap_dance_actions[] = {
    [EXIT] = ACTION_TAP_DANCE_DOUBLE(KC_ESC, LALT(KC_F4)),
    [VS] = ACTION_TAP_DANCE_DOUBLE(KC_F10, KC_F11),
    [SNAG] = ACTION_TAP_DANCE_DOUBLE(PLT, A(KC_GRV))

};
