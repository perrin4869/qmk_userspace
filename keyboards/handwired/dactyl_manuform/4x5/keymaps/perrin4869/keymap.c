/*
This is the c configuration file for the keymap

Copyright 2012 Jun Wako <wakojun@gmail.com>
Copyright 2015 Jack Humbert

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

#define _BASE 0
#define _RAISE 1
#define _LOWER 2

#define ALT_ESC  LALT_T(KC_ESC)
#define CTL_BSPC RCTL_T(KC_BSPC)
#define ALT_GRV  RALT_T(KC_GRV)
#define CTL_GRV  LCTL_T(KC_GRV)
#define SFT_SPC  SFT_T(KC_SPC)
#define SFT_ENT  SFT_T(KC_ENT)

#define RAISE MO(_RAISE)
#define LOWER MO(_LOWER)

#define RAISE_TAB LT(_RAISE, KC_TAB)
#define LOWER_DEL LT(_LOWER, KC_DEL)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Base (dvorak)
     * ,----------------------------------,                             ,----------------------------------,
     * |   '  |   ,  |   .  |   p  |   y  |                             |   f  |   g  |   c  |   r  |   l  |
     * |------+------+------+------+------|                             |-------------+------+------+------|
     * |   a  |   o  |   e  |   u  |   i  |                             |   d  |   h  |   t  |   n  |   s  |
     * |------+------+------+------+------|                             |------|------+------+------+------|
     * |   ;  |   q  |   j  |   k  |   x  |                             |   b  |   m  |   w  |   v  |   z  |
     * |------+------+------+-------------,                             ,-------------+------+------+------,
     *        |  [   |   ]  |                                                         |   -  |   =  |
     *        '------+------'-------------'                             '-------------'------+------'
     *                      |  ESC | ENTER|                             | SPACE|  BS  |
     *                      |  +   |   +  |                             |  +   |  +   |
     *                      | LALT | SHIFT|                             | SHIFT| RCTRL|
     *                      '------+------'                             '------+------'
     *                                    '------+------' '------+------'
     *                                    | TAB  | GUI  | |  GUI | DEL  |
     *                                    |   +  |      | |      | +    |
     *                                    | Raise|      | |      | Lower|
     *                                    '------+------' '------+------'
     *                                    | LCTRL| HOME | |  END | RALT |
     *                                    | +    |      | |      | +    |
     *                                    | ~    |      | |      | ~    |
     *                                    '------+------' '------+------'
     */

    [_BASE] = LAYOUT(
        KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,                                         KC_F,   KC_G,   KC_C,    KC_R,   KC_L,
        KC_A,    KC_O,    KC_E,    KC_U,    KC_I,                                         KC_D,   KC_H,   KC_T,    KC_N,   KC_S,
        KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,                                         KC_B,   KC_M,   KC_W,    KC_V,   KC_Z,
                 KC_LBRC, KC_RBRC,                                                                        KC_MINS, KC_EQL,
                                   ALT_ESC, SFT_ENT,                                      SFT_SPC, CTL_BSPC,
                                                     RAISE_TAB, KC_LGUI,  KC_RGUI, LOWER_DEL,
                                                     CTL_GRV,   KC_HOME,  KC_END,  ALT_GRV
    ),

    /* Raise
     * ,----------------------------------,                             ,----------------------------------,
     * |      |      |  mup |      |      |                             | VOL+ | F12  |  up  | F11  | PgUp |
     * |------+------+------+------+------|                             |-------------+------+------+------|
     * |      | mleft| mdown|mright|      |                             | MUTE | left | down |right | PgDn |
     * |------+------+------+------+------|                             |------|------+------+------+------|
     * |      | mprev| mplay| mnext|      |                             | VOL- |  /   |  \   |  ?   |  |   |
     * |------+------+------+-------------,                             ,-------------+------+------+------,
     *        | mbtn |mbtn2 |                                                         |INSERT|DELETE|
     *        '------+------'-------------'                             '-------------'------+------'
     *                      |      |      |                             |      |      |
     *                      |      |      |                             |      |      |
     *                      |      |      |                             |      |      |
     *                      '------+------'                             '------+------'
     *                                    '------+-------' '--------+------'
     *                                    |      |       | |        |      |
     *                                    '------+-------' '--------+------'
     *                                    |QK_RBT|QK_BOOT| | QK_BOOT|QK_RBT|
     *                                    '------+-------' '--------+------'
     */

    [_RAISE] = LAYOUT(
        _______, _______, MS_UP,   _______, _______,                                      KC_VOLU, KC_F12,  KC_UP,   KC_F11,   KC_PGUP,
        _______, MS_LEFT, MS_DOWN, MS_RGHT, _______,                                      KC_MUTE, KC_LEFT, KC_DOWN, KC_RIGHT, KC_PGDN,
        _______, KC_MPRV, KC_MPLY, KC_MNXT, _______,                                      KC_VOLD, KC_SLSH, KC_BSLS, KC_QUES,  KC_PIPE,
                 MS_BTN1, MS_BTN2,                                                                          KC_INS,  KC_DEL,
                                   _______, _______,                                      _______, _______,
                                                     _______, _______,  _______, _______,
                                                     QK_RBT,  QK_BOOT,  QK_BOOT, QK_RBT
    ),

    /* Lower
     * ,----------------------------------,                             ,------------------------------------,
     * | F1   | F2   | F3   | F4   | F5   |                             |  F6  | F7   |  F8   |  F9  |  F10  |
     * |------+------+------+------+------|                             |-------------+-------+------+-------|
     * |  1   |  2   |  3   |  4   |  5   |                             |  6   |  7   |  8    |  9   |  10   |
     * |------+------+------+------+------|                             |------|------+-------+------+-------|
     * |  !   |  @   |  #   |  $   |  %   |                             |  ^   |  &   |  *    |  (   |  )    |
     * |------+------+------+-------------,                             ,-------------+-------+------+-------,
     *        | F11  | F12  |                                                         | INSERT|DELETE|
     *        '------+------'-------------'                             '-------------'-------+------'
     *                      |      |      |                             |      |      |
     *                      |      |      |                             |      |      |
     *                      |      |      |                             |      |      |
     *                      '------+------'                             '------+------'
     *                                    '------+------' '------+------'
     *                                    |      |      | |      |      |
     *                                    '------+------' '------+------'
     *                                    |      |      | |      |      |
     *                                    '------+------' '------+------'
     */

    [_LOWER] = LAYOUT(
          KC_F1,   KC_F2,  KC_F3,   KC_F4,  KC_F5,                                        KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,
          KC_1,    KC_2,   KC_3,    KC_4,   KC_5,                                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
          KC_EXLM, KC_AT,  KC_HASH, KC_DLR, KC_PERC,                                      KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,
                   KC_F11, KC_F12,                                                                          KC_INS,  KC_DEL,
                                    _______, _______,                                     _______, _______,
                                                     _______, _______,  _______, _______,
                                                     _______, _______,  _______, _______
    )
};
