#include "keymap_common.h"

const uint8_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* 0: qwerty */
    [0] = KEYMAP(GRV,  1,    2,    3,    4,    5,    6,    7,    8,    9,    0,    MINS, EQL,    BSPC, \
                 TAB,  Q,    W,    E,    R,    T,    Y,    U,    I,    O,    P,    LBRC, RBRC, BSLS, DEL, \
                 ESC,  A,    S,    D,    F,    G,    H,    J,    K,    L,    SCLN, QUOT,    ENT,     MPLY, \
                 LSFT, Z,    X,    C,    V,    B,    N,    M,    COMM, DOT,  SLSH,    RSFT,    VOLD, VOLU, \
                 LCTL,    LALT,  LGUI,  FN2,    SPC,   FN1,  RGUI,   RALT,         LEFT, DOWN, UP,   RGHT),
    [1] = KEYMAP(GRV,  1,    2,    3,    4,    5,    6,    7,    8,    9,    0,    MINS, EQL,    BSPC, \
                 TAB,  Q,    W,    F,    P,    G,    J,    L,    U,    Y,    SCLN, LBRC, RBRC, BSLS, DEL, \
                 ESC,  A,    R,    S,    T,    D,    H,    N,    E,    I,    O,    QUOT,    ENT,     MPLY, \
                 LSFT, Z,    X,    C,    V,    B,    K,    M,    COMM, DOT,  SLSH,    RSFT,    VOLD, VOLU, \
                 LCTL,    LALT,  LGUI,  FN2,    SPC,   FN1,  RGUI,   RALT,         LEFT, DOWN, UP,   RGHT),
    [2] = KEYMAP(GRV,  F1,   F2,   F3,   F4,   F5,   F6,   F7,   F8,   F9,   F10,  F11,  F12,    BSPC, \
                 TAB,  1,    2,    3,    4,    5,    6,    7,    8,    9,    0,    LBRC, RBRC, BSLS, DEL, \
                 ESC,  FN3, FN4, TRNS, TRNS, TRNS, TRNS, MINS, EQL,  LBRC, RBRC,   BSLS,    ENT,     MPLY, \
                 LSFT, Z,    X,    C,    V,    B,    N,    M,    COMM, DOT,  SLSH,    RSFT,    VOLD, VOLU, \
                 LCTL,    LALT,  LGUI,  TRNS,   SPC,   FN1,  RGUI,   RALT,         MNXT, VOLD, VOLU, MPLY),
    [3] = KEYMAP(GRV,  F1,   F2,   F3,   F4,   F5,   F6,   F7,   F8,   F9,   F10,  F11,  F12,    BSPC, \
                 TAB,  FN10, FN11, FN12, FN13, FN14, FN15, FN16, FN17, FN18, FN19, LBRC, RBRC, BSLS, DEL, \
                 ESC,  FN3, FN4, TRNS, TRNS, TRNS, TRNS, FN20, FN21, FN23, FN24, FN28,    ENT,     MPLY, \
                 LSFT, Z,    X,    C,    V,    B,    N,    M,    COMM, DOT,  SLSH,    RSFT,    VOLD, VOLU, \
                 LCTL,    LALT,  LGUI,  FN2,    SPC,   TRNS, RGUI,   RALT,         MNXT, VOLD, VOLU, MPLY),
};
const uint16_t PROGMEM fn_actions[] = {
    [1] = ACTION_LAYER_MOMENTARY(2),  // to Fn overlay
    [2] = ACTION_LAYER_MOMENTARY(3),  // to Fn overlay 
    // [1] = ACTION_LAYER_ON_OFF(1),
    // [2] = ACTION_LAYER_ON_OFF(2),
    [3] = ACTION_DEFAULT_LAYER_SET(0), 
    [4] = ACTION_DEFAULT_LAYER_SET(1),  

    [10] = ACTION_MODS_KEY(MOD_LSFT, KC_1),
    [11] = ACTION_MODS_KEY(MOD_LSFT, KC_2),
    [12] = ACTION_MODS_KEY(MOD_LSFT, KC_3),
    [13] = ACTION_MODS_KEY(MOD_LSFT, KC_4),
    [14] = ACTION_MODS_KEY(MOD_LSFT, KC_5),
    [15] = ACTION_MODS_KEY(MOD_LSFT, KC_6),
    [16] = ACTION_MODS_KEY(MOD_LSFT, KC_7),
    [17] = ACTION_MODS_KEY(MOD_LSFT, KC_8),
    [18] = ACTION_MODS_KEY(MOD_LSFT, KC_9),
    [19] = ACTION_MODS_KEY(MOD_LSFT, KC_0),
    [20] = ACTION_MODS_KEY(MOD_LSFT, KC_MINS),
    [21] = ACTION_MODS_KEY(MOD_LSFT, KC_EQL),
    [22] = ACTION_MODS_KEY(MOD_LSFT, KC_GRV),
    [23] = ACTION_MODS_KEY(MOD_LSFT, KC_LBRC),
    [24] = ACTION_MODS_KEY(MOD_LSFT, KC_RBRC),
    [28] = ACTION_MODS_KEY(MOD_LSFT, KC_BSLS),
};
