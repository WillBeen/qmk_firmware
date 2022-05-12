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
#define _CTL_GRA  LCTL_T(_GRA)
#define _CTL_O  LCTL_T(KC_O)
#define _OPT_R  LOPT_T(KC_R)
#define _OPT_I  LOPT_T(KC_I)
#define _OPT_GRV  LOPT_T(KC_GRV)
#define _CMD_S  LCMD_T(KC_S)
#define _CMD_E  LCMD_T(KC_E)
#define _CMD_MNS  LCMD_T(KC_MINS)
#define _FNC_SPC  LT(_FCT,KC_SPC)
#define _NUM_TAB  LT(_NUM,KC_TAB)
// combos
#define _CTLnTAB  LCTL(KC_TAB)
#define _CMDnTAB  LCMD(KC_TAB)
#define _CMDnT  LCMD(KC_T)
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
  //,--------------------------------------------.                    ,--------------------------------------------.
        KC_Q ,   KC_W ,   KC_F ,   KC_P ,   KC_B ,                        KC_J ,   KC_L ,   KC_U ,   KC_Y ,   KC_P ,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
      _CTL_A , _OPT_R , _CMD_S ,   KC_T ,   KC_G ,                        KC_H ,   KC_N , _CMD_E , _OPT_I , _CTL_O ,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
        KC_Z ,   KC_X ,   KC_C ,   KC_D ,   KC_V ,                        KC_K ,   KC_M , KC_COMM,  KC_DOT, KC_SLSH,
  //|--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
                                TO(_NUM), KC_LSFT, KC_ENT ,   MO(_SYM), KC_SPC ,MO(_LNG)
                             //`--------------------------'  `--------------------------'
  ),

[_LNG] = LAYOUT_split_3x5_3(
  //,--------------------------------------------.                    ,--------------------------------------------.
        _CIA , KC_TILD, KC_UNDS, KC_DQUO, KC_ESC ,                        _DIU ,   _CIU ,   _GRU ,   _DII ,   _DIO ,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
     _CTL_GRA,_OPT_GRV,_CMD_MNS, KC_QUOT, KC_ENT ,                        _TIN ,   _GRE ,   _ACE ,   _CII ,   _CIO ,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
        _DIA , XXXXXXX,   _CEC , KC_BSLS, KC_TAB ,                        _EUR ,   KC_M ,   _CIE ,   _DIE , XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
                                 KC_DEL , KC_LSFT, KC_BSPC,    XXXXXXX, XXXXXXX, XXXXXXX
                             //`--------------------------'  `--------------------------'
  ),

[_SYM] = LAYOUT_split_3x5_3(
  //,--------------------------------------------.                    ,--------------------------------------------.
      KC_EXLM,  KC_AT , KC_HASH, KC_DLR , KC_ESC ,                      KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_EQL ,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
      KC_LCTL, KC_LOPT, KC_LCMD, KC_PIPE, KC_ENT ,                      KC_LPRN, KC_RPRN,  KC_UP , KC_LBRC, KC_RBRC,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
      KC_CUT , KC_COPY, KC_PSTE, XXXXXXX, KC_TAB ,                       KC_LT , KC_LEFT, KC_DOWN, KC_RGHT,  KC_GT ,
  //|--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
                                MO(_FCT), KC_LSFT, KC_BSPC,    XXXXXXX, XXXXXXX, XXXXXXX
                             //`--------------------------'  `--------------------------'
  ),

[_NUM] = LAYOUT_split_3x5_3(
  //,--------------------------------------------.                    ,--------------------------------------------.
      XXXXXXX,_CTLnTAB,_CMDnTAB, _CMDnT , KC_ESC ,                      KC_PPLS,  KC_7  ,  KC_8  ,  KC_9  , KC_PAST,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
      KC_LCTL, KC_LOPT, KC_LCMD, KC_BTN1, KC_ENT ,                       KC_0  ,  KC_4  ,  KC_5  ,  KC_6  , KC_PEQL,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
      KC_CUT , KC_COPY, KC_PSTE, KC_BTN2, KC_TAB ,                      KC_PMNS,  KC_1  ,  KC_2  ,  KC_3  , KC_PSLS,
  //|--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
                                 KC_COMM, KC_LSFT, KC_BSPC,    KC_PDOT, KC_SPC ,TO(_BSE)
                             //`--------------------------'  `--------------------------'
  ),

[_FCT] = LAYOUT_split_3x5_3(
  //,--------------------------------------------.                    ,--------------------------------------------.
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_ESC ,                      XXXXXXX, KC_F9  , KC_F10 , KC_F11 , KC_F12 ,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
      KC_LCTL, KC_LOPT, KC_LCMD, KC_LSFT, KC_ENT ,                      XXXXXXX, KC_F5  , KC_F6  , KC_F7  , KC_F8  ,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_TAB ,                      XXXXXXX, KC_F1  , KC_F2  , KC_F3  , KC_F4  ,
  //|--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
                                 XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX
                             //`--------------------------'  `--------------------------'
  ),
};
