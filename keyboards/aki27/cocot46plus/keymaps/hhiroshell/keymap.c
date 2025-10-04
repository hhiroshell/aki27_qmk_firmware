/*
Copyright 2022 aki27

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H
#include <stdio.h>
#include "quantum.h"


// Defines names for use in layer keycodes and the keymap
enum layer_number {
    _BASE = 0,
    _LOWER = 1,
    _RAISE = 2,
    _FUNC = 3,
    _ADMIN = 4,
    // _Layer5 = 5,
    // _Layer6 = 6
};

#define LCTL_ESC LCTL_T(KC_ESC)

/*
#define CPI_SW USER00
#define SCRL_SW USER01
#define ROT_R15 USER02
#define ROT_L15 USER03
#define SCRL_MO USER04
#define SCRL_TO USER05
#define SCRL_IN USER06
*/

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT(
  //|-------------------------------------------------------|                                   |-------------------------------------------------------|
       KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                                          KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_BSPC,
  //|-------------------------------------------------------|                                   |-------------------------------------------------------|
     LCTL_ESC,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                                          KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_RCTL,
  //|-------------------------------------------------------|                                   |-------------------------------------------------------|
      KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                                          KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_RSFT,
  //|-------------------------------------------------------|                                   |-------------------------------------------------------|
                        KC_LGUI, KC_LALT, MO(_LOWER), KC_SPC, KC_MS_BTN1,               KC_MS_BTN2, KC_ENT, MO(_RAISE), KC_RALT, KC_RGUI,
                                                                 KC_PGUP,   KC_MPLY,     KC_PGDN, XXXXXXX, XXXXXXX, XXXXXXX
                                                            //`--------------'  `--------------'
    ),
  [_LOWER] = LAYOUT(
  //|-------------------------------------------------------|                                   |-------------------------------------------------------|
      XXXXXXX, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,                                       KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_DEL,
  //|-------------------------------------------------------|                                   |-------------------------------------------------------|
      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                       KC_GRV,  KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS,
  //|-------------------------------------------------------|                                   |-------------------------------------------------------|
      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                       KC_TILD, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE,
  //|-------------------------------------------------------|                                   |-------------------------------------------------------|
                        _______, _______, _______, _______,   KC_MS_BTN4,             KC_MS_BTN5, _______, MO(_FUNC), _______, _______,
                                                                 KC_PGUP,   KC_MPLY,  KC_PGDN, XXXXXXX, XXXXXXX, XXXXXXX
                                                            //`--------------'  `--------------'
    ),
  [_RAISE] = LAYOUT(
  //|-------------------------------------------------------|                                   |-------------------------------------------------------|
      XXXXXXX,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                                          KC_6,    KC_7,    KC_8,    KC_9,   KC_0,   KC_DEL,
  //|-------------------------------------------------------|                                   |-------------------------------------------------------|
      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                       KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT, XXXXXXX, KC_RCTL,
  //|-------------------------------------------------------|                                   |-------------------------------------------------------|
      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                       KC_HOME, KC_PGDN, KC_PGUP,  KC_END, XXXXXXX, KC_RSFT,
  //|-------------------------------------------------------|                                   |-------------------------------------------------------|
                      _______, _______, MO(_FUNC), _______,   KC_MS_BTN4,             KC_MS_BTN5, _______, _______, _______, _______,
                                                                 KC_PGUP,   KC_MPLY,  KC_PGDN, XXXXXXX, XXXXXXX, XXXXXXX
                                                            //`--------------'  `--------------'
    ),
  [_FUNC] = LAYOUT(
  //|-------------------------------------------------------|                                   |-------------------------------------------------------|
      XXXXXXX,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                                         KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10, XXXXXXX,
  //|-------------------------------------------------------|                                   |-------------------------------------------------------|
   TG(_ADMIN),  KC_F11,  KC_F12,  KC_F13,  KC_F14,  KC_F15,                                       XXXXXXX, KC_VOLD, KC_VOLU, XXXXXXX, XXXXXXX, XXXXXXX,
  //|-------------------------------------------------------|                                   |-------------------------------------------------------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|-------------------------------------------------------|                                   |-------------------------------------------------------|
                        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   KC_MS_BTN1,             KC_MS_BTN2, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                                                 KC_PGUP,   KC_MPLY,  KC_PGDN, XXXXXXX, XXXXXXX, XXXXXXX
                                                            //`--------------'  `--------------'
    ),
  [_ADMIN] = LAYOUT(
 //|-------------------------------------------------------|                                   |-------------------------------------------------------|
      QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RGB_TOG,                                       SCRL_TO,  CPI_SW, SCRL_SW, ROT_L15, ROT_R15, XXXXXXX,
  //|-------------------------------------------------------|                                   |-------------------------------------------------------|
   TG(_ADMIN), XXXXXXX, RGB_VAI, RGB_SAI, RGB_HUI, RGB_MOD,                                       SCRL_MO, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|-------------------------------------------------------|                                   |-------------------------------------------------------|
      XXXXXXX, XXXXXXX, RGB_VAD, RGB_SAD, RGB_HUD,RGB_RMOD,                                       SCRL_IN, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|-------------------------------------------------------|                                   |-------------------------------------------------------|
                        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   KC_MS_BTN1,             KC_MS_BTN2, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                                                 KC_PGUP,   KC_MPLY,  KC_PGDN, XXXXXXX, XXXXXXX, XXXXXXX
                                                            //`--------------'  `--------------'
  //   ),
  // [_Layer5] = LAYOUT(
  // //|-------------------------------------------------------|                                   |-------------------------------------------------------|
  //     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  // //|-------------------------------------------------------|                                   |-------------------------------------------------------|
  //     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  // //|-------------------------------------------------------|                                   |-------------------------------------------------------|
  //     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  // //|-------------------------------------------------------|                                   |-------------------------------------------------------|
  //                       XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,   XXXXXXX,             XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,
  //                                                                XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
  //                                                           //`--------------'  `--------------'
  //   ),
  // [_Layer6] = LAYOUT(
  // //|-------------------------------------------------------|                                   |-------------------------------------------------------|
  //     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  // //|-------------------------------------------------------|                                   |-------------------------------------------------------|
  //     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  // //|-------------------------------------------------------|                                   |-------------------------------------------------------|
  //     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  // //|-------------------------------------------------------|                                   |-------------------------------------------------------|
  //                       XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,   XXXXXXX,             XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,
  //                                                                XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
  //                                                           //`--------------'  `--------------'
    )
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [0] = { ENCODER_CCW_CW(KC_MPRV, KC_MNXT) },
    [1] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [2] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [3] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [4] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    // [5] = { ENCODER_CCW_CW(KC_PGUP, KC_PGDN) },
    // [6] = { ENCODER_CCW_CW(KC_PGUP, KC_PGDN) },
};
#endif

layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
    case _LOWER:
        rgblight_sethsv_range(HSV_CYAN, 0, 2);
        cocot_set_scroll_mode(true);
        break;
    case _RAISE:
        rgblight_sethsv_range(HSV_WHITE, 0, 2);
        cocot_set_scroll_mode(true);
        break;
    case _FUNC:
        rgblight_sethsv_range(HSV_YELLOW, 0, 2);
        cocot_set_scroll_mode(false);
        break;
    case _ADMIN:
        rgblight_sethsv_range(HSV_ORANGE, 0, 2);
        cocot_set_scroll_mode(false);
        break;
    // case _Layer5:
    //     rgblight_sethsv_range(HSV_CYAN, 0, 2);
    //     cocot_set_scroll_mode(false);
    //     break;
    // case _Layer6:
    //     rgblight_sethsv_range(HSV_ORANGE, 0, 2);
    //     cocot_set_scroll_mode(false);
    //     break;
    default:
        rgblight_sethsv_range( 0, 0, 0, 0, 2);
        cocot_set_scroll_mode(false);
        break;
    }
    rgblight_set_effect_range( 2, 10);
      return state;
};

#ifdef OLED_ENABLE
bool oled_task_user(void) {
    render_logo();
    oled_write_layer_state();
    return false;
}
#endif

static bool mo_lower_pressed = false;
static bool mo_raise_pressed = false;
static bool lctl_pressed = false;
static bool rctl_pressed = false;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case MO(_LOWER):
        if (record->event.pressed) {
            layer_on(_LOWER);
            update_tri_layer(_LOWER, _RAISE, _FUNC);

            mo_lower_pressed = true;
        } else {
            layer_off(_LOWER);
            update_tri_layer(_LOWER, _RAISE, _FUNC);

            if (mo_lower_pressed) {
                tap_code(KC_LNG2);
            }

            mo_lower_pressed = false;
        }
        return false;
        break;

    case MO(_RAISE):
        if (record->event.pressed) {
            layer_on(_RAISE);
            update_tri_layer(_LOWER, _RAISE, _FUNC);

            mo_raise_pressed = true;
        } else {
            layer_off(_RAISE);
            update_tri_layer(_LOWER, _RAISE, _FUNC);

            if (mo_raise_pressed) {
                tap_code(KC_LNG1);
            }

            mo_raise_pressed = false;
        }
        return false;
        break;

    case KC_RCTL:
        // Implement RCTL_T(KC_QUOT) behavior from scratch to avoid unexpected behavior in Ubuntu environment.
        if (record->event.pressed) {
            rctl_pressed = true;
        } else {
            // Unregister RCTL to avoid hitting Ctrl+'
            unregister_code(KC_RCTL);

            if (rctl_pressed) {
                tap_code(KC_QUOT);
            }

            rctl_pressed = false;
        }
        break;

    default:
        if (record->event.pressed) {
            mo_lower_pressed = false;
            mo_raise_pressed = false;
            lctl_pressed = false;
            rctl_pressed = false;
        }
        break;
    }

    return true;
}
