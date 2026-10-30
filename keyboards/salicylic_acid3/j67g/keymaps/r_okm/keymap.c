#include QMK_KEYBOARD_H
#include "r_okm.h"
#include "keymap_japanese.h"  // For JP_ keycodes

enum layer_NUMBER {
    _QWERTY = 0,
    _FN,
    _NUMBER,
};

// Mirrors the keymap managed in Remap. Every flash resets the VIA EEPROM to this keymap,
// so edits made in Remap are lost unless they are copied back here first.
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT(
       KC_ESC,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0, JP_MINS, JP_CIRC,  JP_YEN, KC_BSPC,
       KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,   JP_AT, JP_LBRC,  KC_ENT,
      KC_LCTL,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L, JP_SCLN, JP_COLN, JP_RBRC,
      KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M, JP_COMM,  JP_DOT, JP_SLSH, JP_BSLS,   KC_UP, KC_RSFT,
      KC_LCTL, KC_LGUI, LALT_T(JP_MHEN), MO(_FN),     KC_SPC,     MO(_NUMBER), JP_HENK,  KC_APP, KC_LEFT, KC_DOWN, KC_RGHT
  ),

  [_FN] = LAYOUT(
      _______,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12, _______, _______,
  _______,KC_F12,LCTL(KC_W),LCTL(KC_PGUP),LCTL(KC_PGDN),LCS(KC_T),  KC_HOME, ESC_MHEN, _______, KC_END, JP_EQL, _______, _______, LALT(KC_ENT),
  _______,LCTL(KC_A),LCTL(KC_S),LCTL(KC_D),LCTL(KC_F),LCTL(KC_G), KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT, _______, JP_MINS, _______,
  _______,LCTL(KC_Z),LCTL(KC_X),LCTL(KC_C),LCTL(KC_V),LCTL(KC_B), KC_BSPC,  KC_DEL, JP_LBRC, JP_RBRC, ARROW_1, JP_CIRC, _______, _______,
      _______, _______, _______, _______,          _______,          _______, _______, _______, _______, _______, _______
  ),

  [_NUMBER] = LAYOUT(
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
      _______,  KC_F11,   KC_F2,   KC_F3, LALT(KC_F4), KC_F5, LGUI(KC_1), LGUI(KC_2), LGUI(KC_3), LGUI(KC_4), LGUI(KC_5), LGUI(KC_6), _______, _______,
      _______,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0, _______, _______,
      _______, JP_EXLM, JP_DQUO, JP_HASH,  JP_DLR, JP_PERC, JP_AMPR, JP_QUOT, JP_LPRN, JP_RPRN, JP_PIPE, _______, _______, _______,
      _______, _______, _______, _______,          _______,          _______, _______, _______, _______, _______, QK_BOOT
  )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    return process_record_user_r_okm(keycode, record);
}
