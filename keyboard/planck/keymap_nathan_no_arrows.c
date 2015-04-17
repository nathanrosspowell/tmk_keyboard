// Author: Nathan Ross Powell <nathanrospowell@gmail.com>

#include "keymap_common.h"

const uint8_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
   /* 0: main layer
    * ,-----------------------------------------------------------------------.
    * |Esc  | q   | w   | e   | r   | t   | y   | u   | i   | o   | p   | BS  |
    * |-----------------------------------------------------------------------|
    * |Tab  | a   | s   | d   | f   | g   | h   | j   | k   | l   | ;   | Ret |
    * |-----------------------------------------------------------------------|
    * |Ctrl | z   | x   | c   | v   | b   | n   | m   | ,   | .   | '   |Shift|
    * |-----------------------------------------------------------------------|
    * |Alt  | \   | (   | )   |Lower|Space|Space|Upper| [   | ]   | /   |Meta |
    * `-----------------------------------------------------------------------'
    */
  [0] = KEYMAP_GRID(
       ESC,  Q,    W,    E,    R,    T,    Y,    U,    I,    O,    P,    BSPC,
       TAB,  A,    S,    D,    F,    G,    H,    J,    K,    L,    SCLN, ENT,
       LCTL, Z,    X,    C,    V,    B,    N,    M,    COMM, DOT,  QUOT, RSFT,
       LALT, BSLS, FN10, FN11, FN0,  SPC,  SPC,  FN1,  LBRC, RBRC, SLSH, LGUI ),

   /* 1: fn left/lower layer
    * ,-----------------------------------------------------------------------.
    * |     |no op| Up  |no op| F1  | F2  | F3  | F4  | 7   | 8   | 9   |     |
    * |-----------------------------------------------------------------------|
    * |     |Left |Down |Right| F5  | F6  | F7  | F8  | 4   | 5   | 6   | =   |
    * |-----------------------------------------------------------------------|
    * |     | Ins |Home |PgUP | F9  | F10 | F11 | F12 | 1   | 2   | 3   |     |
    * |-----------------------------------------------------------------------|
    * |     | Del | End |PgDn |Lower|Num/ |Num* |Num. |Num0 |Num+ |Num- |     |
    * `-----------------------------------------------------------------------'
    */
  [1] = KEYMAP_GRID(
       TRNS, NO,   UP,   NO,   F1,   F2,   F3,   F4,   7,    8,    9,    TRNS,
       TRNS, LEFT, DOWN, RGHT, F5,   F6,   F7,   F8,   4,    5,    6,    PEQL,
       TRNS, INS,  HOME, PGUP, F9,   F10,  F11,  F12,  1,    2,    3,    TRNS,
       TRNS, DEL,  END,  PGDN, FN0,  PPLS, PAST, PDOT, 0,    PPLS, PMNS, TRNS ),

  /* 2: fn right/raise layer
    * ,-----------------------------------------------------------------------.
    * |     | !   | @   | #   | $   | %   | ^   | &   | *   | -   | +   | Del |
    * |-----------------------------------------------------------------------|
    * |     |C/A/D|C/S/E|User |Num L|Cap L|Scrol| `   | ~   | _   | =   |     |
    * |-----------------------------------------------------------------------|
    * |     | P0  | P1  | P2  | P3  | P4  | P5  |     |     |     |     |     |
    * |-----------------------------------------------------------------------|
    * |     |NextT| P/P |PrevT|     |     |     |Upper|Vol- |Mute |Vol+ |     |
    * `-----------------------------------------------------------------------'
    */
  [2] = KEYMAP_GRID(
       TRNS, FN18, FN19, FN20, FN21, FN22, FN23, FN24, FN25, MINS, FN26, DEL,
       TRNS, FN16, FN17, FN8,  NLCK, CAPS, SLCK, GRV,  FN29, FN27, EQL,  TRNS,
       TRNS, FN2,  FN3,  FN4,  FN5,  FN6,  FN7,  NO,   NO,   NO,   NO,   NO,
       TRNS, MNXT, MPLY, MPRV, NO,   TRNS, TRNS, FN1,  VOLD, MUTE, VOLU, TRNS ),
};

enum macro_id {
    M_P0,
    M_P1,
    M_P2,
    M_P3,
    M_P4,
    M_P5,
    M_USERNAME
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
  // Braces
  [10] = ACTION_MODS_KEY(MOD_LSFT, KC_9), // (
  [11] = ACTION_MODS_KEY(MOD_LSFT, KC_0),  // )
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
