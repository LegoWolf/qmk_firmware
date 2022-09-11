/*
Copyright 2022 David Falkner (falkner@martica.org)

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

typedef enum {
    LAYER_BASE,
    LAYER_SUPER,
    LAYER_FUNC
} custom_layers_t;

typedef enum {
    WIN,
    MAC
} os_modes_t;

typedef enum {
#ifdef VIA_ENABLE
    KC_OSMODE = USER00,
#else
    KC_OSMODE = SAFE_RANGE,
#endif
    KC_VERTICAL_BAR,
    KC_MISSION_CONTROL,
    KC_LAUNCHPAD,
    KC_GRV_REMAP,
    KC_GRV_REMAP_S,
    KC_NUBS_REMAP
} custom_keycodes_t;

#define KC_VBAR KC_VERTICAL_BAR 
#define KC_MSCT KC_MISSION_CONTROL 
#define KC_LCPD KC_LAUNCHPAD
#define MAX_LAYERS (LAYER_NUM + 1)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [LAYER_BASE] = LAYOUT_5x6_5(
  //,----------------+------------+----------------+----------------+----------------+-----------------.  ,-----------------+------------------+------------------+----------------+-----------------+----------------.
      KC_ESCAPE,       KC_1,        KC_2,            KC_3,            KC_4,            KC_5,                KC_6,             KC_7,              KC_8,              KC_9,            KC_0,             KC_MINUS,
  //|----------------|------------|----------------|----------------|----------------|-----------------|  |-----------------|------------------|------------------|----------------|-----------------|----------------|
      MO(LAYER_SUPER), KC_Q,        KC_W,            KC_E,            KC_R,            KC_T,                KC_Y,             KC_U,              KC_I,              KC_O,            KC_P,             MO(LAYER_SUPER),
  //|----------------|------------|----------------|----------------|----------------|-----------------|  |-----------------|------------------|------------------|----------------|-----------------|----------------|
      KC_EQL,          KC_A,        KC_S,            KC_D,            KC_F,            KC_G,                KC_H,             KC_J,              KC_K,              KC_L,            KC_SCOLON,        KC_QUOT,
  //|----------------|------------|----------------|----------------|----------------|-----------------|  |-----------------|------------------|------------------|----------------|-----------------|----------------|
      KC_LSHIFT,       KC_Z,        KC_X,            KC_C,            KC_V,            KC_B,                KC_N,             KC_M,              KC_COMMA,          KC_DOT,          KC_SLASH,         KC_RSHIFT,
  //`----------------+------------+----------------|----------------|----------------|-----------------|  |-----------------|------------------|------------------|----------------+-----------------+----------------,
                       KC_NUBS_REMAP, KC_BSLS,       KC_BSPC,         LCTL_T(KC_TAB),  KC_LALT,             KC_RALT,          KC_ENT,            KC_SPC,            KC_LBRC,         KC_RBRC,
  //                 `------------|----------------|----------------|----------------|-----------------|  |-----------------|------------------|------------------|----------------|-----------------,
                                                                      KC_LGUI,         KC_LCTRL,            KC_RCTRL,         MO(LAYER_FUNC)
  //                                                                `----------------+-----------------,  `-----------------+------------------,                                                    
  ),

  [LAYER_SUPER] = LAYOUT_5x6_5(
  //,----------------+------------+----------------+----------------+----------------+-----------------.  ,-----------------+------------------+------------------+----------------+-----------------+----------------.
      _______,         KC_BRID,     KC_BRIU,         KC_MSCT,         KC_LCPD,         _______,             XXXXXXX,          KC_MRWD,           KC_MPLY,           KC_MFFD,         KC_MUTE,          _______,
  //|----------------|------------|----------------|----------------|----------------|-----------------|  |-----------------|------------------|------------------|----------------|-----------------|----------------|
      _______,         KC_PSLS,     KC_P7,           KC_P8,           KC_P9,           KC_PMNS,             KC_INS,           KC_PGUP,           KC_UP,             KC_HOME,         KC_VBAR,          _______,
  //|----------------|------------|----------------|----------------|----------------|-----------------|  |-----------------|------------------|------------------|----------------|-----------------|----------------|
      KC_PCMM,         KC_PAST,     KC_P4,           KC_P5,           KC_P6,           KC_PPLS,             KC_DEL,           KC_LEFT,           KC_DOWN,           KC_RGHT,         KC_GRV_REMAP_S,   _______,
  //|----------------|------------|----------------|----------------|----------------|-----------------|  |-----------------|------------------|------------------|----------------|-----------------|----------------|
      KC_CAPSLOCK,     KC_PEQL,     KC_P1,           KC_P2,           KC_P3,           KC_PENT,             _______,          KC_PGDN,           _______,           KC_END,          KC_GRV_REMAP,     _______,
  //`----------------+------------+----------------|----------------|----------------|-----------------|  |-----------------|------------------|------------------|----------------+-----------------+----------------,
                       KC_P0,       KC_PDOT,         _______,         _______,         _______,             _______,          _______,           _______,           KC_VOLD,         KC_VOLU,
  //                 `------------|----------------|----------------|----------------|-----------------|  |-----------------|------------------|------------------|----------------|-----------------,
                                                                      KC_APP,          _______,             _______,          _______
  //                                                                `----------------+-----------------,  `-----------------+------------------,                                                    
  ),

  [LAYER_FUNC] = LAYOUT_5x6_5(
  //,----------------+------------+----------------+----------------+----------------+-----------------.  ,-----------------+------------------+------------------+----------------+-----------------+----------------.
      KC_NUM,          KC_F1,       KC_F2,           KC_F3,           KC_F4,           KC_F5,               KC_F6,            KC_F7,             KC_F8,             KC_F9,           KC_F10,           KC_PAUS,
  //|----------------|------------|----------------|----------------|----------------|-----------------|  |-----------------|------------------|------------------|----------------|-----------------|----------------|
      _______,         KC_F11,      KC_F12,          KC_F13,          KC_F14,          KC_F15,              KC_F16,           KC_F17,            KC_F18,            KC_F19,          KC_F20,           _______,
  //|----------------|------------|----------------|----------------|----------------|-----------------|  |-----------------|------------------|------------------|----------------|-----------------|----------------|
      _______,         _______,     _______,         _______,         _______,         _______,             _______,          _______,           _______,           _______,         _______,          _______,
  //|----------------|------------|----------------|----------------|----------------|-----------------|  |-----------------|------------------|------------------|----------------|-----------------|----------------|
      _______,         _______,     _______,         _______,         _______,         _______,             _______,          _______,           _______,           _______,         _______,          _______,
  //`----------------+------------+----------------|----------------|----------------|-----------------|  |-----------------|------------------|------------------|----------------+-----------------+----------------,
                       KC_PSCR,     KC_SLCK,         _______,         _______,         _______,             _______,          _______,           _______,           KC_WH_U,         KC_WH_D,
  //                 `------------|----------------|----------------|----------------|-----------------|  |-----------------|------------------|------------------|----------------|-----------------,
                                                                      KC_OSMODE,       _______,             _______,          _______
  //                                                                `----------------+-----------------,  `-----------------+------------------,                                                    
  )
};

static os_modes_t os_mode = WIN;

static void emit_key_event(uint16_t keycode, keyrecord_t *record)
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

        case KC_MISSION_CONTROL:
            if (os_mode == MAC) {
                // Send the mission control key command.
                host_consumer_send(record->event.pressed ? 0x29F : 0);
                return false;
            }
            break;

        case KC_LAUNCHPAD:
            if (os_mode == MAC) {
                // Send the launch pad key command.
                host_consumer_send(record->event.pressed ? 0x2A0 : 0);
                return false;
            }
            break;

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

        case KC_NUBS_REMAP:
            // Mac and Windows swap the placement of NUBS and GRAVE under CSA keyboard layout.
            emit_key_event((os_mode == WIN) ? KC_NONUS_BSLASH : KC_GRAVE, record);
            return true;

        case KC_GRV_REMAP:
        case KC_GRV_REMAP_S:
        	{
	            // Mac and Windows swap the placement of NUBS and GRAVE under CSA keyboard layout.
	        	uint16_t kc = (os_mode == WIN) ? KC_GRAVE : KC_NONUS_BSLASH;
	            emit_key_event((keycode == KC_GRV_REMAP_S) ? LSFT(kc) : kc, record);
	            return true;
	        }

        case KC_PAUSE:
        case KC_SCROLLLOCK:
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