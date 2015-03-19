// Author: Nathan Ross Powell <nathanrospowell@gmail.com>

#include "keymap_common.h"
#include "bootloader.h"

#ifndef KEYMAP_GRID
   /* Planck keymap definition macro for the 'grid' layout
    * ,-----------------------------------------------------------------------.
    * |     |     |     |     |     |     |     |     |     |     |     |     |
    * |-----------------------------------------------------------------------|
    * |     |     |     |     |     |     |     |     |     |     |     |     |
    * |-----------------------------------------------------------------------|
    * |     |     |     |     |     |     |     |     |     |     |     |     |
    * |-----------------------------------------------------------------------|
    * |     |     |     |     |     |     |     |     |     |     |     |     |
    * `-----------------------------------------------------------------------'
    */
#define KEYMAP_GRID( \
       K00,  K01,  K02,  K03,  K04,  K05,  K06,  K07,  K08,  K09,  K0A,  K0B, \
       K10,  K11,  K12,  K13,  K14,  K15,  K16,  K17,  K18,  K19,  K1A,  K1B, \
       K20,  K21,  K22,  K23,  K24,  K25,  K26,  K27,  K28,  K29,  K2A,  K2B, \
       K30,  K31,  K32,  K33,  K34,  K35,  K36,  K37,  K38,  K39,  K3A,  K3B  \
) { \
    { KC_##K00, KC_##K01, KC_##K02, KC_##K03, KC_##K04, KC_##K05, KC_##K06, KC_##K07, KC_##K08, KC_##K09, KC_##K0A, KC_##K0B }, \
    { KC_##K10, KC_##K11, KC_##K12, KC_##K13, KC_##K14, KC_##K15, KC_##K16, KC_##K17, KC_##K18, KC_##K19, KC_##K1A, KC_##K1B }, \
    { KC_##K20, KC_##K21, KC_##K22, KC_##K23, KC_##K24, KC_##K25, KC_##K26, KC_##K27, KC_##K28, KC_##K29, KC_##K2A, KC_##K2B }, \
    { KC_##K30, KC_##K31, KC_##K32, KC_##K33, KC_##K34, KC_##K35, KC_##K36, KC_##K37, KC_##K38, KC_##K39, KC_##K3A, KC_##K3B }  \
}
#endif

const uint8_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
   /* 0: main layer
    * ,-----------------------------------------------------------------------.
    * |Esc  | q   | w   | e   | r   | t   | y   | u   | i   | o   | p   | BS  |
    * |-----------------------------------------------------------------------|
    * |Tab  | a   | s   | d   | f   | g   | h   | j   | k   | l   | ;   | Ret |
    * |-----------------------------------------------------------------------|
    * |Ctrl | z   | x   | c   | v   | b   | n   | m   | .   | ,   | '   |Shift|
    * |-----------------------------------------------------------------------|
    * |Alt  | \   | (   | )   |Lower|Space|Space|Upper| [   | ]   | /   |Meta |
    * `-----------------------------------------------------------------------'
    */
  [0] = KEYMAP_GRID(
       ESC,  Q,    W,    E,    R,    T,    Y,    U,    I,    O,    P,    BSPC,
       TAB,  A,    S,    D,    F,    G,    H,    J,    K,    L,    SCLN, ENT,
       LCTL, Z,    X,    C,    V,    B,    N,    M,    DOT,  COMA, QUOT, RSFT,
       LALT, BSLS, FN10, FN13, FN0,  SPC,  SPC,  FN1,  LBRC, RBRC, SLSH, LGUI ),

   /* 1: fn left/lower layer
    * ,-----------------------------------------------------------------------.
    * |     |     | Up  |     | F1  | F2  | F3  | F4  |Num7 |Num8 |Num9 |     |
    * |-----------------------------------------------------------------------|
    * |     |Left |Down |Right| F5  | F6  | F7  | F8  |Num4 |Num5 |Num6 |Num= |
    * |-----------------------------------------------------------------------|
    * |     | Ins |Home |PgUP | F9  | F10 | F11 | F12 |Num1 |Num2 |Num3 |     |
    * |-----------------------------------------------------------------------|
    * |     | Del | End |PgDn |     |Num/ |Num* |Num. |Num0 |Num+ |Num- |     |
    * `-----------------------------------------------------------------------'
    */
  [1] = KEYMAP_GRID(
       TRNS, TRNS, UP,   TRNS, F1,   F2,   F3,   F4,   P7,   F8,   P9,   TRNS,
       TRNS, LEFT, DOWN, RGHT, F5,   F6,   F7,   F8,   P4,   P5,   P6,   PEQL,
       TRNS, INS,  HOME, PGUP, F9,   F10,  F11,  F12,  P1,   P2,   P3,   TRNS,
       TRNS, DEL,  END,  PGDN, TRNS, PPLS, PAST, PDOT, P0,   PPLS, PMNS, TRNS ),

  /* 2: fn right/raise layer
    * ,-----------------------------------------------------------------------.
    * |      | !   | @   | #   | $   | %   | ^   | &   | *   | -   | +   |    |
    * |-----------------------------------------------------------------------|
    * |     |     |     |     |     |     |     | `   | ~   | _   | =   |     |
    * |-----------------------------------------------------------------------|
    * |     |     |     |     |     |     |     |     |     |     |     |     |
    * |-----------------------------------------------------------------------|
    * |     |NextT| P/P |PrevT|     |     |     |     |Vol- |Mute |Vol+ |     |
    * `-----------------------------------------------------------------------'
    */
  [2] = KEYMAP_GRID(
       TRNS, FN18, FN19, FN20, FN21, FN22, FN23, FN24, FN25, MINS, FN26, PAST,
       TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, GRV,  FN29, FN27, FN15, TRNS,             
       TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS,             
       TRNS, MNXT, MPLY, MPRV, TRNS, TRNS, ESC,  TRNS, VOLD, MUTE, VOLU, TRANS ),
};

enum macro_id {
    M_P0,
    M_P1,
    M_P2,
    M_P3,
    M_P4,
    M_P5,
    M_USERNAME,
    M_BOOTLOADER
};

const uint16_t PROGMEM fn_actions[] = {
  [0] = ACTION_LAYER_MOMENTARY(1), // left/lower layer
  [1] = ACTION_LAYER_MOMENTARY(2), // right/raise layer
  // Program macros
  [2] = ACTION_MACRO(M_P0),
  [3] = ACTION_MACRO(M_P1),
  [4] = ACTION_MACRO(M_P2),
  [5] = ACTION_MACRO(M_P3),
  [6] = ACTION_MACRO(M_P4),
  [7] = ACTION_MACRO(M_P5),
  [8] = ACTION_MACRO(M_USERNAME),
  [9] = ACTION_FUNCTION_TAP(M_BOOTLOADER),
  // Braces
  [10] = ACTION_MODS_KEY(MOD_LSFT, KC_9), // (
  [11] = ACTION_MODS_KEY(MOD_LSFT, KC_LBRC), // {
  [12] = ACTION_MODS_KEY(MOD_LSFT, KC_COMMA), // <
  [13] = ACTION_MODS_KEY(MOD_LSFT, KC_0),  // )
  [14] = ACTION_MODS_KEY(MOD_LSFT, KC_RBRC), // {
  [15] = ACTION_MODS_KEY(MOD_LSFT, KC_DOT), // >
  // Combo
  [16] = ACTION_MODS_KEY(MOD_LALT | MOD_LCTL, KC_DEL), // Ctrl+Alt+Delete
  [17] = ACTION_MODS_KEY(MOD_LSFT | MOD_LCTL, KC_ESC), // Ctrl+Shft+Escape
  // Symbols
  [18] = ACTION_MODS_KEY(MOD_LSFT, KC_1), // !
  [19] = ACTION_MODS_KEY(MOD_LSFT, KC_2), // @
  [20] = ACTION_MODS_KEY(MOD_LSFT, KC_3), // #
  [21] = ACTION_MODS_KEY(MOD_LSFT, KC_4), // $
  [22] = ACTION_MODS_KEY(MOD_LSFT, KC_5), // %
  [23] = ACTION_MODS_KEY(MOD_LSFT, KC_6), // ^
  [24] = ACTION_MODS_KEY(MOD_LSFT, KC_7), // &
  [25] = ACTION_MODS_KEY(MOD_LSFT, KC_8), // *
  [26] = ACTION_MODS_KEY(MOD_LSFT, KC_EQL), // +
  [27] = ACTION_MODS_KEY(MOD_LSFT, KC_MINUS), // _
  [28] = ACTION_MODS_KEY(MOD_LSFT, KC_QUOTE), // "
  [29] = ACTION_MODS_KEY(MOD_LSFT, KC_GRAVE), // ~
  // Debugging
  [30] = ACTION_MODS_KEY(MOD_LSFT, KC_F11), // Step into
  [31] = ACTION_MODS_KEY(MOD_LSFT | MOD_LCTL, KC_F10), // Set cursor to line
 };

// Run a script and pass a key number to it. This is Windows specific and the script needs to be on your path.
// *open run dialog* keypress.py [PRG_NUM]
#define ADD_PYTHON_PROGRAM_ON_WIN( PRG_NUM )  MACRO( D(LGUI), T(R), U(LGUI), W(100), T(K), T(E), T(Y), T(P), T(R), T(E), T(S), T(S), T(DOT), T(P), T(Y), T(SPC), T(PRG_NUM), END )
// *return*
#define RUN_PYTHON_PROGRAM_ON_WIN MACRO( T(ENT), END )

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {
    keyevent_t event = record->event;
    switch (id) {
        case M_P0:
            return event.pressed ?
                ADD_PYTHON_PROGRAM_ON_WIN( 0 ) :
                RUN_PYTHON_PROGRAM_ON_WIN;
        case M_P1:
            return event.pressed ?
                ADD_PYTHON_PROGRAM_ON_WIN( 1 ) :
                RUN_PYTHON_PROGRAM_ON_WIN;
        case M_P2:
            return event.pressed ?
                ADD_PYTHON_PROGRAM_ON_WIN( 2 ) :
                RUN_PYTHON_PROGRAM_ON_WIN;
        case M_P3:
            return event.pressed ?
                ADD_PYTHON_PROGRAM_ON_WIN( 3 ) :
                RUN_PYTHON_PROGRAM_ON_WIN;
        case M_P4:
            return event.pressed ?
                ADD_PYTHON_PROGRAM_ON_WIN( 4 ) :
                RUN_PYTHON_PROGRAM_ON_WIN;
        case M_P5:
            return event.pressed ?
                ADD_PYTHON_PROGRAM_ON_WIN( 5 ) :
                RUN_PYTHON_PROGRAM_ON_WIN;
        case M_USERNAME:
            return event.pressed ?
                MACRO( T(N), T(A), T(T), T(H), T(A), T(N), T(R), T(O), T(S), T(S), T(P), T(O), T(W), T(E), T(L), T(L), END ) :
                MACRO_NONE;
    }
    return MACRO_NONE;
}

void action_function(keyrecord_t *record, uint8_t id, uint8_t opt) {
    if (id == M_BOOTLOADER && record->tap.count > 1 ) {
        clear_keyboard();
        _delay_ms(250);
        bootloader_jump();
    }
}
