/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

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

// special chars
// U / L : upper / lower
// enum unicode_names {
//     // accute accents
//     UACE,
//     LACE,
//     // grave accents
//     UGRA,
//     LGRA,
//     UGRE,
//     LGRE,
//     UGRU,
//     LGRU,
//     // circumflex accents
//     UCIA,
//     LCIA,
//     UCIE,
//     LCIE,
//     UCII,
//     LCII,
//     UCIO,
//     LCIO,
//     UCIU,
//     LCIU,
//     // diaeresis
//     UDIA,
//     LDIA,
//     UDIE,
//     LDIE,
//     UDII,
//     LDII,
//     UDIN,
//     LDIN,
//     UDIO,
//     LDIO,
//     UDIU,
//     LDIU,
//     // cedilla
//     UCEC,
//     LCEC,
//     //tilde
//     UTIN,
//     LTIN,
//     // euro
//     UEUR,
//     LEUR
// };

// const uint32_t PROGMEM unicode_map[] = {
//     [UACE] = 0x00E9,
//     [LACE] = 0x00E9,
//     [UGRA] = 0x00E1,
//     [LGRA] = 0x00E1,
//     [UGRE] = 0x00E8,
//     [LGRE] = 0x00E8,
//     [UGRU] = 0x00F9,
//     [LGRU] = 0x00F9,
//     [UCIA] = 0x00E2,
//     [LCIA] = 0x00E2,
//     [UCIE] = 0x00EA,
//     [LCIE] = 0x00EA,
//     [UCII] = 0x0EFE,
//     [LCII] = 0x0EFE,
//     [UCIO] = 0x00F4,
//     [LCIO] = 0x00F4,
//     [UCIU] = 0x00FB,
//     [LCIU] = 0x00FB,
//     [UDIA] = 0x00E4,
//     [LDIA] = 0x00E4,
//     [UDIE] = 0x00EE,
//     [LDIE] = 0x00EE,
//     [UDII] = 0x00EF,
//     [LDII] = 0x00EF,
//     [UDIN] = 0x00F1,
//     [LDIN] = 0x00F1,
//     [UDIO] = 0x00F6,
//     [LDIO] = 0x00F6,
//     [UDIU] = 0x00FC,
//     [LDIU] = 0x00FC,
//     [UCEC] = 0x00E7,
//     [LCEC] = 0x00E7,
//     [UTIN] = 0x00F1,
//     [LTIN] = 0x00F1,
//     [UEUR] = 0x20AC,
//     [LEUR] = 0x20AC
// };

// hold/press keys
#define _CTL_A  LCTL_T(KC_A)
#define _CTL_GRA  LCTL_T(_GRA)
#define _CTL_O  LCTL_T(KC_O)
#define _OPT_R  LOPT_T(KC_R)
#define _OPT_I  LOPT_T(KC_I)
#define _OPT_UDS  LOPT_T(KC_UNDS)
#define _CMD_S  LCMD_T(KC_S)
#define _CMD_E  LCMD_T(KC_E)
#define _CMD_MNS  LCMD_T(KC_MINS)
#define _FNC_SPC  LT(_FCT,KC_SPC)
#define _NUM_TAB  LT(_NUM,KC_TAB)
// combos
#define _CTLnTAB  LCTL(KC_TAB)
#define _CMDnTAB  LCMD(KC_TAB)
#define _CMDnT  LCMD(KC_T)
#define _CMDnX  LCMD(KC_X)
#define _CMDnC  LCMD(KC_C)
#define _CMDnV  LCMD(KC_V)

enum my_keycodes {
    // dead keys
    DQUOT = SAFE_RANGE,
    CIRC,
    TILDE,

    // accute accents
    _ACE,
    // grave accents
    _GRA,
    _GRE,
    _GRU,
    // circumflex accents
    _CIA,
    _CIE,
    _CII,
    _CIO,
    _CIU,
    // diaeresis
    _DIA,
    _DIE,
    _DII,
    _DIN,
    _DIO,
    _DIU,
    // cedilla
    _CEC,
    //tilde
    _TIN,
    // euro
    _EUR
};

// special chars
// #define _ACE XP(LACE,UACE)
// #define _GRA XP(LGRA,UGRA)
// #define _GRE XP(LGRE,UGRE)
// #define _GRU XP(LGRU,UGRU)
// #define _CIA XP(LCIA,UCIA)
// #define _CIE XP(LCIE,UCIE)
// #define _CII XP(LCII,UCII)
// #define _CIO XP(LCIO,UCIO)
// #define _CIU XP(LCIU,UCIU)
// #define _DIA XP(LDIA,UDIA)
// #define _DIE XP(LDIE,UDIE)
// #define _DII XP(LDII,UDII)
// #define _DIN XP(LDIN,UDIN)
// #define _DIO XP(LDIO,UDIO)
// #define _DIU XP(LDIU,UDIU)
// #define _CEC XP(LCEC,UCEC)
// #define _TIN XP(LTIN,UTIN)
// #define _EUR XP(LEUR,UEUR)


// #define _ACE UC(0x00E9)
// #define _GRA UC(0x00E9)
// #define _GRE UC(0x00E9)
// #define _GRU UC(0x00E9)
// #define _CIA UC(0x00E9)
// #define _CIE UC(0x00E9)
// #define _CII UC(0x00E9)
// #define _CIO UC(0x00E9)
// #define _CIU UC(0x00E9)
// #define _DIA UC(0x00E9)
// #define _DIE UC(0x00E9)
// #define _DII UC(0x00E9)
// #define _DIN UC(0x00E9)
// #define _DIO UC(0x00E9)
// #define _DIU UC(0x00E9)
// #define _CEC UC(0x00E9)
// #define _TIN UC(0x00E9)
// #define _EUR UC(0x00E9)

enum layers {
  _BSE,
  _SYM,
  _NUM,
  _FCT,
  _LNG
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BSE] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX,   KC_Q ,   KC_W ,   KC_F ,   KC_P ,   KC_B ,                        KC_J ,   KC_L ,   KC_U ,   KC_Y , KC_SCLN, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, _CTL_A , _OPT_R , _CMD_S ,   KC_T ,   KC_G ,                        KC_H ,   KC_N , _CMD_E , _OPT_I , _CTL_O , XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX,   KC_Z ,   KC_X ,   KC_C ,   KC_D ,   KC_V ,                        KC_K ,   KC_M , KC_COMM,  KC_DOT, KC_SLSH, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                         TO(_NUM), KC_LSFT, KC_ENT ,   MO(_SYM), KC_SPC ,MO(_LNG)
                                      //`--------------------------'  `--------------------------'
  ),
  
  [_LNG] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX,   _CIA ,  TILDE , KC_UNDS,  DQUOT , KC_ESC ,                        _DIU ,   _CIU ,   _GRU ,   _DII ,   _DIO , XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX,   _GRA , KC_GRV , KC_MINS, KC_QUOT, KC_ENT ,                        _TIN ,   _GRE ,   _ACE ,   _CII ,   _CIO , XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX,   _DIA , XXXXXXX,   _CEC , KC_BSLS, KC_TAB ,                        _EUR ,   KC_M ,   _CIE ,   _DIE , UC_M_MA, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_DEL , KC_LSFT, KC_BSPC,    QK_BOOT, XXXXXXX, XXXXXXX
                                      //`--------------------------'  `--------------------------'
  ),

  [_SYM] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, KC_EXLM,  KC_AT , KC_HASH, KC_DLR , KC_ESC ,                      KC_PERC, CIRC, KC_AMPR, KC_ASTR, KC_EQL , XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, KC_LCTL, KC_LOPT, KC_LCMD, KC_PIPE, KC_ENT ,                      KC_LPRN, KC_RPRN,  KC_UP , KC_LBRC, KC_RBRC, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, KC_CUT , KC_COPY, KC_PSTE, XXXXXXX, KC_TAB ,                       KC_LT , KC_LEFT, KC_DOWN, KC_RGHT,  KC_GT , XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                         MO(_FCT), KC_LSFT, KC_BSPC,    XXXXXXX, XXXXXXX, XXXXXXX
                                      //`--------------------------'  `--------------------------'
  ),

//   [_SYM] = LAYOUT_split_3x6_3(
//   //,-----------------------------------------------------.                    ,-----------------------------------------------------.
//       XXXXXXX, KC_EXLM,  KC_AT , KC_HASH, KC_DLR , KC_PERC,                      KC_CIRC, KC_LCBR, KC_RCBR,  KC_LT ,  KC_GT , XXXXXXX,
//   //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
//       XXXXXXX, KC_LSFT, KC_LOPT, KC_LCMD, KC_BTN1, KC_BTN2,                      KC_AMPR, KC_LPRN, KC_RPRN, KC_LBRC, KC_RBRC, XXXXXXX,
//   //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
//       XXXXXXX, KC_TILD, KC_CUT , KC_COPY, KC_PSTE, KC_GRV ,                      KC_ASTR, KC_LEFT, KC_DOWN,  KC_UP , KC_RGHT, XXXXXXX,
//   //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
//                                           XXXXXXX, XXXXXXX, XXXXXXX,    KC_SPC ,MO(_NUM), KC_TAB 
//                                       //`--------------------------'  `--------------------------'
//   ),

  [_NUM] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, XXXXXXX,_CTLnTAB,_CMDnTAB, _CMDnT , KC_ESC ,                      KC_PPLS,  KC_7  ,  KC_8  ,  KC_9  , KC_PAST, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, KC_LCTL, KC_LOPT, KC_LCMD, KC_BTN1, KC_ENT ,                       KC_0  ,  KC_4  ,  KC_5  ,  KC_6  , KC_PEQL, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, _CMDnX , _CMDnC , _CMDnV , KC_BTN2, KC_TAB ,                      KC_PMNS,  KC_1  ,  KC_2  ,  KC_3  , KC_PSLS, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX, KC_LSFT, KC_BSPC,    KC_PDOT, KC_SPC ,TO(_BSE)
                                      //`--------------------------'  `--------------------------'
  ),

  [_FCT] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_ESC ,                      XXXXXXX, KC_F9  , KC_F10 , KC_F11 , KC_F12 , XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, KC_LCTL, KC_LOPT, KC_LCMD, KC_LSFT, KC_ENT ,                      XXXXXXX, KC_F5  , KC_F6  , KC_F7  , KC_F8  , XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_TAB ,                      XXXXXXX, KC_F1  , KC_F2  , KC_F3  , KC_F4  , XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX
                                      //`--------------------------'  `--------------------------'
  ),
};

// // for "_NUM_TAB" key, I want layer "_NUM" to be activated right when the key is pressed
// // but if no other key is pressed, I want KC_TAB to be sent
// // uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
// //     switch (keycode) {
// //         case _NUM_TAB:
// //             return 5;
// //         default:
// //             return TAPPING_TERM;
// //     }
// // }
// // bool get_retro_tapping(uint16_t keycode, keyrecord_t *record) {
// //     switch (keycode) {
// //         case _NUM_TAB:
// //             return true;
// //         default:
// //             return false;
// //     }
// // }

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  
    switch (keycode) {
        case KC_PDOT:
            if (get_mods() & MOD_BIT(KC_LSFT)) {
                if (record->event.pressed) {
                    unregister_code(KC_LSFT);
                    register_code(KC_COMM);
                    unregister_code(KC_COMM);
                    register_code(KC_LSFT);
                    return false;
                } else {
                    return false;
                }
            }
          break;
        case KC_QUOT:
            if (record->event.pressed) {
                register_code(KC_QUOT);
                unregister_code(KC_QUOT);
                register_code(KC_SPC);
                unregister_code(KC_SPC);
                return false;
            } else {
                return false;
            }
          break;
        case KC_GRV:
            if (record->event.pressed) {
                register_code(KC_GRV);
                unregister_code(KC_GRV);
                register_code(KC_SPC);
                unregister_code(KC_SPC);
                return false;
            } else {
                return false;
            }
          break;
        case TILDE:
            if (record->event.pressed) {
                register_code(KC_LSFT);
                register_code(KC_GRV);
                unregister_code(KC_GRV);
                unregister_code(KC_LSFT);
                register_code(KC_SPC);
                unregister_code(KC_SPC);
                return false;
            } else {
                return false;
            }
          break;
        case DQUOT:
            if (record->event.pressed) {
                register_code(KC_LSFT);
                register_code(KC_QUOT);
                unregister_code(KC_QUOT);
                unregister_code(KC_LSFT);
                register_code(KC_SPC);
                unregister_code(KC_SPC);
                return false;
            } else {
                return false;
            }
          break;
        case CIRC:
            if (record->event.pressed) {
                register_code(KC_LSFT);
                register_code(KC_6);
                unregister_code(KC_6);
                unregister_code(KC_LSFT);
                register_code(KC_SPC);
                unregister_code(KC_SPC);
                return false;
            } else {
                return false;
            }
          break;




    // _ACE
    // _GRA
    // _GRE
    // _GRU
    // _CIA
    // _CIE
    // _CII
    // _CIO
    // _CIU
    // _DIA
    // _DIE
    // _DII
    // _DIN
    // _DIO
    // _DIU
    // _CEC
    // _TIN
    // _EUR
  }
  return true;
}
