#include "dactyl_manuform.h"
#include "action_layer.h"
#include "eeconfig.h"

// https://www.reddit.com/r/olkb/comments/8qppdn/qmk_issue_with_mt_when_typing_quickly
#define IGNORE_MOD_TAP_INTERRUPT
#undef  PERMISSIVE_HOLD
#undef  PREVENT_STUCK_MODIFIERS

extern keymap_config_t keymap_config;

#define _BASE 0
#define _RAISE 1
#define _LOWER 2

// Fillers to make layering more clear

#define ____ KC_TRNS

#define ALT_ESC  LALT_T(KC_ESC)
#define CTL_BSPC RCTL_T(KC_BSPC)
#define ALT_GRV  RALT_T(KC_GRV)
#define CTL_GRV  LCTL_T(KC_GRV)
#define SFT_SPC  SFT_T(KC_SPC)
#define SFT_ENT  SFT_T(KC_ENT)

#define KC_ML KC_MS_LEFT
#define KC_MR KC_MS_RIGHT
#define KC_MU KC_MS_UP
#define KC_MD KC_MS_DOWN
#define KC_MB1 KC_MS_BTN1
#define KC_MB2 KC_MS_BTN1

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
 *                                    | LCTRL|INSERT| |DELETE| RALT |
 *                                    | +    |      | |      | +    |
 *                                    | ~    |      | |      | ~    |
 *                                    '------+------' '------+------'
 */

[_BASE] = LAYOUT( \
  KC_QUOT, KC_COMM, KC_DOT,  KC_P, KC_Y,                                     KC_F, KC_G, KC_C,    KC_R,   KC_L, \
  KC_A,    KC_O,    KC_E,    KC_U, KC_I,                                     KC_D, KC_H, KC_T,    KC_N,   KC_S, \
  KC_SCLN, KC_Q,    KC_J,    KC_K, KC_X,                                     KC_B, KC_M, KC_W,    KC_V,   KC_Z, \
           KC_LBRC, KC_RBRC,                                                             KC_MINS, KC_EQL,       \
                                         ALT_ESC,   SFT_ENT,   SFT_SPC, CTL_BSPC,                               \
                                         RAISE_TAB, KC_LGUI,   KC_RGUI, LOWER_DEL,                              \
                                         CTL_GRV,   KC_INS,    KC_DEL,  ALT_GRV
),

/* Raise
 * ,----------------------------------,                             ,----------------------------------,
 * |      |      |  mup |      |      |                             | VOL+ |      |  up  |      | PgUp |
 * |------+------+------+------+------|                             |-------------+------+------+------|
 * |      | mleft| mdown|mright|      |                             | MUTE | left | down |right | PgDn |
 * |------+------+------+------+------|                             |------|------+------+------+------|
 * |      | mprev| mplay| mnext|      |                             | VOL- |  /   |  \   |  ?   |  |   |
 * |------+------+------+-------------,                             ,-------------+------+------+------,
 *        | mbtn |mbtn2 |                                                         | HOME | END  |
 *        '------+------'-------------'                             '-------------'------+------'
 *                      |      |      |                             |      |      |
 *                      |      |      |                             |      |      |
 *                      |      |      |                             |      |      |
 *                      '------+------'                             '------+------'
 *                                    '------+------' '------+------'
 *                                    |      |      | |      |      |
 *                                    '------+------' '------+------'
 *                                    |      |RESET | | RESET|      |
 *                                    '------+------' '------+------'
 */

[_RAISE] = LAYOUT( \
  ____, ____,    KC_MU,   ____,    ____,                    KC_VOLU, ____,    KC_UP,   ____,     KC_PGUP,   \
  ____, KC_ML,   KC_MD,   KC_MR,   ____,                    KC_MUTE, KC_LEFT, KC_DOWN, KC_RIGHT, KC_PGDOWN, \
  ____, KC_MPRV, KC_MPLY, KC_MNXT, ____,                    KC_VOLD, KC_SLSH, KC_BSLS, KC_QUES,  KC_PIPE,   \
        KC_MB1,  KC_MB2,                                                      KC_HOME, KC_END,              \
                                   ____, ____,  ____, ____,                                                 \
                                   ____, ____,  ____, ____,                                                 \
                                   ____, RESET, RESET, ____                                                 \
),
/* Lower
 * ,----------------------------------,                             ,----------------------------------,
 * | F1   | F2   | F3   | F4   | F5   |                             |  F6  | F7   |  F8  |  F9  |  F10 |
 * |------+------+------+------+------|                             |-------------+------+------+------|
 * |  1   |  2   |  3   |  4   |  5   |                             |  6   |  7   |  8   |  9   |  10  |
 * |------+------+------+------+------|                             |------|------+------+------+------|
 * |  !   |  @   |  #   |  $   |  %   |                             |  ^   |  &   |  *   |  (   |  )   |
 * |------+------+------+-------------,                             ,-------------+------+------+------,
 *        | F11  | F12  |                                                         |  -   |  =   |
 *        '------+------'-------------'                             '-------------'------+------'
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

[_LOWER] = LAYOUT( \
  KC_F1,   KC_F2,  KC_F3,   KC_F4,  KC_F5,                            KC_F6,   KC_F7,    KC_F8,   KC_F9,   KC_F10,  \
  KC_1,    KC_2,   KC_3,    KC_4,   KC_5,                             KC_6,    KC_7,     KC_8,    KC_9,    KC_0,    \
  KC_EXLM, KC_AT,  KC_HASH, KC_DLR, KC_PERC,                          KC_CIRC, KC_AMPR,  KC_ASTR, KC_LPRN, KC_RPRN, \
           KC_F11, KC_F12,                                                               ____,    ____,             \
                                             ____, ____,  ____, ____,                                               \
                                             ____, ____,  ____, ____,                                               \
                                             ____, ____,  ____, ____                                                \
)
};

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

