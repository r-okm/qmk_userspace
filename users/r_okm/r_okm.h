#pragma once

#include "action.h"
#include "quantum_keycodes.h"

enum r_okm_custom_keycodes {
    ARROW_1 = SAFE_RANGE,
    ARROW_2,
    Z_TAB,
    Z_UP,
    Z_DOWN,
    Z_LEFT,
    Z_RIGHT,
    X_ONE,
    X_TWO,
    X_THREE,
    X_FOUR,
    X_FIVE,
    X_SIX,
    X_SEVEN,
    ESC_MHEN,
    R_OKM_SAFE_RANGE
};

bool process_record_user_r_okm(uint16_t keycode, keyrecord_t *record);
