/*
Copyright 2020 Cole Smith <cole@boadsource.xyz>

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

// special chars
// U / L : upper / lower
enum unicode_names {
    // accute accents
    UACE,
    LACE,
    // grave accents
    UGRA,
    LGRA,
    UGRE,
    LGRE,
    UGRU,
    LGRU,
    // circumflex accents
    UCIA,
    LCIA,
    UCIE,
    LCIE,
    UCII,
    LCII,
    UCIO,
    LCIO,
    UCIU,
    LCIU,
    // diaeresis
    UDIA,
    LDIA,
    UDIE,
    LDIE,
    UDII,
    LDII,
    UDIN,
    LDIN,
    UDIO,
    LDIO,
    UDIU,
    LDIU,
    // cedilla
    UCEC,
    LCEC,
    //tilde
    UTIN,
    LTIN,
    // euro
    UEUR,
    LEUR
};

const uint32_t PROGMEM unicode_map[] = {
    [UACE] = 0x00E9,
    [LACE] = 0x00E9,
    [UGRA] = 0x00E1,
    [LGRA] = 0x00E1,
    [UGRE] = 0x00E8,
    [LGRE] = 0x00E8,
    [UGRU] = 0x00F9,
    [LGRU] = 0x00F9,
    [UCIA] = 0x00E2,
    [LCIA] = 0x00E2,
    [UCIE] = 0x00EA,
    [LCIE] = 0x00EA,
    [UCII] = 0x0EFE,
    [LCII] = 0x0EFE,
    [UCIO] = 0x00F4,
    [LCIO] = 0x00F4,
    [UCIU] = 0x00FB,
    [LCIU] = 0x00FB,
    [UDIA] = 0x00E4,
    [LDIA] = 0x00E4,
    [UDIE] = 0x00EE,
    [LDIE] = 0x00EE,
    [UDII] = 0x00EF,
    [LDII] = 0x00EF,
    [UDIN] = 0x00F1,
    [LDIN] = 0x00F1,
    [UDIO] = 0x00F6,
    [LDIO] = 0x00F6,
    [UDIU] = 0x00FC,
    [LDIU] = 0x00FC,
    [UCEC] = 0x00E7,
    [LCEC] = 0x00E7,
    [UTIN] = 0x00F1,
    [LTIN] = 0x00F1,
    [UEUR] = 0x20AC,
    [LEUR] = 0x20AC
};

// hold/press keys
#define _CTL_A  LCTL_T(KC_A)
#define _CTL_O  LCTL_T(KC_O)
#define _OPT_R  LOPT_T(KC_R)
#define _OPT_I  LOPT_T(KC_I)
#define _CMD_S  LCMD_T(KC_S)
#define _CMD_E  LCMD_T(KC_E)
#define _FNC_SPC  LT(_FCT,KC_SPC)
#define _NUM_TAB  LT(_NUM,KC_TAB)
// special chars
#define _ACE XP(LACE,UACE)
#define _GRA XP(LGRA,UGRA)
#define _GRE XP(LGRE,UGRE)
#define _GRU XP(LGRU,UGRU)
#define _CIA XP(LCIA,UCIA)
#define _CIE XP(LCIE,UCIE)
#define _CII XP(LCII,UCII)
#define _CIO XP(LCIO,UCIO)
#define _CIU XP(LCIU,UCIU)
#define _DIA XP(LDIA,UDIA)
#define _DIE XP(LDIE,UDIE)
#define _DII XP(LDII,UDII)
#define _DIN XP(LDIN,UDIN)
#define _DIO XP(LDIO,UDIO)
#define _DIU XP(LDIU,UDIU)
#define _CEC XP(LCEC,UCEC)
#define _TIN XP(LTIN,UTIN)
#define _EUR XP(LEUR,UEUR)

enum layers {
  _BSE,
  _SYM,
  _NUM,
  _FCT,
  _LNG
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_BSE] = LAYOUT_split_3x5_3(
  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,         KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,
  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,         KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,
                    KC_LCTL, XXXXXXX, KC_SPC,         KC_BSPC, XXXXXXX,  KC_ENT
),

[_SYM] = LAYOUT_split_3x5_3(
  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,         KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
  KC_TAB,    KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT,      XXXXXXX, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC,
  KC_LCTL, KC_GRV,  KC_LGUI, KC_LALT, XXXXXXX,      XXXXXXX, XXXXXXX, XXXXXXX, KC_BSLS,  KC_QUOT,
                    XXXXXXX, XXXXXXX, XXXXXXX,      XXXXXXX, XXXXXXX, XXXXXXX
),

[_NUM] = LAYOUT_split_3x5_3(
  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,         KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
  KC_TAB,    KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT,      XXXXXXX, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC,
  KC_LCTL, KC_GRV,  KC_LGUI, KC_LALT, XXXXXXX,      XXXXXXX, XXXXXXX, XXXXXXX, KC_BSLS,  KC_QUOT,
                    XXXXXXX, XXXXXXX, XXXXXXX,      XXXXXXX, XXXXXXX, XXXXXXX
),

[_FCT] = LAYOUT_split_3x5_3(
  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,         KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
  KC_TAB,    KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT,      XXXXXXX, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC,
  KC_LCTL, KC_GRV,  KC_LGUI, KC_LALT, XXXXXXX,      XXXXXXX, XXXXXXX, XXXXXXX, KC_BSLS,  KC_QUOT,
                    XXXXXXX, XXXXXXX, XXXXXXX,      XXXXXXX, XXXXXXX, XXXXXXX
),

[_LNG] = LAYOUT_split_3x5_3(
  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,      KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,
  KC_ESC,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,      XXXXXXX, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR,
  KC_CAPS, KC_TILD, XXXXXXX, XXXXXXX, XXXXXXX,      XXXXXXX, XXXXXXX, XXXXXXX, KC_PIPE,  KC_DQT,
                    XXXXXXX, XXXXXXX, XXXXXXX,      KC_ENT,  XXXXXXX, KC_DEL
)
};
