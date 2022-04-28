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
    _DIO,
    _DIU,
    // cedilla
    _CEC,
    //tilde
    _TIN,
    // e in o
    _OE,
    // euro
    _EUR,
    // mouse
    _WHUP,
    _WHDN,
    // os selection
    _MACOS,
    _ANDRO,
    _DEADKEY // mandatory for password typing
};

enum layers {
  _BSE,
  _SYM,
  _NUM,
  _FCT,
  _MSE,
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
      XXXXXXX,   _DIA , XXXXXXX,   _CEC , KC_BSLS, KC_TAB ,                        _EUR ,   KC_M ,   _CIE ,   _DIE ,   _OE  , XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LCTL, KC_LSFT, KC_LCMD,    QK_BOOT, XXXXXXX, XXXXXXX
                                      //`--------------------------'  `--------------------------'
  ),

  [_SYM] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, KC_EXLM,  KC_AT , KC_HASH, KC_DLR , KC_ESC ,                      KC_PERC, CIRC, KC_AMPR, KC_ASTR, KC_EQL , XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, KC_LCTL, KC_LOPT, KC_LCMD, KC_PIPE, KC_ENT ,                      KC_LPRN, KC_RPRN,  KC_UP , KC_LBRC, KC_RBRC, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, KC_CUT , KC_COPY, KC_PSTE, KC_BSLS, KC_TAB ,                       KC_LT , KC_LEFT, KC_DOWN, KC_RGHT,  KC_GT , XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                         MO(_FCT), KC_LSFT, KC_BSPC,    XXXXXXX, XXXXXXX, XXXXXXX
                                      //`--------------------------'  `--------------------------'
  ),

  [_NUM] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX,TO(_BSE), _CTLnTAB,_CMDnTAB, _CMDnT , KC_ESC ,                      KC_PPLS,  KC_7  ,  KC_8  ,  KC_9  , KC_PAST, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, KC_LCTL, KC_LOPT, KC_LCMD, KC_BTN1, KC_ENT ,                      KC_PDOT,  KC_4  ,  KC_5  ,  KC_6  , KC_PEQL, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, _CMDnX , _CMDnC , _CMDnV , KC_BTN2, KC_TAB ,                      KC_PMNS,  KC_1  ,  KC_2  ,  KC_3  , KC_PSLS, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                         MO(_MSE), KC_LSFT, KC_BSPC,     KC_0  , KC_SPC ,TO(_BSE)
                                      //`--------------------------'  `--------------------------'
  ),

  [_MSE] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, XXXXXXX, KC_ACL0, KC_ACL1, KC_ACL2, KC_ESC ,                      XXXXXXX, KC_WH_L,  _WHDN ,  _WHUP , KC_WH_R, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, KC_LCTL, KC_LOPT, KC_LCMD, KC_BTN1, KC_ENT ,                      XXXXXXX, XXXXXXX, KC_MS_U, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_BTN2, KC_TAB ,                      XXXXXXX, KC_MS_L, KC_MS_D, KC_MS_R, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, KC_LSFT, XXXXXXX
                                      //`--------------------------'  `--------------------------'
  ),

  [_FCT] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX,_DEADKEY, _ANDRO , _MACOS , XXXXXXX, KC_ESC ,                      XXXXXXX, KC_F9  , KC_F10 , KC_F11 , KC_F12 , XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, KC_LCTL, KC_LOPT, KC_LCMD, KC_LSFT, KC_ENT ,                      XXXXXXX, KC_F5  , KC_F6  , KC_F7  , KC_F8  , XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_TAB ,                      XXXXXXX, KC_F1  , KC_F2  , KC_F3  , KC_F4  , XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX
                                      //`--------------------------'  `--------------------------'
  ),
};


uint8_t my_mods;
enum ostype {
    OS_MAC = SAFE_RANGE,
    OS_AND,
    OS_DEA
};
enum accents {
    _accent_aecu = SAFE_RANGE,
    _accent_grav,
    _accent_circ,
    _accent_diae,
    _accent_tild
};
int my_ostype = OS_MAC;
void accent_letter(int accent, uint16_t keycode, bool pressed, uint8_t my_mods, int ostype) {
    if (pressed) {
        switch (accent) {
            case _accent_aecu:
                switch (ostype) {
                    case OS_MAC:
                        unregister_mods(MOD_MASK_SHIFT);
                        tap_code(KC_QUOT);
                        set_mods(my_mods);
                        break;
                    case OS_AND:
                        add_oneshot_mods(MOD_MASK_ALT);
                        tap_code(KC_E);
                        break;
                }
                break;
            case _accent_grav:
                switch (ostype) {
                    case OS_MAC:
                        unregister_mods(MOD_MASK_SHIFT);
                        tap_code(KC_GRV);
                        set_mods(my_mods);
                        break;
                    case OS_AND:
                        unregister_mods(MOD_MASK_SHIFT);
                        add_oneshot_mods(MOD_MASK_ALT);
                        tap_code(KC_GRV);
                        set_mods(my_mods);
                        break;
                    }
                break;
            case _accent_circ:
                switch (ostype) {
                    case OS_MAC:
                        add_oneshot_mods(MOD_MASK_SHIFT);
                        tap_code(KC_6);
                        break;
                    case OS_AND:
                        add_oneshot_mods(MOD_MASK_ALT);
                        tap_code(KC_I);
                        break;
                }
                break;
            case _accent_diae:
                switch (ostype) {
                    case OS_MAC:
                        add_oneshot_mods(MOD_MASK_SHIFT);
                        tap_code(KC_QUOT);
                        break;
                    case OS_AND:
                        add_oneshot_mods(MOD_MASK_ALT);
                        tap_code(KC_U);
                        break;
                }
                break;
            case _accent_tild:
                switch (ostype) {
                    case OS_MAC:
                        add_oneshot_mods(MOD_MASK_SHIFT);
                        tap_code(KC_GRV);
                        break;
                    case OS_AND:
                        add_oneshot_mods(MOD_MASK_ALT);
                        tap_code(KC_N);
                        break;
                }
                break;
        }
        tap_code(keycode);
    }
}
void cedilla(bool pressed, uint8_t my_mods, int ostype) {
    switch (ostype) {
        case OS_MAC:
            if (pressed) {
                add_oneshot_mods(MOD_MASK_ALT);
                tap_code(KC_C);
            }
            break;
        case OS_AND:
            if (pressed) {
                add_oneshot_mods(MOD_MASK_ALT);
                tap_code(KC_C);
            }
            break;
    }
}
void oe(bool pressed, uint8_t my_mods, int ostype) {
    switch (ostype) {
        case OS_MAC:
            if (pressed) {
                add_oneshot_mods(MOD_MASK_ALT);
                tap_code(KC_Q);
            }
            break;
        case OS_AND:
            if (pressed) {
                tap_code(KC_O);
                tap_code(KC_E);
            }
            break;
    }
}
void euro(bool pressed, uint8_t my_mods, int ostype) {
    switch (ostype) {
        case OS_MAC:
            if (pressed) {
                add_oneshot_mods(MOD_MASK_SHIFT);
                add_oneshot_mods(MOD_MASK_ALT);
                tap_code(KC_2);
            }
            break;
    }
}
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    my_mods = get_mods();
  
    switch (keycode) {
        case _MACOS:
            my_ostype = OS_MAC;
            break;
        case _ANDRO:
            my_ostype = OS_AND;
            break;
        case _DEADKEY:
            my_ostype = OS_DEA;
            break;
        case _ACE:
          accent_letter(_accent_aecu, KC_E, record->event.pressed, my_mods, my_ostype);
          break;
        case _GRA:
          accent_letter(_accent_grav, KC_A, record->event.pressed, my_mods, my_ostype);
          break;
        case _GRE:
          accent_letter(_accent_grav, KC_E, record->event.pressed, my_mods, my_ostype);
          break;
        case _GRU:
          accent_letter(_accent_grav, KC_U, record->event.pressed, my_mods, my_ostype);
          break;
        case _CIA:
          accent_letter(_accent_circ, KC_A, record->event.pressed, my_mods, my_ostype);
          break;
        case _CIE:
          accent_letter(_accent_circ, KC_E, record->event.pressed, my_mods, my_ostype);
          break;
        case _CII:
          accent_letter(_accent_circ, KC_I, record->event.pressed, my_mods, my_ostype);
          break;
        case _CIO:
          accent_letter(_accent_circ, KC_O, record->event.pressed, my_mods, my_ostype);
          break;
        case _CIU:
          accent_letter(_accent_circ, KC_U, record->event.pressed, my_mods, my_ostype);
          break;
        case _DIA:
          accent_letter(_accent_diae, KC_A, record->event.pressed, my_mods, my_ostype);
          break;
        case _DIE:
          accent_letter(_accent_diae, KC_E, record->event.pressed, my_mods, my_ostype);
          break;
        case _DII:
          accent_letter(_accent_diae, KC_I, record->event.pressed, my_mods, my_ostype);
          break;
        case _DIO:
          accent_letter(_accent_diae, KC_O, record->event.pressed, my_mods, my_ostype);
          break;
        case _DIU:
          accent_letter(_accent_diae, KC_U, record->event.pressed, my_mods, my_ostype);
          break;
        case _OE:
          oe(record->event.pressed, my_mods, my_ostype);
          break;
        case _CEC:
          cedilla(record->event.pressed, my_mods, my_ostype);
          break;
        case _TIN:
          accent_letter(_accent_tild, KC_N, record->event.pressed, my_mods, my_ostype);
          break;
        case _EUR:
          euro(record->event.pressed, my_mods, my_ostype);
          break;
        case _WHUP:
            if (my_ostype == OS_MAC) {
                if (record->event.pressed) {
                    register_code(KC_WH_D);
                    return false;
                } else {
                    unregister_code(KC_WH_D);
                    return false;
                }
            } else {
                if (record->event.pressed) {
                    register_code(KC_WH_U);
                    return false;
                } else {
                    unregister_code(KC_WH_U);
                    return false;
                }
            }
          break;
        case _WHDN:
            if (my_ostype == OS_MAC) {
                if (record->event.pressed) {
                    register_code(KC_WH_U);
                    return false;
                } else {
                    unregister_code(KC_WH_U);
                    return false;
                }
            } else {
                if (record->event.pressed) {
                    register_code(KC_WH_D);
                    return false;
                } else {
                    unregister_code(KC_WH_D);
                    return false;
                }
            }
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
                tap_code(KC_QUOT);
                set_mods(my_mods);
                if (my_ostype != OS_DEA) {
                    tap_code(KC_SPC);
                }
                return false;
            } else {
                return false;
            }
          break;
        case KC_GRV:
            if (record->event.pressed) {    
                unregister_mods(MOD_MASK_SHIFT);
                tap_code(KC_GRV);
                set_mods(my_mods);
                if (my_ostype != OS_DEA) {
                    tap_code(KC_SPC);
                }
                return false;
            } else {
                return false;
            }
          break;
        case KC_BSLS:
            if (record->event.pressed) {    
                unregister_mods(MOD_MASK_SHIFT);
                tap_code(KC_BSLS);
                set_mods(my_mods);
                return false;
            } else {
                return false;
            }
          break;
        case KC_MINS:
            if (record->event.pressed) {    
                unregister_mods(MOD_MASK_SHIFT);
                tap_code(KC_MINS);
                set_mods(my_mods);
                return false;
            } else {
                return false;
            }
          break;
        case CIRC:
            if (record->event.pressed) {
                add_oneshot_mods(MOD_MASK_SHIFT);
                tap_code(KC_6);
                if (my_ostype != OS_DEA) {
                    tap_code(KC_SPC);
                }
                return false;
            } else {
                return false;
            }
          break;
        case TILDE:
            if (record->event.pressed) {
                add_oneshot_mods(MOD_MASK_SHIFT);
                tap_code(KC_GRV);
                if (my_ostype != OS_DEA) {
                    tap_code(KC_SPC);
                }
                return false;
            } else {
                return false;
            }
          break;
        case DQUOT:
            if (record->event.pressed) {
                add_oneshot_mods(MOD_MASK_SHIFT);
                tap_code(KC_QUOT);
                if (my_ostype != OS_DEA) {
                    tap_code(KC_SPC);
                }
                return false;
            } else {
                return false;
            }
          break;
    }
    return true;
}
