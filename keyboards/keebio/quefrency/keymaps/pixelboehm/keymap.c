#include QMK_KEYBOARD_H
#include "keymap_german.h"


// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _BASE 0
#define _FN1 1
#define _FN2 2
#define _FN3 3


#define AUTOFORMAT LGUI(LALT(LSFT(KC_L)))
#define TASK_MANAGER LALT(LGUI(KC_ESC))
#define RAYCAST LCTL(KC_F)

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
};

enum unicode_names {
    UMLAUT_A,
    UMLAUT_a,
    UMLAUT_O,
    UMLAUT_o,
    UMLAUT_U,
    UMLAUT_u,
    SHARP_S,
    EURO,
    HEART
};

const uint32_t PROGMEM unicode_map[] = {
    [UMLAUT_A]  = 0x00C4,
    [UMLAUT_a]  = 0x00E4,
    [UMLAUT_O]  = 0x00D6,
    [UMLAUT_o]  = 0x00F6,
    [UMLAUT_U]  = 0x00DC,
    [UMLAUT_u]  = 0x00FC,
    [SHARP_S]   = 0x00DF,
    [EURO]      = 0x20AC,
    [HEART]      = 0x2764,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT(
    QK_GESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  _______,  KC_BSPC, \
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, \
    MO(_FN1), KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT, \
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, _______, \
    KC_LCTL, MO(_FN2), KC_LGUI, KC_LALT, KC_SPC,           _______,KC_BSPC, KC_RALT, KC_LGUI, _______, MO(_FN2), KC_RCTL
  ),
  [_FN1] = LAYOUT(
    QK_GESC, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______,  KC_DEL, \
    _______, XP(HEART, HEART), RAYCAST, XP(EURO, EURO),   _______, TASK_MANAGER, _______, XP(UMLAUT_u, UMLAUT_U), KC_HOME	, XP(UMLAUT_o, UMLAUT_O), _______, _______, _______, _______, \
    _______, XP(UMLAUT_a, UMLAUT_A), X(SHARP_S), _______, AUTOFORMAT, _______, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, _______, _______, _______,\
    _______, KC_GRV, _______, _______, _______, _______, KC_END, _______, _______, _______, _______, _______, _______, \
    _______, MO(_FN3), _______, _______, _______,          _______, KC_DEL, _______, _______, _______, _______, _______
  ),
  
  [_FN2] = LAYOUT(
    _______, DM_PLY1, DM_PLY2, _______, _______, _______, _______, _______, _______,   _______, UC_LINX, UC_WINC, UC_MAC, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    MO(_FN3), _______, _______, _______, _______, _______, KC_MEDIA_PREV_TRACK, _______, _______, _______, _______, _______, _______,\
    _______, _______, _______, _______, _______, _______, KC_MEDIA_NEXT_TRACK, KC_AUDIO_MUTE, KC_AUDIO_VOL_DOWN, KC_AUDIO_VOL_UP, KC_MEDIA_PLAY_PAUSE, _______, _______, \
    KC_TILD, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______, _______
  ),

  [_FN3] = LAYOUT(
    QK_BOOT, DM_REC1, DM_REC2, _______, _______, _______, _______, _______, _______,   _______, _______, _______, _______, _______, _______, \
    _______, DM_RSTP, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,\
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______, _______
  )
};
