#include QMK_KEYBOARD_H
#include "r-okm.h"
#include "sendstring_japanese.h"  // macro sendstring for jis keyboard マクロ文字列送信時に日本語キーボード設定での文字化け回避

bool process_record_user_rokm(uint16_t keycode, keyrecord_t *record) {
    static bool is_lalt_pressed = false;
    static bool is_lwin_pressed = false;
    bool result = false;

    switch (keycode) {
#ifdef MACROS_ENABLE
        case ARROW_1:
            if (record->event.pressed) {
                SEND_STRING("->");
            }
            break;

        case ARROW_2:
            if (record->event.pressed) {
                SEND_STRING("=>");
            }
            break;

#endif
        case Z_TAB:
            if (record->event.pressed) {
                register_code(KC_LALT);
                register_code(KC_TAB);
                is_lalt_pressed = true;
            } else {
                unregister_code(KC_TAB);
            }
            break;

        case Z_UP:
            if (record->event.pressed) {
                register_code(KC_UP);
            } else {
                unregister_code(KC_UP);
            }
            break;

        case Z_DOWN:
            if (record->event.pressed) {
                register_code(KC_DOWN);
            } else {
                unregister_code(KC_DOWN);
            }
            break;

        case Z_LEFT:
            if (record->event.pressed) {
                register_code(KC_LEFT);
            } else {
                unregister_code(KC_LEFT);
            }
            break;

        case Z_RIGHT:
            if (record->event.pressed) {
                register_code(KC_RIGHT);
            } else {
                unregister_code(KC_RIGHT);
            }
            break;

        case X_ONE:
            if (record->event.pressed) {
                register_code(KC_LWIN);
                register_code(KC_1);
                is_lwin_pressed = true;
            } else {
                unregister_code(KC_1);
            }
            break;

        case X_TWO:
            if (record->event.pressed) {
                register_code(KC_LWIN);
                register_code(KC_2);
                is_lwin_pressed = true;
            } else {
                unregister_code(KC_2);
            }
            break;

        case X_THREE:
            if (record->event.pressed) {
                register_code(KC_LWIN);
                register_code(KC_3);
                is_lwin_pressed = true;
            } else {
                unregister_code(KC_3);
            }
            break;

        case X_FOUR:
            if (record->event.pressed) {
                register_code(KC_LWIN);
                register_code(KC_4);
                is_lwin_pressed = true;
            } else {
                unregister_code(KC_4);
            }
            break;

        case X_FIVE:
            if (record->event.pressed) {
                register_code(KC_LWIN);
                register_code(KC_5);
                is_lwin_pressed = true;
            } else {
                unregister_code(KC_5);
            }
            break;

        case X_SIX:
            if (record->event.pressed) {
                register_code(KC_LWIN);
                register_code(KC_6);
                is_lwin_pressed = true;
            } else {
                unregister_code(KC_6);
            }
            break;

        case X_SEVEN:
            if (record->event.pressed) {
                register_code(KC_LWIN);
                register_code(KC_7);
                is_lwin_pressed = true;
            } else {
                unregister_code(KC_7);
            }
            break;

        case ESC_MHEN:
            if (record->event.pressed) {
                register_code(KC_ESC);
                register_code(JP_MHEN);
            } else {
                unregister_code(KC_ESC);
                unregister_code(JP_MHEN);
            }
            break;

        default:
            if (is_lalt_pressed) {
                unregister_code(KC_LALT);
                is_lalt_pressed = false;
            }
            if (is_lwin_pressed) {
                unregister_code(KC_LWIN);
                is_lwin_pressed = false;
            }
            result = true;
            break;
    }

  return result;
}
