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
#include <stdio.h>

// hold/press keys
#define _CTL_A  LCTL_T(KC_A)
#define _CTL_GRA  LCTL_T(_GRA)
#define _CTL_U  LCTL_T(KC_U)
#define _OPT_R  LOPT_T(KC_R)
#define _OPT_I  LOPT_T(KC_I)
#define _OPT_UDS  LOPT_T(KC_UNDS)
#define _CMD_S  LCMD_T(KC_S)
#define _CMD_E  LCMD_T(KC_E)
#define _CMD_MNS  LCMD_T(KC_MINS)
// combos
#define _CTLnTAB  LCTL(KC_TAB)
#define _CTLnGRV  LCTL(KC_GRV)
#define _CMDnTAB  LCMD(KC_TAB)
#define _CMDnT  LCMD(KC_T)
#define _CMDnR  LCMD(KC_R)
#define _CMDnX  LCMD(KC_X)
#define _CMDnC  LCMD(KC_C)
#define _CMDnV  LCMD(KC_V)

enum my_keycodes {
    // accute accents
    _ACE = SAFE_RANGE,
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
    _DIO,
    _DIU,
    // cedilla
    _CEC,
    // e in o
    _OE,
    //tilde
    _TIN,
    // euro
    _EUR
};

enum layers {
  _MOD,
  _STD,
  _BSE,
  _SYM,
  _NUM,
  _FCT,
  _MSE,
  _LNG
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_MOD] = LAYOUT_split_3x5_3(
  //,--------------------------------------------.                    ,--------------------------------------------.
        KC_Q ,   KC_W ,   KC_F ,   KC_P ,   KC_B ,                        KC_J ,   KC_L ,   KC_O ,   KC_Y , KC_SCLN,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
      _CTL_A , _OPT_R , _CMD_S ,   KC_T ,   KC_G ,                        KC_H ,   KC_N , _CMD_E , _OPT_I , _CTL_U ,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
        KC_Z ,   KC_X ,   KC_C ,   KC_D ,   KC_V ,                        KC_K ,   KC_M , KC_COMM,  KC_DOT, KC_SLSH,
  //|--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
                                TT(_NUM), KC_LSFT, KC_QUOT,   MO(_LNG), KC_SPC ,TT(_SYM)
                             //`--------------------------'  `--------------------------'
  ),
  [_STD] = LAYOUT_split_3x5_3(
  //,--------------------------------------------.                    ,--------------------------------------------.
        KC_Q ,   KC_W ,   KC_F ,   KC_P ,   KC_B ,                        KC_J ,   KC_L ,   KC_O ,   KC_Y , KC_SCLN,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
      KC_A , KC_R , KC_S ,   KC_T ,   KC_G ,                        KC_H ,   KC_N , KC_E , KC_I , KC_U ,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
        KC_Z ,   KC_X ,   KC_C ,   KC_D ,   KC_V ,                        KC_K ,   KC_M , KC_COMM,  KC_DOT, KC_SLSH,
  //|--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
                                TT(_NUM), KC_LSFT, KC_QUOT,   MO(_LNG), KC_SPC ,TT(_SYM)
                             //`--------------------------'  `--------------------------'
  ),
  [_BSE] = LAYOUT_split_3x5_3(
  //,--------------------------------------------.                    ,--------------------------------------------.
     _______ ,_______ ,_______ ,_______ ,_______ ,                     _______ ,_______ ,_______ ,_______ ,_______ ,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
     _______ ,_______ ,_______ ,_______ ,_______ ,                     _______ ,_______ ,_______ ,_______ ,_______ ,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
     _______ ,_______ ,_______ ,_______ ,_______ ,                     _______ ,_______ ,_______ ,_______ ,_______ ,
  //|--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
                                _______ ,_______ ,_______ ,   _______ ,_______ ,_______
                             //`--------------------------'  `--------------------------'
  ),

  [_LNG] = LAYOUT_split_3x5_3(
  //,--------------------------------------------.                    ,--------------------------------------------.
        _CIA , XXXXXXX, KC_UNDS, KC_TILD, XXXXXXX,                        _DIU ,   _CIU ,   _GRU ,   _DII ,   _DIO ,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
        _GRA , KC_LOPT, KC_MINS, KC_DQUO, XXXXXXX,                        _TIN ,   _GRE ,   _ACE ,   _CII ,   _CIO ,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
        _DIA , XXXXXXX,   _CEC , KC_GRV , XXXXXXX,                        _EUR ,   KC_M ,   _CIE ,   _DIE ,   _OE  ,
  //|--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
                                 KC_LCTL, KC_LSFT, KC_LCMD,    XXXXXXX, XXXXXXX, XXXXXXX
                             //`--------------------------'  `--------------------------'
  ),

  [_SYM] = LAYOUT_split_3x5_3(
  //,--------------------------------------------.                    ,--------------------------------------------.
      KC_EXLM,  KC_AT , KC_HASH, KC_DLR , KC_ESC ,                      KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_EQL ,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
      KC_LCTL, KC_LOPT, KC_LCMD, KC_PIPE, KC_ENT ,                      KC_LPRN, KC_RPRN,  KC_UP , KC_LBRC, KC_RBRC,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
     _CTLnGRV, XXXXXXX, XXXXXXX, KC_BSLS, KC_TAB ,                       KC_LT , KC_LEFT, KC_DOWN, KC_RGHT,  KC_GT ,
  //|--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
                                 KC_DEL , KC_LSFT, KC_BSPC,   TO(_BSE),MO(_FCT), XXXXXXX
                             //`--------------------------'  `--------------------------'
  ),

  [_NUM] = LAYOUT_split_3x5_3(
  //,--------------------------------------------.                    ,--------------------------------------------.
      _CMDnR ,_CTLnTAB,_CMDnTAB, _CMDnT , KC_ESC ,                      KC_PPLS,  KC_7  ,  KC_8  ,  KC_9  , KC_PEQL,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
      KC_LCTL, KC_LOPT, KC_LCMD, KC_BTN1, KC_ENT ,                      KC_PMNS,  KC_4  ,  KC_5  ,  KC_6  , KC_PDOT,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
      _CMDnX , _CMDnC , _CMDnV , KC_BTN2, KC_TAB ,                      KC_PAST,  KC_1  ,  KC_2  ,  KC_3  , KC_PSLS,
  //|--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
                               MO(_MSE), KC_LSFT, KC_BSPC,    TO(_BSE),  KC_0  , KC_SPC
                            //`--------------------------'  `--------------------------'
  ),

  [_MSE] = LAYOUT_split_3x5_3(
  //,-------------------------------------------.                    ,--------------------------------------------.
     XXXXXXX, KC_ACL0, KC_ACL1, KC_ACL2, KC_ESC ,                      XXXXXXX, KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R,
  //|-------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
     KC_LCTL, KC_LOPT, KC_LCMD, KC_BTN1, KC_ENT ,                      XXXXXXX, XXXXXXX, KC_MS_U, XXXXXXX, XXXXXXX,
  //|-------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
     XXXXXXX, XXXXXXX, XXXXXXX, KC_BTN2, KC_TAB ,                      XXXXXXX, KC_MS_L, KC_MS_D, KC_MS_R, XXXXXXX,
  //|-------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
                                XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, KC_LSFT, XXXXXXX
                            //`--------------------------'  `--------------------------'
  ),

  [_FCT] = LAYOUT_split_3x5_3(
  //,--------------------------------------------.                    ,--------------------------------------------.
     DF(_STD),DF(_MOD),CG_SWAP , XXXXXXX, KC_ESC ,                      XXXXXXX, KC_F9  , KC_F10 , KC_F11 , KC_F12 ,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
      KC_LCTL, KC_LOPT, KC_LCMD, KC_LSFT, KC_ENT ,                      XXXXXXX, KC_F5  , KC_F6  , KC_F7  , KC_F8  ,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_TAB ,                      XXXXXXX, KC_F1  , KC_F2  , KC_F3  , KC_F4  ,
  //|--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
                                 XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX
                             //`--------------------------'  `--------------------------'
  ),
};


uint8_t my_mods;
int my_accent;
uint16_t my_keycode;
enum layout {
    MAC_US = SAFE_RANGE,
    MAC_HEX
};
enum accents {
    _accent_aecu = SAFE_RANGE,
    _accent_grav,
    _accent_circ,
    _accent_diae,
    _accent_tild
};
int my_layout = MAC_US;

void accent_letter(int accent, uint16_t keycode, bool pressed, uint8_t my_mods, int layout) {
    if (pressed) {
        switch (accent) {
            case _accent_aecu:
                unregister_mods(MOD_MASK_SHIFT);
                add_oneshot_mods(MOD_MASK_ALT);
                tap_code(KC_E);
                set_mods(my_mods);
                break;
            case _accent_grav:
                unregister_mods(MOD_MASK_SHIFT);
                add_oneshot_mods(MOD_MASK_ALT);
                tap_code(KC_GRV);
                set_mods(my_mods);
                break;
            case _accent_circ:
                unregister_mods(MOD_MASK_SHIFT);
                add_oneshot_mods(MOD_MASK_ALT);
                tap_code(KC_I);
                set_mods(my_mods);
                break;
            case _accent_diae:
                unregister_mods(MOD_MASK_SHIFT);
                add_oneshot_mods(MOD_MASK_ALT);
                tap_code(KC_U);
                set_mods(my_mods);
                break;
            case _accent_tild:
                unregister_mods(MOD_MASK_SHIFT);
                add_oneshot_mods(MOD_MASK_ALT);
                tap_code(KC_N);
                set_mods(my_mods);
                break;
        }
        tap_code(keycode);
    }
}

void cedilla(bool pressed, uint8_t my_mods, int layout) {
    if (pressed) {
        add_oneshot_mods(MOD_MASK_ALT);
        tap_code(KC_C);
    }
}

void oe(bool pressed, uint8_t my_mods, int layout) {
    if (pressed) {
        add_oneshot_mods(MOD_MASK_ALT);
        tap_code(KC_Q);
    }
}

void euro(bool pressed, uint8_t my_mods, int layout) {
    if (pressed) {
        if (get_mods() & MOD_MASK_SHIFT) {
            unregister_mods(MOD_MASK_SHIFT);
            add_oneshot_mods(MOD_MASK_ALT);
            tap_code(KC_3);
        } else {
            add_oneshot_mods(MOD_MASK_SHIFT);
            add_oneshot_mods(MOD_MASK_ALT);
            tap_code(KC_2);
        }
        set_mods(my_mods);
    }
}
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    my_mods = get_mods();

    switch (keycode) {
        case _ACE:
          accent_letter(_accent_aecu, KC_E, record->event.pressed, my_mods, my_layout);
          break;
        case _GRA:
          accent_letter(_accent_grav, KC_A, record->event.pressed, my_mods, my_layout);
          break;
        case _GRE:
          accent_letter(_accent_grav, KC_E, record->event.pressed, my_mods, my_layout);
          break;
        case _GRU:
          accent_letter(_accent_grav, KC_U, record->event.pressed, my_mods, my_layout);
          break;
        case _CIA:
          accent_letter(_accent_circ, KC_A, record->event.pressed, my_mods, my_layout);
          break;
        case _CIE:
          accent_letter(_accent_circ, KC_E, record->event.pressed, my_mods, my_layout);
          break;
        case _CII:
          accent_letter(_accent_circ, KC_I, record->event.pressed, my_mods, my_layout);
          break;
        case _CIO:
          accent_letter(_accent_circ, KC_O, record->event.pressed, my_mods, my_layout);
          break;
        case _CIU:
          accent_letter(_accent_circ, KC_U, record->event.pressed, my_mods, my_layout);
          break;
        case _DIA:
          accent_letter(_accent_diae, KC_A, record->event.pressed, my_mods, my_layout);
          break;
        case _DIE:
          accent_letter(_accent_diae, KC_E, record->event.pressed, my_mods, my_layout);
          break;
        case _DII:
          accent_letter(_accent_diae, KC_I, record->event.pressed, my_mods, my_layout);
          break;
        case _DIO:
          accent_letter(_accent_diae, KC_O, record->event.pressed, my_mods, my_layout);
          break;
        case _DIU:
          accent_letter(_accent_diae, KC_U, record->event.pressed, my_mods, my_layout);
          break;
        case _CEC:
          cedilla(record->event.pressed, my_mods, my_layout);
          break;
        case _TIN:
          accent_letter(_accent_tild, KC_N, record->event.pressed, my_mods, my_layout);
          break;
        case _EUR:
          euro(record->event.pressed, my_mods, my_layout);
          break;
        case _OE:
          oe(record->event.pressed, my_mods, my_layout);
          break;
        case KC_PDOT:
            if (my_mods & MOD_BIT(KC_LSFT)) {
                if (record->event.pressed) {
                    unregister_mods(MOD_MASK_SHIFT);
                    tap_code(KC_COMM);
                    set_mods(my_mods);
                    return false;
                } else {
                    return false;
                }
            }
          break;
        case KC_QUOT:
            if (record->event.pressed) {
                unregister_mods(MOD_MASK_SHIFT);
                register_code(KC_QUOT);
                set_mods(my_mods);
                return false;
            }
          break;
        case KC_GRV:
            if (record->event.pressed) {
                unregister_mods(MOD_MASK_SHIFT);
                register_code(KC_GRV);
                set_mods(my_mods);
                return false;
            }
          break;
        case KC_BSLS:
            if (record->event.pressed) {
                unregister_mods(MOD_MASK_SHIFT);
                register_code(KC_BSLS);
                set_mods(my_mods);
                return false;
            }
          break;
        case KC_MINS:
            if (record->event.pressed) {
                unregister_mods(MOD_MASK_SHIFT);
                register_code(KC_MINS);
                set_mods(my_mods);
                return false;
            }
          break;
    }
    return true;
}
