/*
Copyright 2012,2013 Jun Wako <wakojun@gmail.com>

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
#include "shinory.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_BASE] = LAYOUT_all(
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    JP_MINS, JP_EQL,  KC_BSPC, KC_BSPC, KC_DEL,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    JP_LBRC, JP_RBRC,          JP_BSLS, KC_HOME,
        JP_EISU, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,           KC_END,
        JP_LSFT, JP_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          JP_RSFT, KC_UP,   TT(_FN1),
        KC_LCTL, KC_LGUI, KC_LALT,                            KC_SPC,                             KC_RALT, KC_RCTL,          KC_LEFT, KC_DOWN, KC_RGHT
    ),

    [_FN1] = LAYOUT_all(
        KC_TILD, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, _______, KC_PSCR,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, KC_PGUP,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,          KC_PGDN,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______,
        QK_BOOT, DF(_US), DF(_JP),                            _______,                            _______, _______,          _______, _______, _______
    ),

    [_US] = LAYOUT_all(
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, KC_BSPC, KC_DEL,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC,          KC_BSLS, KC_HOME,
        KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,           KC_END,
        KC_LSFT, KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT, KC_UP,   TT(_FN1),
        KC_LCTL, KC_LGUI, KC_LALT,                            KC_SPC,                             KC_RALT, KC_RCTL,          KC_LEFT, KC_DOWN, KC_RGHT
    ),

    [_JP] = LAYOUT_all(
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    JP_MINS, JP_EQL,  KC_BSPC, KC_BSPC, KC_DEL,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    JP_LBRC, JP_RBRC,          JP_BSLS, KC_HOME,
        JP_EISU, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,           KC_END,
        JP_LSFT, JP_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          JP_RSFT, KC_UP,   TT(_FN1),
        KC_LCTL, KC_LGUI, KC_LALT,                            KC_SPC,                             KC_RALT, KC_RCTL,          KC_LEFT, KC_DOWN, KC_RGHT
    ),

    [_JP_SFT] = LAYOUT_all(
        JP_GRV,  JP_EXLM, JP_AT,   JP_HASH, JP_DLR,  JP_PERC, JP_CIRC, JP_AMPR, JP_ASTR, JP_LPRN, JP_RPRN, JP_UNDS, JP_PLUS, _______, _______, JP_TILD,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, JP_LCBR, JP_RCBR,          JP_PIPE, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______,
        _______, _______, _______,                            _______,                            _______, _______,          _______, _______, _______
    ),

};

static bool lshift = false;
static bool rshift = false;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {

	switch (keycode) {
		case JP_LSFT:
			if (record->event.pressed) {
        	  	lshift = true;
      		} else {
      		    lshift = false;
      		}
			return true;

		case JP_RSFT:
			if (record->event.pressed) {
        	  	rshift = true;
      		} else {
      		    rshift = false;
      		}
			return true;
	}

    uint8_t current_layer = get_highest_layer(layer_state);

	if (current_layer == _JP_SFT) {
		switch (keycode) {
			case _______:
				return true;

			default:
				if (record->event.pressed) {
					unregister_code(KC_LSFT);
					unregister_code(KC_RSFT);
					register_code(keycode);
      			} else {
       				if (lshift) { 
						register_code(KC_LSFT);
					}
        			if (rshift) {
						register_code(KC_RSFT);
					}
					unregister_code(keycode);
      			}
				return false;
		}
	}

	return true;
}