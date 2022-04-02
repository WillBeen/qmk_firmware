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
#define NUMB_TAB  LT(NUMB,KC_TAB)
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


// layers
#define BASE 0
#define SYMB 1
#define NUMB 2
#define FNCT 3
#define LANG 4

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [BASE] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_ESC ,   KC_Q ,   KC_W ,   KC_F ,   KC_P ,   KC_B ,                        KC_J ,   KC_L ,   KC_U ,   KC_Y ,   KC_P , KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     MO(FNCT), _CTL_A , _OPT_R , _CMD_S ,   KC_T ,   KC_G ,                        KC_M ,   KC_N , _CMD_E , _OPT_I , _CTL_O , KC_QUOT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_DEL ,   KC_Z ,   KC_X ,   KC_C ,   KC_D ,   KC_V ,                        KC_K ,   KC_H , KC_COMM,  KC_DOT, KC_SLSH, KC_BSLS,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                        MO(SYMB), KC_LSFT , KC_ENT ,    KC_SPC ,MO(LANG),NUMB_TAB
                                      //`--------------------------'  `--------------------------'
  ),
  
  [LANG] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX,   _CIA , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                        _DIU ,   _CIU ,   _GRU ,   _DII ,   _DIO , XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX,   _GRA ,   _DIA , XXXXXXX,   _EUR , XXXXXXX,                        _CIE ,   _GRE ,   _ACE ,   _CII ,   _CIO , XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX,   _CEC , XXXXXXX, XXXXXXX,                      XXXXXXX,   _TIN ,   _DIE , XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LSFT, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX
                                      //`--------------------------'  `--------------------------'
  ),

  [SYMB] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_ESC , KC_EXLM,  KC_AT , KC_HASH, KC_DLR , KC_PERC,                      KC_CIRC, KC_LCBR, KC_RCBR,  KC_LT ,  KC_GT , KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL, KC_LSFT, KC_LOPT, KC_LCMD, KC_BTN1, KC_BTN2,                      KC_AMPR, KC_LPRN, KC_RPRN, KC_LBRC, KC_RBRC, KC_MINS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_DEL , KC_TILD, KC_CUT , KC_COPY, KC_PSTE, KC_GRV ,                      KC_ASTR, KC_LEFT, KC_DOWN,  KC_UP , KC_RGHT, KC_EQL ,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX, XXXXXXX, XXXXXXX,    KC_SPC , KC_TAB ,MO(NUMB)
                                      //`--------------------------'  `--------------------------'
  ),

  [NUMB] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_ESC , KC_EXLM,  KC_AT , KC_HASH, KC_DLR , KC_PERC,                      KC_CIRC,  KC_7  ,  KC_8  ,  KC_9  , KC_PEQL, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL, KC_LSFT, KC_LOPT, KC_LCMD, KC_BTN1, KC_BTN2,                      KC_PPLS,  KC_4  ,  KC_5  ,  KC_6  ,  KC_0  , KC_PAST,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_DEL , KC_TILD, KC_CUT , KC_COPY, KC_PSTE, KC_GRV ,                      KC_PMNS,  KC_1  ,  KC_2  ,  KC_3  , KC_PDOT, KC_PSLS,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_TAB , KC_SPC , KC_ENT ,    XXXXXXX, XXXXXXX, XXXXXXX
                                      //`--------------------------'  `--------------------------'
  ),

  [FNCT] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, KC_F9  , KC_F10 , KC_F11 , KC_F12 , XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, KC_LOPT, KC_LCMD, KC_BTN1, KC_BTN2,                      XXXXXXX, KC_F5  , KC_F6  , KC_F7  , KC_F8  , XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, KC_F1  , KC_F2  , KC_F3  , KC_F4  , XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LCTL, KC_LSFT, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX
                                      //`--------------------------'  `--------------------------'
  ),
};

#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master()) {
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  }
  return rotation;
}

#define L_BASE 0
#define L_LOWER 2
#define L_RAISE 4
#define L_ADJUST 8

void oled_render_layer_state(void) {
    oled_write_P(PSTR("Layer: "), false);
    switch (layer_state) {
        case L_BASE:
            oled_write_ln_P(PSTR("Default"), false);
            break;
        case L_LOWER:
            oled_write_ln_P(PSTR("Lower"), false);
            break;
        case L_RAISE:
            oled_write_ln_P(PSTR("Raise"), false);
            break;
        case L_ADJUST:
        case L_ADJUST|L_LOWER:
        case L_ADJUST|L_RAISE:
        case L_ADJUST|L_LOWER|L_RAISE:
            oled_write_ln_P(PSTR("Adjust"), false);
            break;
    }
}


char keylog_str[24] = {};

const char code_to_name[60] = {
    ' ', ' ', ' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f',
    'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
    'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
    '1', '2', '3', '4', '5', '6', '7', '8', '9', '0',
    'R', 'E', 'B', 'T', '_', '-', '=', '[', ']', '\\',
    '#', ';', '\'', '`', ',', '.', '/', ' ', ' ', ' '};

void set_keylog(uint16_t keycode, keyrecord_t *record) {
  char name = ' ';
    if ((keycode >= QK_MOD_TAP && keycode <= QK_MOD_TAP_MAX) ||
        (keycode >= QK_LAYER_TAP && keycode <= QK_LAYER_TAP_MAX)) { keycode = keycode & 0xFF; }
  if (keycode < 60) {
    name = code_to_name[keycode];
  }

  // update keylog
  snprintf(keylog_str, sizeof(keylog_str), "%dx%d, k%2d : %c",
           record->event.key.row, record->event.key.col,
           keycode, name);
}

void oled_render_keylog(void) {
    oled_write(keylog_str, false);
}

void render_bootmagic_status(bool status) {
    /* Show Ctrl-Gui Swap options */
    static const char PROGMEM logo[][2][3] = {
        {{0x97, 0x98, 0}, {0xb7, 0xb8, 0}},
        {{0x95, 0x96, 0}, {0xb5, 0xb6, 0}},
    };
    if (status) {
        oled_write_ln_P(logo[0][0], false);
        oled_write_ln_P(logo[0][1], false);
    } else {
        oled_write_ln_P(logo[1][0], false);
        oled_write_ln_P(logo[1][1], false);
    }
}

void oled_render_logo(void) {
    static const char PROGMEM crkbd_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0xb4,
        0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0xd4,
        0};
    oled_write_P(crkbd_logo, false);
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        oled_render_layer_state();
        oled_render_keylog();
    } else {
        oled_render_logo();
    }
    return false;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    set_keylog(keycode, record);
  }
  return true;
}
#endif // OLED_ENABLE
