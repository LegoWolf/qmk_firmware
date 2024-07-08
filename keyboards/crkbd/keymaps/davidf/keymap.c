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

typedef enum {
    LAYER_BASE,
    LAYER_SUPER,
    LAYER_FUNC,
    LAYER_NAV,
    LAYER_NUM
} custom_layers_t;

typedef enum {
    WIN,
    MAC
} os_modes_t;

typedef enum {
#ifdef VIA_ENABLE
    KC_OSMODE = QK_KB_0,
#else
    KC_OSMODE = SAFE_RANGE,
#endif
    KC_VERTICAL_BAR,
} custom_keycodes_t;

#define KC_VBAR KC_VERTICAL_BAR 
#define MAX_LAYERS (LAYER_NUM + 1)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [LAYER_BASE] = LAYOUT_split_3x6_3(
  //,----------------+------------+----------------+----------------+----------------+-----------------.  ,-----------------+------------------+------------------+----------------+-----------------+----------------.
      KC_ESCAPE,       KC_Q,        KC_W,            KC_E,            KC_R,            KC_T,                KC_Y,             KC_U,              KC_I,              KC_O,            KC_P,             KC_MINUS,
  //|----------------|------------|----------------|----------------|----------------|-----------------|  |-----------------|------------------|------------------|----------------|-----------------|----------------|
      MO(LAYER_SUPER), KC_A,        KC_S,            KC_D,            KC_F,            KC_G,                KC_H,             KC_J,              KC_K,              KC_L,            KC_SCLN,          MO(LAYER_SUPER),
  //|----------------|------------|----------------|----------------|----------------|-----------------|  |-----------------|------------------|------------------|----------------|-----------------|----------------|
      OSM(MOD_LSFT),   KC_Z,        KC_X,            KC_C,            KC_V,            KC_B,                KC_N,             KC_M,              KC_COMMA,          KC_DOT,          KC_SLASH,         OSM(MOD_RSFT),
  //`----------------+------------+----------------|----------------|----------------|-----------------|  |-----------------|------------------|------------------|----------------+-----------------+----------------,
                                                     TT(LAYER_NAV),   KC_BSPC,         LCTL_T(KC_TAB),      KC_ENTER,         KC_SPACE,          KC_RALT
  //                                               `----------------+----------------+-----------------,  `-----------------+------------------+------------------,                                                    
  ),

  [LAYER_SUPER] = LAYOUT_split_3x6_3(
  //,----------------+------------+----------------+----------------+----------------+-----------------.  ,-----------------+------------------+------------------+----------------+-----------------+----------------.
      _______,         KC_BSLS,     XXXXXXX,         KC_QUOTE,        XXXXXXX,         KC_INSERT,           KC_DELETE,        KC_NUBS,           KC_GRAVE,          KC_LBRC,         KC_VBAR,          KC_EQUAL,
  //|----------------|------------|----------------|----------------|----------------|-----------------|  |-----------------|------------------|------------------|----------------|-----------------|----------------|
      XXXXXXX,         KC_1,        KC_2,            KC_3,            KC_4,            KC_5,                KC_6,             KC_7,              KC_8,              KC_9,            KC_0,             XXXXXXX,
  //|----------------|------------|----------------|----------------|----------------|-----------------|  |-----------------|------------------|------------------|----------------|-----------------|----------------|
      KC_CAPS,         XXXXXXX,     XXXXXXX,         KC_RBRC,         XXXXXXX,         XXXXXXX,             KC_APPLICATION,   OSM(MOD_LGUI),     OSM(MOD_LCTL),     OSM(MOD_LALT),   OSL(LAYER_FUNC),  _______,
  //`----------------+------------+----------------|----------------|----------------|-----------------|  |-----------------|------------------|------------------|----------------+-----------------+----------------,
                                                     TT(LAYER_NUM),   _______,         _______,             KC_OSMODE,        _______,           _______
  //                                               `----------------+----------------+-----------------,  `-----------------+------------------+------------------,                                                    
  ),

  [LAYER_FUNC] = LAYOUT_split_3x6_3(
  //,----------------+------------+----------------+----------------+----------------+-----------------.  ,-----------------+------------------+------------------+----------------+-----------------+----------------.
      XXXXXXX,         KC_F11,      KC_F12,          KC_F13,          KC_F14,          KC_F15,              KC_F16,           KC_F17,            KC_F18,            KC_F19,          KC_F20,           XXXXXXX,
  //|----------------|------------|----------------|----------------|----------------|-----------------|  |-----------------|------------------|------------------|----------------|-----------------|----------------|
      _______,         KC_F1,       KC_F2,           KC_F3,           KC_F4,           KC_F5,               KC_F6,            KC_F7,             KC_F8,             KC_F9,           KC_F10,           _______,
  //|----------------|------------|----------------|----------------|----------------|-----------------|  |-----------------|------------------|------------------|----------------|-----------------|----------------|
      _______,         XXXXXXX,     XXXXXXX,         XXXXXXX,         XXXXXXX,         XXXXXXX,             KC_PAUSE,         KC_PSCR,           KC_LNUM,           KC_LSCR,         XXXXXXX,          _______,
  //`----------------+------------+----------------|----------------|----------------|-----------------|  |-----------------|------------------|------------------|----------------+-----------------+----------------,
                                                     XXXXXXX,         _______,         _______,             _______,          _______,           _______
  //                                               `----------------+----------------+-----------------,  `-----------------+------------------+------------------,                                                    
  ),

  [LAYER_NAV] = LAYOUT_split_3x6_3(
  //,----------------+------------+----------------+----------------+----------------+-----------------.  ,-----------------+------------------+------------------+----------------+-----------------+----------------.
      TT(LAYER_NAV),   XXXXXXX,     KC_HOME,         KC_UP,           KC_END,          KC_PGUP,             KC_PGUP,          KC_HOME,           KC_UP,             KC_END,          XXXXXXX,          XXXXXXX,
  //|----------------|------------|----------------|----------------|----------------|-----------------|  |-----------------|------------------|------------------|----------------|-----------------|----------------|
      _______,         XXXXXXX,     KC_LEFT,         KC_DOWN,         KC_RIGHT,        KC_PGDN,             KC_PGDN,          KC_LEFT,           KC_DOWN,           KC_RIGHT,        XXXXXXX,          _______,
  //|----------------|------------|----------------|----------------|----------------|-----------------|  |-----------------|------------------|------------------|----------------|-----------------|----------------|
      _______,         XXXXXXX,     OSM(MOD_LGUI),   OSM(MOD_LCTL),   OSM(MOD_LALT),   XXXXXXX,             XXXXXXX,          OSM(MOD_LGUI),     OSM(MOD_LCTL),     OSM(MOD_LALT),   XXXXXXX,          _______,
  //`----------------+------------+----------------|----------------|----------------|-----------------|  |-----------------|------------------|------------------|----------------+-----------------+----------------,
                                                     TT(LAYER_NAV),   _______,         _______,             _______,          _______,           _______
  //                                               `----------------+----------------+-----------------,  `-----------------+------------------+------------------,                                                    
  ),

  [LAYER_NUM] = LAYOUT_split_3x6_3(
  //,----------------+------------+----------------+----------------+----------------+-----------------.  ,-----------------+------------------+------------------+----------------+-----------------+----------------.
      TT(LAYER_NUM),   XXXXXXX,     KC_BRID,         XXXXXXX,         KC_BRIU,         KC_VOLU,             KC_KP_SLASH,      KC_KP_7,           KC_KP_8,           KC_KP_9,         KC_KP_PLUS,       XXXXXXX,
  //|----------------|------------|----------------|----------------|----------------|-----------------|  |-----------------|------------------|------------------|----------------|-----------------|----------------|
      XXXXXXX,         XXXXXXX,     KC_MPRV,         KC_MPLY,         KC_MNXT,         KC_VOLD,             KC_KP_0,          KC_KP_4,           KC_KP_5,           KC_KP_6,         KC_KP_MINUS,      XXXXXXX,
  //|----------------|------------|----------------|----------------|----------------|-----------------|  |-----------------|------------------|------------------|----------------|-----------------|----------------|
      XXXXXXX,         XXXXXXX,     XXXXXXX,         KC_MCTL,         KC_LPAD,         KC_MUTE,             KC_KP_ASTERISK,   KC_KP_1,           KC_KP_2,           KC_KP_3,         KC_KP_COMMA,      XXXXXXX,
  //`----------------+------------+----------------|----------------|----------------|-----------------|  |-----------------|------------------|------------------|----------------+-----------------+----------------,
                                                     TT(LAYER_NUM),   _______,         XXXXXXX,             KC_KP_ENTER,      KC_KP_EQUAL,       KC_KP_DOT
  //                                               `----------------+----------------+-----------------,  `-----------------+------------------+------------------,                                                    
  )
};

static os_modes_t os_mode = WIN;

#ifdef OLED_ENABLE

// All bitmaps below were converted from PNG to CPP code below using: https://javl.github.io/image2cpp/
// (Make sure to select draw mode "Vertical - 1 bit per pixel".)

#define SMALL_ICON_DIM 16
#define SMALL_ICON_SIZE 32
#define LARGE_ICON_SIZE 128
#define SHOW_GRAPHICS

typedef struct {
    os_modes_t os_mode;
    layer_state_t default_layer;
    layer_state_t layer;
    led_t leds;
    uint8_t mods;
} state_t;

static state_t current;
static bool force_render = true;

static bool is_windows( void ) {
    return (current.os_mode == WIN);
}

static void oled_render_logo(void) {
    static const char PROGMEM crkbd_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0xb4,
        0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0xd4,
        0};
    oled_write_P(crkbd_logo, false);
}

static void get_state( state_t *state ) {
    state->default_layer = get_highest_layer(default_layer_state);
    state->layer = get_highest_layer(layer_state);
    state->leds = host_keyboard_led_state();
    state->mods = get_mods() | get_oneshot_mods();
    state->os_mode = os_mode;
}

static bool has_state_changed( void ) {
    state_t state;
    get_state( &state );
    return (current.os_mode != state.os_mode) ||
        (current.leds.caps_lock != state.leds.caps_lock) ||
        (current.leds.num_lock != state.leds.num_lock) ||
        (current.leds.scroll_lock != state.leds.scroll_lock) ||
        (current.mods != state.mods) ||
        (current.default_layer != state.default_layer )
        || (current.layer != state.layer);     
}

static void update_state( void ) {
    get_state( &current );
    force_render = false;
}

#ifdef SHOW_GRAPHICS

// This graphical implementation displays the keyboard state on the left side OLED display as a series of icons.

static void oled_gfx_render_large_bitmap(int x, int y, const char *bitmap, bool enabled) {
    // 'blank', 32x32px
    static const char bitmap_blank [] PROGMEM = {
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
    };

    bitmap = enabled ? bitmap : bitmap_blank;
    oled_set_cursor(x, y);
    oled_write_raw_P(bitmap, LARGE_ICON_SIZE);
}

static void oled_gfx_render_small_bitmap(int x, int y, const char *bitmap, bool enabled) {
    // 'blank', 16x16px
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

    const char *bitmap = is_windows() ? bitmap_windows : bitmap_apple;
    oled_gfx_render_large_bitmap(x, y, bitmap, true);
}

static void oled_gfx_render_layer_state(int x, int y) {
    // 'layer-base', 32x32px
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

    // 'layer-super', 32x32px
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

    // 'layer-function', 32x32px
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

    // 'layer-navigation', 32x32px
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

    // 'layer-game', 32x32px
    static const char bitmap_game[] PROGMEM = {
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0xf8, 0xfe, 0x1f, 0x1f, 0x1f, 0x03, 0x03, 0x03, 0x1f, 0x1f, 0x1f, 0xfe, 0xfe, 0xfe, 
        0xfe, 0xfe, 0xfe, 0x1f, 0x1f, 0x1f, 0xe3, 0xe3, 0xe3, 0x1f, 0x1f, 0x1f, 0xfe, 0xf8, 0x00, 0x00, 
        0x00, 0x00, 0x07, 0x3f, 0xff, 0xff, 0xff, 0xf8, 0xf8, 0x78, 0x3f, 0x1f, 0x1f, 0x0f, 0x0f, 0x07, 
        0x07, 0x0f, 0x0f, 0x1f, 0x1f, 0x3f, 0x78, 0xf8, 0xf8, 0xff, 0xff, 0xff, 0x3f, 0x03, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00
    };

    static const char* const bitmaps[] PROGMEM = {bitmap_base, bitmap_super, bitmap_function, bitmap_navigation, bitmap_game};
    bool valid = (0 <= current.layer && current.layer < MAX_LAYERS);
    const char *bitmap = valid ? (const char *)pgm_read_word(bitmaps + current.layer) : NULL;
    oled_gfx_render_large_bitmap(x, y, bitmap, valid);
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

    oled_gfx_render_small_bitmap(x, y, bitmap_caps_lock, current.leds.caps_lock);
    oled_gfx_render_small_bitmap(x + 3, y, bitmap_num_lock, current.leds.num_lock);
    oled_gfx_render_small_bitmap(x, y + 2, bitmap_scroll_lock, current.leds.scroll_lock);
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
    oled_gfx_render_small_bitmap(x, y, bitmap_gui, (current.mods & MOD_MASK_GUI));
    oled_gfx_render_small_bitmap(x + 3, y, bitmap_ctrl, (current.mods & MOD_MASK_CTRL));
    oled_gfx_render_small_bitmap(x, y + 2, bitmap_alt, (current.mods & MOD_MASK_ALT));
    oled_gfx_render_small_bitmap(x + 3, y + 2, bitmap_shift, (current.mods & MOD_MASK_SHIFT));
}

#else // SHOW_GRAPHICS

// This alternative implementation displays the keyboard states on the left side OLED display as a series of text labels.

void oled_render_os_mode(void) {
    oled_write_P(PSTR("   OS: "), false);
    oled_write_ln_P(is_windows() ? PSTR("Windows") : PSTR("Mac"), false);
}

void oled_render_layer_state(void) {
    static const char base[] PROGMEM = "Base";
    static const char super[] PROGMEM = "Super";
    static const char function[] PROGMEM = "Function";
    static const char navigation[] PROGMEM = "Navigation";
    static const char number[] PROGMEM = "Number";
    static const char * const names[] PROGMEM = {base, super, function, navigation, number};
    bool valid = (0 <= current.layer && current.layer < MAX_LAYERS);
    const char *name = valid ? (const char *)pgm_read_word(names + current.layer) : PSTR("Unknown");
    oled_write_P(PSTR("Layer: "), false);
    oled_write_ln_P(name, false);
}

void oled_render_leds(void) {
    static const char blank[] PROGMEM = "  ";
    oled_write_P(PSTR(" LEDs: "), false);
    oled_write_P(current.leds.caps_lock ? PSTR("L ") : blank, false);
    oled_write_P(current.leds.num_lock ? PSTR("N ") : blank, false);
    oled_write_P(current.leds.scroll_lock ? PSTR("S ") : blank, false);
    oled_advance_page(true);
}

void oled_render_mods(void) {
    static const char blank[] PROGMEM = "  ";
    oled_write_P(PSTR(" Mods: "), false);
    oled_write_P((current.mods & MOD_MASK_GUI) ? PSTR("O ") : blank, false);
    oled_write_P((current.mods & MOD_MASK_CTRL) ? PSTR("C ") : blank, false);
    oled_write_P((current.mods & MOD_MASK_ALT) ? PSTR("A ") : blank, false);
    oled_write_P((current.mods & MOD_MASK_SHIFT) ? PSTR("S ") : blank, false);
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

void emit_key_event(uint16_t keycode, keyrecord_t *record)
{
    if (record->event.pressed) {
        register_code16(keycode);
    } else {
        unregister_code16(keycode);
    }  
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_OSMODE:
            if (record->event.pressed) {
                // Switch OS mode.
                os_mode = (os_mode == WIN) ? MAC : WIN;
            }
            return false;

        case KC_VERTICAL_BAR:
              if (os_mode == MAC) {
                  // On the Mac CSA keyboard layout, vertical bar is just RALT+MINUS.
                  emit_key_event(RALT(KC_MINUS), record);
              } else if (record->event.pressed) {
                  // On the Windows CSA keyboard layout, vertical bar is unavailable.
                  // So we swap to US layout, type the vertical bar and swap back.
                  SEND_STRING(SS_LGUI(" ") SS_DELAY(100) "|" SS_LGUI(" "));
              }
            return false;

        case KC_NONUS_BACKSLASH:
            if (os_mode == MAC) {
                // Mac and Windows swap the placement of NUBS and GRAVE under CSA keyboard layout.
                emit_key_event(KC_GRAVE, record);
                return false;
            }
            break;

        case KC_GRAVE:
            if (os_mode == MAC) {
                // Mac and Windows swap the placement of NUBS and GRAVE under CSA keyboard layout.
                emit_key_event(KC_NONUS_BACKSLASH, record);
                return false;
            }
            break;

        case KC_SCROLL_LOCK:
            if (os_mode == MAC) {
                // Suppress scroll lock on Mac. It just gets confused.
                return false;
            }
            break;

        case LCTL_T(KC_TAB):
            if (os_mode == MAC && !record->tap.count) {
                // Change the LCTL_L(KC_TAB) key to LGUI_T(KC_TAB) on Mac.
                emit_key_event(KC_LGUI, record);
                return false;
            }
            break;
    }

    return true; // Process all other keycodes normally
}