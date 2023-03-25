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
#include <keymap_canadian_multilingual.h>

typedef enum {
    LAYER_BASE,
    LAYER_SUPER,
    LAYER_FUNC,
    LAYER_NAV,
    LAYER_GAME
} custom_layers_t;

typedef enum {
    WIN,
    MAC
} os_modes_t;

typedef enum {
#ifdef VIA_ENABLE
    KC_OSMODE = QK_USER_0,
#else
    KC_OSMODE = SAFE_RANGE,
#endif
    KC_VERTICAL_BAR,        // QK_USER_1
    KC_A_CIRCUMFLEX,        // QK_USER_2
    KC_E_CIRCUMFLEX,        // QK_USER_3
    KC_E_DIAERESIS,         // QK_USER_4
    KC_I_CIRCUMFLEX,        // QK_USER_5
    KC_I_DIAERESIS,         // QK_USER_6
    KC_O_CIRCUMFLEX,        // QK_USER_7
    KC_U_CIRCUMFLEX,        // QK_USER_8
    KC_U_DIAERESIS,         // QK_USER_9
    KC_Y_DIAERESIS          // QK_USER_10
} custom_keycodes_t;

#define KC_VBAR KC_VERTICAL_BAR 
#define MAX_LAYERS (LAYER_NUM + 1)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [LAYER_BASE] = LAYOUT_5x6_5(
        KC_ESC,          KC_1,        KC_2,            KC_3,            KC_4,            KC_5,                KC_6,             KC_7,              KC_8,              KC_9,            KC_0,             KC_MINUS,
        MO(LAYER_SUPER), KC_Q,        KC_W,            KC_E,            KC_R,            KC_T,                KC_Y,             KC_U,              KC_I,              KC_O,            KC_P,             MO(LAYER_SUPER),
        KC_EQL,          KC_A,        KC_S,            KC_D,            KC_F,            KC_G,                KC_H,             KC_J,              KC_K,              KC_L,            KC_SCLN,          KC_QUOT,
        KC_LSFT,         KC_Z,        KC_X,            KC_C,            KC_V,            KC_B,                KC_N,             KC_M,              KC_COMMA,          KC_DOT,          KC_SLASH,         KC_RSFT,
                         KC_NUBS,     KC_BSLS,   LT(LAYER_NAV,KC_BSPC), LCTL_T(KC_TAB),  KC_LALT,             KC_RALT,          KC_ENT,            KC_SPC,            KC_LBRC,         KC_RBRC,
                                                                        KC_LGUI,         KC_LCTL,             KC_RCTL,          MO(LAYER_FUNC)                                             
    ),

    [LAYER_SUPER] = LAYOUT_5x6_5(
        XXXXXXX,         XXXXXXX,     XXXXXXX,         XXXXXXX,         XXXXXXX,         XXXXXXX,             XXXXXXX,          XXXXXXX,           XXXXXXX,           XXXXXXX,         XXXXXXX,          XXXXXXX,
        XXXXXXX,         KC_BSLS,     XXXXXXX,         KC_QUOT,         XXXXXXX,         KC_INS,              KC_DEL,           KC_NUBS,           KC_GRV,            KC_LBRC,         KC_VBAR,          XXXXXXX,
        XXXXXXX,         KC_1,        KC_2,            KC_3,            KC_4,            KC_5,                KC_6,             KC_7,              KC_8,              KC_9,            KC_0,             XXXXXXX,
        KC_CAPS,         XXXXXXX,     XXXXXXX,         KC_RBRC,         XXXXXXX,         XXXXXXX,             KC_APP,           XXXXXXX,           XXXXXXX,           XXXXXXX,         XXXXXXX,          KC_CAPS,
                         XXXXXXX,     XXXXXXX,         TG(LAYER_GAME),  XXXXXXX,         _______,             _______,          KC_OSMODE,         _______,           XXXXXXX,         XXXXXXX,
                                                                        _______,         _______,             _______,          _______                                                  
    ),

    [LAYER_FUNC] = LAYOUT_5x6_5(
        XXXXXXX,         XXXXXXX,     XXXXXXX,         XXXXXXX,         XXXXXXX,         XXXXXXX,             XXXXXXX,          KC_BRID,           KC_BRIU,           KC_MCTL,         KC_LPAD,          XXXXXXX,
        XXXXXXX,         KC_F11,      KC_F12,          KC_F13,          KC_F14,          KC_F15,              KC_F16,           KC_F17,            KC_F18,            KC_F19,          KC_F20,           XXXXXXX,
        XXXXXXX,         KC_F1,       KC_F2,           KC_F3,           KC_F4,           KC_F5,               KC_F6,            KC_F7,             KC_F8,             KC_F9,           KC_F10,           XXXXXXX,
        KC_LSFT,         KC_PAUS,     KC_PSCR,         KC_NUM,          KC_SCRL,         XXXXXXX,             KC_MPRV,          KC_MNXT,           KC_VOLD,           KC_VOLU,         KC_MUTE,          KC_RSFT,
                         XXXXXXX,     XXXXXXX,         XXXXXXX,         XXXXXXX,         _______,             _______,          XXXXXXX,           XXXXXXX,           KC_MPLY,         XXXXXXX,
                                                                        _______,         _______,             _______,          _______                                                  
    ),

    [LAYER_NAV] = LAYOUT_5x6_5(
        XXXXXXX,         XXXXXXX,     XXXXXXX,         XXXXXXX,         XXXXXXX,         XXXXXXX,             XXXXXXX,          XXXXXXX,           XXXXXXX,           XXXXXXX,         XXXXXXX,          XXXXXXX,
        XXXXXXX,         XXXXXXX,     KC_HOME,         KC_UP,           KC_END,          KC_PGUP,             KC_PGUP,          KC_HOME,           KC_UP,             KC_END,          XXXXXXX,          XXXXXXX,
        XXXXXXX,         XXXXXXX,     KC_LEFT,         KC_DOWN,         KC_RGHT,         KC_PGDN,             KC_PGDN,          KC_LEFT,           KC_DOWN,           KC_RGHT,         XXXXXXX,          XXXXXXX,
        _______,         XXXXXXX,     KC_LGUI,         KC_LCTL,         KC_LALT,         XXXXXXX,             XXXXXXX,          KC_LGUI,           KC_RCTL,           KC_RALT,         XXXXXXX,          _______,
                         XXXXXXX,     XXXXXXX,         XXXXXXX,         XXXXXXX,         _______,             _______,          XXXXXXX,           XXXXXXX,           KC_WH_U,         KC_WH_D,
                                                                        _______,         _______,             _______,          _______                                                  
    ),

    [LAYER_GAME] = LAYOUT_5x6_5(
        KC_ESC,          KC_1,        KC_2,            KC_3,            KC_4,            KC_5,                XXXXXXX,          XXXXXXX,           XXXXXXX,           XXXXXXX,         XXXXXXX,          TG(LAYER_GAME),
        KC_TAB,          KC_T,        KC_Q,            KC_W,            KC_E,            KC_R,                KC_PSLS,          KC_P7,             KC_P8,             KC_P9,           KC_PPLS,          XXXXXXX,
        KC_LSFT,         KC_G,        KC_A,            KC_S,            KC_D,            KC_F,                KC_P0,            KC_P4,             KC_P5,             KC_P6,           KC_PMNS,          XXXXXXX,
        XXXXXXX,         KC_B,        KC_Z,            KC_X,            KC_C,            KC_V,                KC_PAST,          KC_P1,             KC_P2,             KC_P3,           KC_PCMM,          XXXXXXX,
                         XXXXXXX,     XXXXXXX,         KC_ENT,          KC_SPC,          KC_LALT,             KC_RALT,          KC_PENT,           KC_PEQL,           KC_PDOT,         XXXXXXX,
                                                                        KC_LGUI,         KC_LCTL,             KC_RCTL,          XXXXXXX                                                  
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

static bool swap_key_event(uint16_t keycode, keyrecord_t *record)
{
    if (os_mode == MAC) {
        emit_key_event(keycode, record);
        return false;
    }
    return true;
}

static bool send_deadkey_event(uint16_t deadkeycode, uint16_t keycode, keyrecord_t *record)
{
    if (record->event.pressed) {
        uint8_t mods = get_mods() & (MOD_MASK_SHIFT | MOD_BIT(KC_RALT));
        del_mods(mods);
        tap_code16(deadkeycode);
        add_mods(mods);
        tap_code16(keycode);
    }
    return false;
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

        // Single-stroke versions of keys that normally require deadkey composition.
        case KC_A_CIRCUMFLEX: return send_deadkey_event(CA_CIRC, KC_A, record);
        case KC_E_CIRCUMFLEX: return send_deadkey_event(CA_CIRC, KC_E, record);
        case KC_E_DIAERESIS: return send_deadkey_event(CA_DIAE, KC_E, record);
        case KC_I_CIRCUMFLEX: return send_deadkey_event(CA_CIRC, KC_I, record);
        case KC_I_DIAERESIS: return send_deadkey_event(CA_DIAE, KC_I, record);
        case KC_O_CIRCUMFLEX: return send_deadkey_event(CA_CIRC, KC_O, record);
        case KC_U_CIRCUMFLEX: return send_deadkey_event(CA_CIRC, KC_U, record);
        case KC_U_DIAERESIS: return send_deadkey_event(CA_DIAE, KC_U, record);
        case KC_Y_DIAERESIS: return send_deadkey_event(CA_DIAE, KC_Y, record);

        // Mac and Windows swap the placement of NUBS and GRAVE under CSA keyboard layout.
        case KC_NONUS_BACKSLASH: return swap_key_event(CA_SLSH, record);
        case S(KC_NONUS_BACKSLASH): return swap_key_event(S(CA_SLSH), record);
        case CA_SLSH: return swap_key_event(KC_NONUS_BACKSLASH, record);
        case S(CA_SLSH): return swap_key_event(S(KC_NONUS_BACKSLASH), record);

        case KC_PAUSE:
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