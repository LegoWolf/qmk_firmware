#include QMK_KEYBOARD_H

enum custom_keycodes {
#ifdef VIA_ENABLE
    KC_MISSION_CONTROL = USER00,
#else
    KC_MISSION_CONTROL = SAFE_RANGE,
#endif
    KC_LAUNCHPAD
};

#define KC_MCTL KC_MISSION_CONTROL
#define KC_LPAD KC_LAUNCHPAD

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[0] = LAYOUT_5x6_5(
		KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,
		MO(1),   KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    MO(1),
		KC_EQL,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
		KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
		         KC_GRV,  KC_BSLS, KC_BSPC, KC_TAB,  KC_LCTL, KC_RCTL, KC_ENT,  KC_SPC,  KC_LBRC, KC_RBRC,
		                                    KC_LGUI, KC_LALT, KC_RALT, MO(2)),

	[1] = LAYOUT_5x6_5(
		_______, KC_BRID, KC_BRIU, KC_MCTL, KC_LPAD, _______, KC_SLEP, KC_MRWD, KC_MPLY, KC_MFFD, KC_MUTE, _______,
		_______, KC_PSLS, KC_P7,   KC_P8,   KC_P9,   KC_PMNS, KC_INS,  KC_PGUP, KC_UP,   KC_HOME, _______, _______,
		KC_PCMM, KC_PAST, KC_P4,   KC_P5,   KC_P6,   KC_PPLS, KC_DEL,  KC_LEFT, KC_DOWN, KC_RGHT, _______, _______,
		_______, KC_PEQL, KC_P1,   KC_P2,   KC_P3,   KC_PENT, _______, KC_PGDN, _______, KC_END,  _______, _______,
		         KC_P0,   KC_PDOT, _______, _______, _______, _______, _______, _______, KC_VOLD, KC_VOLU,
		                                    _______, _______, _______, _______),

	[2] = LAYOUT_5x6_5(
		_______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_PAUS,
		_______, KC_F11,  KC_F12,  KC_F13,  KC_F14,  KC_F15,  KC_F16,  KC_F17,  KC_F18,  KC_F19,  KC_F20,  _______,
		_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
		_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
		         KC_PSCR, KC_SLCK, _______, _______, _______, _______, _______, _______, KC_WH_U,  KC_WH_D,
		                                    KC_APP,  _______, _______, _______),

	[3] = LAYOUT_5x6_5(_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______),
	[4] = LAYOUT_5x6_5(_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______),
	[5] = LAYOUT_5x6_5(_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______)
};

const uint16_t PROGMEM both_shifts[] = {KC_LSFT, KC_RSFT, COMBO_END};
combo_t key_combos[COMBO_COUNT] = {
    COMBO(both_shifts, KC_CAPS)
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_MISSION_CONTROL:
            host_consumer_send(record->event.pressed ? 0x29F : 0);
            return false; // Skip all further processing of this key
        case KC_LAUNCHPAD:
            host_consumer_send(record->event.pressed ? 0x2A0 : 0);
            return false; // Skip all further processing of this key
       default:
            return true; // Process all other keycodes normally
    }
}