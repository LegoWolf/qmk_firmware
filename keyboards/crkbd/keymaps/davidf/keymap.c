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

enum custom_layers {
    LAYER_BASE_MAC,
    LAYER_BASE_WIN,
    LAYER_SUPER_MAC,
    LAYER_SUPER_WIN,
    LAYER_FUNCTION,
    LAYER_NAVIGATION,
    LAYER_NUMBER_MAC,
    LAYER_NUMBER_WIN
};

enum custom_keycodes {
#ifdef VIA_ENABLE
    KC_VBAR_MACRO = USER00,
#else
    KC_VBAR_MACRO = SAFE_RANGE,
#endif
    KC_MISSION_CONTROL,
    KC_LAUNCHPAD
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [LAYER_BASE_MAC] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,  KC_ESC,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI,   MO(1),  KC_SPC,     KC_ENT,   MO(2), KC_RALT
                                      //`--------------------------'  `--------------------------'

  ),

  [LAYER_BASE_WIN] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,  KC_ESC,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI,   MO(1),  KC_SPC,     KC_ENT,   MO(2), KC_RALT
                                      //`--------------------------'  `--------------------------'

  ),

  [LAYER_SUPER_MAC] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_LEFT, KC_DOWN,   KC_UP,KC_RIGHT, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI, _______,  KC_SPC,     KC_ENT,   MO(3), KC_RALT
                                      //`--------------------------'  `--------------------------'
  ),

  [LAYER_SUPER_WIN] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_LEFT, KC_DOWN,   KC_UP,KC_RIGHT, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI, _______,  KC_SPC,     KC_ENT,   MO(3), KC_RALT
                                      //`--------------------------'  `--------------------------'
  ),

  [LAYER_FUNCTION] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,                      KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_MINS,  KC_EQL, KC_LBRC, KC_RBRC, KC_BSLS,  KC_GRV,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE, KC_TILD,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI,   MO(3),  KC_SPC,     KC_ENT, _______, KC_RALT
                                      //`--------------------------'  `--------------------------'
  ),

  [LAYER_NAVIGATION] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI, _______,  KC_SPC,     KC_ENT, _______, KC_RALT
                                      //`--------------------------'  `--------------------------'
  ),

  [LAYER_NUMBER_MAC] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI, _______,  KC_SPC,     KC_ENT, _______, KC_RALT
                                      //`--------------------------'  `--------------------------'
  ),

  [LAYER_NUMBER_WIN] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI, _______,  KC_SPC,     KC_ENT, _______, KC_RALT
                                      //`--------------------------'  `--------------------------'
  )
};

// All bitmaps were converted from PNG to CPP code below using: https://javl.github.io/image2cpp/

#define GFX_FRAME_DURATION 200  // Don't redraw graphics more frquently than this number of ms.
#define SMALL_ICON_DIM 16
#define SMALL_ICON_SIZE 32
#define SHOW_GRAPHICS

static uint8_t current_leds, current_mods;
static layer_state_t current_default_layer, current_layer;
static bool force_render = true;

#ifdef OLED_ENABLE

static bool is_windows( void ) {
  return (current_default_layer == LAYER_BASE_WIN);
}

static void oled_render_logo(void) {
    static const char PROGMEM crkbd_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0xb4,
        0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0xd4,
        0};
    oled_write_P(crkbd_logo, false);
}

static bool has_state_changed( void ) {
  return (current_default_layer != get_highest_layer(default_layer_state)) ||
    (current_layer != get_highest_layer(layer_state)) ||
    (current_leds != host_keyboard_leds()) ||
    (current_mods != (get_mods() | get_oneshot_mods()));
}

static void update_state( void ) {
    current_default_layer = get_highest_layer(default_layer_state);
    current_layer = get_highest_layer(layer_state);
    current_leds = host_keyboard_leds();
    current_mods = get_mods() | get_oneshot_mods();
    force_render = false;
}

#ifdef SHOW_GRAPHICS

static void oled_gfx_render_os_mode(int x, int y) {
    // 'apple logo', 32x32px
    static const char bitmap_apple [] PROGMEM = {
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0xe0, 0xf8, 0x7c, 0x7c, 0x1e, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0xc0, 0xf0, 0xfc, 0xfe, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0xfe, 
        0xfe, 0xfe, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0x1e, 0x0c, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x0f, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
        0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0xf0, 0xc0, 0xc0, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x07, 0x1f, 0x3f, 0x3f, 0x7f, 0x7f, 0x7f, 0x7f, 0x3f, 0x3f, 
        0x3f, 0x3f, 0x3f, 0x7f, 0x7f, 0x7f, 0x7f, 0x3f, 0x3f, 0x0f, 0x07, 0x01, 0x00, 0x00, 0x00, 0x00
    };

    // 'windows logo', 32x32px
    static const char bitmap_windows [] PROGMEM = {
        0x00, 0x00, 0xfc, 0xfc, 0xfc, 0xfc, 0xfc, 0xfc, 0xfc, 0xfc, 0xfc, 0xfc, 0xfc, 0xfc, 0xfc, 0x00, 
        0x00, 0xfc, 0xfc, 0xfc, 0xfc, 0xfc, 0xfc, 0xfc, 0xfc, 0xfc, 0xfc, 0xfc, 0xfc, 0xfc, 0x00, 0x00, 
        0x00, 0x00, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x00, 
        0x00, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x00, 0x00, 
        0x00, 0x00, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0x00, 
        0x00, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0x00, 0x00, 
        0x00, 0x00, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x00, 
        0x00, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x00, 0x00
    };    

    oled_set_cursor(x, y);
    if (is_windows()) {
        oled_write_raw_P(bitmap_windows, sizeof(bitmap_windows));
    } else {
        oled_write_raw_P(bitmap_apple, sizeof(bitmap_apple));
    } 
}

static void oled_gfx_render_layer_state(int x, int y) {
    // 'base layer', 32x32px
    static const char bitmap_base [] PROGMEM = {
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc0, 0xc0, 
        0xc0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0xfc, 0xff, 0x1f, 0x01, 
        0x1f, 0xff, 0xfc, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xf8, 0xff, 0x3f, 0x1f, 0x18, 0x18, 0x18, 
        0x18, 0x18, 0x1f, 0x7f, 0xff, 0xf8, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0x07, 0x07, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x03, 0x07, 0x07, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
    };

    // 'super layer', 32x32px
    static const char bitmap_super[] PROGMEM = {
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xe0, 0xf0, 0x70, 0x70, 0x70, 
        0x70, 0x70, 0x70, 0xf0, 0xe0, 0xc0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0xff, 0xff, 0xff, 0xc1, 0x80, 0x80, 0x80, 
        0x80, 0x80, 0x80, 0x00, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x81, 0xe3, 0xff, 0xff, 0x3f, 0x01, 0x01, 
        0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0c, 0x0e, 0x0f, 0x0f, 0x0f, 0x07, 0x07, 0x07, 0x07, 
        0x0f, 0x0e, 0x0e, 0x0e, 0x0e, 0x0e, 0x0f, 0x07, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
    };

    // 'function key layer', 32x32px
    static const char bitmap_function[] PROGMEM = {
        0x00, 0x00, 0x00, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0xf0, 0xf0, 0xe0, 0xe0, 0x70, 0x30, 0x30, 0x70, 0xf0, 0xe0, 0xe0, 0x80, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x00, 0x00, 
        0x00, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x07, 0x07, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x07, 0x07, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x07, 0x07, 0x00, 0x00, 0x00
    };

    // 'navigation layer', 32x32px
        static const char bitmap_navigation[] PROGMEM = {
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc0, 0xe0, 0xf0, 
        0xf0, 0xe0, 0xc0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x80, 0xc0, 0xe0, 0xf0, 0xb0, 0x80, 0x80, 0x80, 0x81, 0x01, 0x00, 0x1f, 
        0x1f, 0x00, 0x01, 0x81, 0x80, 0x80, 0x80, 0xb0, 0xf0, 0xe0, 0xc0, 0x80, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x01, 0x03, 0x07, 0x0f, 0x0d, 0x01, 0x01, 0x01, 0x81, 0x80, 0x00, 0xf8, 
        0xf8, 0x00, 0x80, 0x81, 0x01, 0x01, 0x01, 0x0d, 0x0f, 0x07, 0x03, 0x01, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x03, 0x07, 0x0f, 
        0x0f, 0x07, 0x03, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
    };

    // 'number layer', 32x32px
        static const char bitmap_number[] PROGMEM = {
        0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc0, 0xe0, 0x70, 0x30, 0x30, 0x30, 0x70, 0x70, 0xe0, 0xc0, 
        0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x1e, 0x7f, 0xff, 0xe0, 0xc0, 0x80, 0x80, 0x80, 0x80, 0xc0, 0xe0, 0xff, 
        0xff, 0xfe, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xc0, 0xc0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xc1, 0xc1, 0xe1, 0xe1, 0x71, 0x71, 0x38, 0x1f, 0x0f, 
        0x07, 0x00, 0x00, 0x80, 0x80, 0x80, 0xff, 0xff, 0x01, 0x03, 0x07, 0x0e, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x07, 0x0f, 0x0f, 0x0f, 0x0f, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
    };

    oled_set_cursor(x, y);
    switch (current_layer) {
        case LAYER_NUMBER_MAC:
        case LAYER_NUMBER_WIN:
            oled_write_raw_P(bitmap_number, sizeof(bitmap_number));
            break;

        case LAYER_NAVIGATION:
            oled_write_raw_P(bitmap_navigation, sizeof(bitmap_navigation));
            break;

        case LAYER_SUPER_MAC:
        case LAYER_SUPER_WIN:
            oled_write_raw_P(bitmap_super, sizeof(bitmap_super));
            break;

        case LAYER_BASE_MAC:
        case LAYER_BASE_WIN:
            oled_write_raw_P(bitmap_base, sizeof(bitmap_base));
            break;

        case LAYER_FUNCTION:
            oled_write_raw_P(bitmap_function, sizeof(bitmap_function));
            break;
    }
}

static void oled_gfx_render_small_bitmap(int x, int y, const char *bitmap, bool enabled) {
    // 'led-caps-lock', 16x16px
    static const char bitmap_blank [] PROGMEM = {
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 
    };

    uint8_t i, n;
    bitmap = enabled ? bitmap : bitmap_blank;

    for(i = 0, n = 0; n < SMALL_ICON_SIZE; i++, n += SMALL_ICON_DIM) {
        oled_set_cursor(x, y + i);
        oled_write_raw_P(bitmap + n, SMALL_ICON_DIM);
    }
}

static void oled_gfx_render_leds(int x, int y) {
    // 'led-caps-lock', 16x16px
    static const char bitmap_caps_lock [] PROGMEM = {
        0x00, 0x00, 0xf8, 0xfc, 0x3c, 0x1c, 0x0c, 0x04, 0x04, 0x0c, 0x1c, 0x3c, 0xfc, 0xf8, 0x00, 0x00, 
        0x00, 0x00, 0x1f, 0x3f, 0x3f, 0x3f, 0x24, 0x24, 0x24, 0x24, 0x3f, 0x3f, 0x3f, 0x1f, 0x00, 0x00
    };

    // 'led-num-lock', 16x16px
    static const char bitmap_num_lock [] PROGMEM = {
        0x00, 0x00, 0xf8, 0xfc, 0xfc, 0x0c, 0x04, 0x64, 0x64, 0x04, 0x0c, 0xfc, 0xfc, 0xf8, 0x00, 0x00, 
        0x00, 0x00, 0x1f, 0x3f, 0x3f, 0x3f, 0x26, 0x26, 0x22, 0x30, 0x38, 0x3f, 0x3f, 0x1f, 0x00, 0x00
    };

    // 'led-scroll-lock', 16x16px
    static const char bitmap_scroll_lock [] PROGMEM = {
        0x00, 0x00, 0xf8, 0x7c, 0x3c, 0x3c, 0x4c, 0x04, 0x04, 0x4c, 0x3c, 0x3c, 0x7c, 0xf8, 0x00, 0x00, 
        0x00, 0x00, 0x1f, 0x3e, 0x3c, 0x3c, 0x32, 0x20, 0x20, 0x32, 0x3c, 0x3c, 0x3e, 0x1f, 0x00, 0x00
    };

    oled_gfx_render_small_bitmap(x, y, bitmap_caps_lock, (current_leds & (1 << USB_LED_CAPS_LOCK)));
    oled_gfx_render_small_bitmap(x + 3, y, bitmap_num_lock, (current_leds & (1 << USB_LED_NUM_LOCK)));
    oled_gfx_render_small_bitmap(x, y + 2, bitmap_scroll_lock, (current_leds & (1 << USB_LED_SCROLL_LOCK)));
}

static void oled_gfx_render_modes(int x, int y) {
    // 'mode-gui-apple', 16x16px
    static const char bitmap_gui_apple [] PROGMEM = {
        0x00, 0x18, 0x3c, 0x66, 0x66, 0xfc, 0xf8, 0x60, 0x60, 0xf8, 0xfc, 0x66, 0x66, 0x3c, 0x18, 0x00, 
        0x00, 0x18, 0x3c, 0x66, 0x66, 0x3f, 0x1f, 0x06, 0x06, 0x1f, 0x3f, 0x66, 0x66, 0x3c, 0x18, 0x00
    };

    // 'mode-gui-windows', 16x16px
    static const char bitmap_gui_windows [] PROGMEM = {
        0x00, 0x00, 0x7c, 0x7c, 0x7c, 0x7c, 0x7c, 0x00, 0x00, 0x7c, 0x7c, 0x7c, 0x7c, 0x7c, 0x00, 0x00, 
        0x00, 0x00, 0x3e, 0x3e, 0x3e, 0x3e, 0x3e, 0x00, 0x00, 0x3e, 0x3e, 0x3e, 0x3e, 0x3e, 0x00, 0x00
    };

    // 'mode-ctrl', 16x16px
    static const char bitmap_ctrl [] PROGMEM = {
        0x00, 0x00, 0x00, 0x00, 0x80, 0xc0, 0xe0, 0x70, 0x70, 0xe0, 0xc0, 0x80, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x06, 0x07, 0x03, 0x01, 0x00, 0x00, 0x00, 0x00, 0x01, 0x03, 0x07, 0x06, 0x00, 0x00
    };

    // 'mode-alt', 16x16px
    static const char bitmap_alt [] PROGMEM = {
        0x00, 0x00, 0x0c, 0x0c, 0x0c, 0x3c, 0xfc, 0xf0, 0xc0, 0x00, 0x0c, 0x0c, 0x0c, 0x0c, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x0f, 0x3f, 0x3c, 0x30, 0x30, 0x30, 0x00, 0x00
    };

    // 'mode-shift', 16x16px
    static const char bitmap_shift [] PROGMEM = {
        0x00, 0x00, 0x00, 0x00, 0xc0, 0xe0, 0xf0, 0xf8, 0xf8, 0xf0, 0xe0, 0xc0, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 0x1f, 0x1f, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
    };

    const char* bitmap_gui = is_windows() ? bitmap_gui_windows : bitmap_gui_apple;
    oled_gfx_render_small_bitmap(x, y, bitmap_gui, (current_mods & MOD_MASK_GUI));
    oled_gfx_render_small_bitmap(x + 3, y, bitmap_ctrl, (current_mods & MOD_MASK_CTRL));
    oled_gfx_render_small_bitmap(x, y + 2, bitmap_alt, (current_mods & MOD_MASK_ALT));
    oled_gfx_render_small_bitmap(x + 3, y + 2, bitmap_shift, (current_mods & MOD_MASK_SHIFT));
}

#else // SHOW_GRAPHICS

void oled_render_os_mode(void) {
    oled_write_P(PSTR("   OS: "), false);
    oled_write_ln_P(is_windows() ? PSTR("Windows") : PSTR("Mac"), false);
}

void oled_render_layer_state(void) {
    oled_write_P(PSTR("Layer: "), false);
    switch (current_layer) {
        case LAYER_NUMBER_MAC:
        case LAYER_NUMBER_WIN:
            oled_write_ln_P(PSTR("Number"), false);
            break;
        case LAYER_NAVIGATION:
            oled_write_ln_P(PSTR("Navigation"), false);
            break;
        case LAYER_FUNCTION:
            oled_write_ln_P(PSTR("Function"), false);
            break;
        case LAYER_SUPER_MAC:
        case LAYER_SUPER_WIN:
            oled_write_ln_P(PSTR("Super"), false);
            break;
        case LAYER_BASE_MAC:
        case LAYER_BASE_WIN:
            oled_write_ln_P(PSTR("Base"), false);
            break;
    }
}

void oled_render_leds(void) {
    oled_write_P(PSTR(" LEDs: "), false);
    oled_write_P((current_leds & (1 << USB_LED_CAPS_LOCK)) ? PSTR("L ") : PSTR("  "), false);
    oled_write_P((current_leds & (1 << USB_LED_NUM_LOCK)) ? PSTR("N ") : PSTR("  "), false);
    oled_write_P((current_leds & (1 << USB_LED_SCROLL_LOCK)) ? PSTR("S ") : PSTR("  "), false);
    oled_advance_page(true);
}

void oled_render_mods(void) {
    oled_write_P(PSTR(" Mods: "), false);
    oled_write_P((current_mods & MOD_MASK_GUI) ? PSTR("O ") : PSTR("  "), false);
    oled_write_P((current_mods & MOD_MASK_CTRL) ? PSTR("C ") : PSTR("  "), false);
    oled_write_P((current_mods & MOD_MASK_ALT) ? PSTR("A ") : PSTR("  "), false);
    oled_write_P((current_mods & MOD_MASK_SHIFT) ? PSTR("S ") : PSTR("  "), false);
    oled_advance_page(true);
}

#endif // SHOW_GRAPHICS

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

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master()) {
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  }
#ifdef SHOW_GRAPHICS
  return OLED_ROTATION_270;
#else
  return OLED_ROTATION_0;
#endif
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        if (force_render || has_state_changed()) {
          update_state();
#         ifdef SHOW_GRAPHICS
            oled_gfx_render_os_mode(0, 0);
            oled_gfx_render_layer_state(0, 4);
            oled_gfx_render_leds(0, 8);
            oled_gfx_render_modes(0, 12);
#         else
            oled_render_os_mode();
            oled_render_layer_state();
            oled_render_leds();
            oled_render_mods();
#         endif
        }

    } else {
        oled_render_logo();
    }
    return false;
}

void keyboard_post_init_user( void ) {
  update_state();
}

#endif // OLED_ENABLE

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_MISSION_CONTROL:
            host_consumer_send(record->event.pressed ? 0x29F : 0);
            return false; // Skip all further processing of this key
        case KC_LAUNCHPAD:
            host_consumer_send(record->event.pressed ? 0x2A0 : 0);
            return false; // Skip all further processing of this key
        case KC_VBAR_MACRO:
            if (record->event.pressed) {
                SEND_STRING(SS_LGUI(" ") SS_DELAY(100) "|" SS_LGUI(" "));
            }
            return false; // Skip all further processing of this key          
    }
    return true; // Process all other keycodes normally
}