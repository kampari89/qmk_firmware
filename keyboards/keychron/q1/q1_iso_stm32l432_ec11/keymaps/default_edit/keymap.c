/* Copyright 2022 @ Keychron (https://www.keychron.com)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H

// clang-format off

enum layers{
  MAC_BASE,
  MAC_FN,
  WIN_BASE,
  WIN_FN,
  NW_LS,
  NW_SACRED,
  NW_SEC,
  XXX
};


enum custom_keycodes {
    KC_TO_NW_SEC = SAFE_RANGE,
	KC_TO_NW_LS,
	HEAL_POTS,
	SACRED_P2,
	SACRED_P3,
	SACRED_P4,
	SACRED_P5,
};


enum {
    TD_P2,
	TD_P3,
	TD_P4,
	TD_P5,
	TD_SELF_HEAL
};


void dance_P2_each(tap_dance_state_t *state, void *user_data) {
    if (state->count >= 3) {
        SEND_STRING("r7" SS_DELAY(200) "f7");
    }
};
void dance_P3_each(tap_dance_state_t *state, void *user_data) {
    if (state->count >= 3) {
        SEND_STRING("r8" SS_DELAY(200) "f8");
    }
};
void dance_P4_each(tap_dance_state_t *state, void *user_data) {
    if (state->count >= 3) {
        SEND_STRING("r9" SS_DELAY(200) "f9");
    }
};
void dance_P5_each(tap_dance_state_t *state, void *user_data) {
    if (state->count >= 3) {
        SEND_STRING("r0" SS_DELAY(200) "f0");
    }
};

void self_heal_each(tap_dance_state_t *state, void *user_data) {
    if (state->count >= 2) {
        SEND_STRING(SS_DOWN(KC_LCTRL) SS_DELAY(100) "f" SS_UP(KC_LCTRL));
    }
};

void dance_P2_finish(tap_dance_state_t *state, void *user_data) {
    switch (state->count) {
        case 1:
            SEND_STRING("r7");
            break;
        case 2:
            SEND_STRING("f7");
            break;
	}
};
void dance_P3_finish(tap_dance_state_t *state, void *user_data) {
    switch (state->count) {
        case 1:
            SEND_STRING("r8");
            break;
        case 2:
            SEND_STRING("f8");
            break;
	}
};
void dance_P4_finish(tap_dance_state_t *state, void *user_data) {
    switch (state->count) {
        case 1:
            SEND_STRING("r9");
            break;
        case 2:
            SEND_STRING("f9");
            break;
	}
};
void dance_P5_finish(tap_dance_state_t *state, void *user_data) {
    switch (state->count) {
        case 1:
            SEND_STRING("r0");
            break;
        case 2:
            SEND_STRING("f0");
            break;
	}
};

void self_heal_finish(tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        SEND_STRING(SS_DOWN(KC_LCTRL) SS_DELAY(100) "r" SS_UP(KC_LCTRL));
	}
};


tap_dance_action_t tap_dance_actions[] = {
    [TD_P2] = ACTION_TAP_DANCE_FN_ADVANCED(dance_P2_each, dance_P2_finish, NULL),
	[TD_P3] = ACTION_TAP_DANCE_FN_ADVANCED(dance_P3_each, dance_P3_finish, NULL),
	[TD_P4] = ACTION_TAP_DANCE_FN_ADVANCED(dance_P4_each, dance_P4_finish, NULL),
	[TD_P5] = ACTION_TAP_DANCE_FN_ADVANCED(dance_P5_each, dance_P5_finish, NULL),
	[TD_SELF_HEAL] = ACTION_TAP_DANCE_FN_ADVANCED(self_heal_each, self_heal_finish, NULL)
};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case KC_TO_NW_SEC:
        if (record->event.pressed) {
            SEND_STRING("2");
			layer_move(6);
        }
        break;
	case KC_TO_NW_LS:
        if (record->event.pressed) {
            SEND_STRING("1");
			layer_move(4);
        }
        break;
	case HEAL_POTS:
        if (record->event.pressed) {
            SEND_STRING("346");
			layer_move(4);
        }
        break;
	case SACRED_P2:
        if (record->event.pressed) {
            SEND_STRING("q7");
        }
        break;
	case SACRED_P3:
        if (record->event.pressed) {
            SEND_STRING("q8");
        }
        break;
	case SACRED_P4:
        if (record->event.pressed) {
            SEND_STRING("q9");
        }
        break;
	case SACRED_P5:
        if (record->event.pressed) {
            SEND_STRING("q0");
        }
        break;
    }
    return true;
};



#define KC_TASK LGUI(KC_TAB)
#define KC_FLXP LGUI(KC_E)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [MAC_BASE] = LAYOUT_iso_83(
         KC_ESC,   KC_BRID,  KC_BRIU,  KC_NO,    KC_NO,    RGB_VAD,  RGB_VAI,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,    KC_VOLU,  KC_DEL,             KC_MUTE,
         KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,    KC_EQL,   KC_BSPC,            KC_PGUP,
         KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,    KC_RBRC,                      KC_PGDN,
         KC_CAPS,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,    KC_NUHS,  KC_ENT,             KC_HOME,
         KC_LSFT,  KC_NUBS,  KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,              KC_RSFT,  KC_UP,
         KC_LCTL,  KC_LOPT,  KC_LCMD,                                KC_SPC,                                 KC_RCMD,  MO(MAC_FN), KC_RCTL,  KC_LEFT,  KC_DOWN,  KC_RGHT),

    [MAC_FN] = LAYOUT_iso_83(
         _______,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,     KC_F12,   _______,            RGB_TOG,
         _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______,            _______,
         RGB_TOG,  RGB_MOD,  RGB_VAI,  RGB_HUI,  RGB_SAI,  RGB_SPI,  _______,  _______,  _______,  _______,  _______,  _______,    _______,                      _______,
         _______,  RGB_RMOD, RGB_VAD,  RGB_HUD,  RGB_SAD,  RGB_SPD,  _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______,            _______,
         _______,  _______,  _______,  _______,  _______,  _______,  _______,  NK_TOGG,  _______,  _______,  _______,  _______,              _______,  _______,
         _______,  _______,  _______,                                _______,                                _______,  _______,    _______,  _______,  _______,  _______),

    [WIN_BASE] = LAYOUT_iso_83(
         KC_ESC,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,     KC_F12,       KC_DEL,             KC_MUTE,
         KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,    KC_EQL,       KC_BSPC,            KC_PGUP,
         KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,    KC_RBRC,                          KC_PGDN,
         KC_RCTL,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,    KC_NUHS,      KC_ENT,             KC_HOME,
         KC_LSFT,  KC_NUBS,  KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,                  KC_RSFT,  KC_UP,
         KC_LCTL,  KC_LWIN,  KC_LALT,                                KC_SPC,                                 KC_RALT,  MO(WIN_FN), TO(NW_LS),  KC_LEFT,  KC_DOWN,  KC_RGHT),

    [WIN_FN] = LAYOUT_iso_83(
         _______,  KC_BRID,  KC_BRIU,  KC_TASK,  KC_FLXP,  RGB_VAD,  RGB_VAI,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,    KC_VOLU,  _______,            RGB_TOG,
         _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______,            _______,
         RGB_TOG,  RGB_MOD,  RGB_VAI,  RGB_HUI,  RGB_SAI,  RGB_SPI,  _______,  _______,  _______,  _______,  _______,  _______,    _______,                      _______,
         _______,  RGB_RMOD, RGB_VAD,  RGB_HUD,  RGB_SAD,  RGB_SPD,  _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______,            _______,
         _______,  _______,  _______,  _______,  _______,  _______,  _______,  NK_TOGG,  _______,  _______,  _______,  _______,              _______,  _______,
         _______,  _______,  _______,                                _______,                                _______,  _______,    _______,  _______,  _______,  _______),

    [NW_LS] = LAYOUT_iso_83(
         KC_ESC,   		 KC_F1,      KC_F2,         KC_F3,             KC_F4,      KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,     KC_F12,       KC_DEL,             KC_MUTE,
         KC_GRV,   		 XXXXXXX,    KC_TO_NW_SEC,  TD(TD_SELF_HEAL),  HEAL_POTS,  KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,    KC_EQL,       KC_BSPC,            KC_PGUP,
         KC_TAB,   		 TD(TD_P2),  KC_W,          TD(TD_P3),         TD(TD_P4),  KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,       KC_LBRC,      KC_RBRC,            KC_PGDN,
         KC_CAPS,        KC_A,       KC_S,          KC_D,              KC_F,       KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,    KC_NUHS,      KC_ENT,             KC_HOME,
         KC_LSFT,        KC_NUBS,    KC_Z,          KC_X,              TD(TD_P5),  KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,                  KC_RSFT,  KC_UP,
         MO(NW_SACRED),  KC_LWIN,    KC_LALT,                                                KC_SPC,                                 KC_RALT,  MO(WIN_FN), TO(WIN_BASE), KC_LEFT,  KC_DOWN,  KC_RGHT),
 
    [NW_SACRED] = LAYOUT_iso_83(
         _______,  _______,    _______,  _______,    _______,    _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______,            _______,
         _______,  _______,    _______,  _______,    _______,    _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______,            _______,
         _______,  SACRED_P2,  _______,  SACRED_P3,  SACRED_P4,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,                      _______,
         _______,  _______,    _______,  _______,    _______,    _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______,            _______,
         _______,  _______,    _______,  _______,    SACRED_P5,  _______,  _______,  _______,  _______,  _______,  _______,  _______,              _______,  _______,
         _______,  _______,    _______,                                    _______,                                _______,  _______,    _______,  _______,  _______,  _______),
		 
	[NW_SEC] = LAYOUT_iso_83(
         KC_ESC,   KC_F1,          KC_F2,    KC_F3,    KC_F4,      KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,     KC_F12,       KC_DEL,             KC_MUTE,
         KC_GRV,   KC_TO_NW_LS,    XXXXXXX,  KC_3,     HEAL_POTS,  KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,    KC_EQL,       KC_BSPC,            KC_PGUP,
         KC_TAB,   KC_Q,           KC_W,     KC_E,     KC_R,       KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,    KC_RBRC,                          KC_PGDN,
         KC_CAPS,  KC_A,           KC_S,     KC_D,     KC_F,       KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,    KC_NUHS,      KC_ENT,             KC_HOME,
         KC_LSFT,  KC_NUBS,        KC_Z,     KC_X,     KC_C,       KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,                  KC_RSFT,  KC_UP,
         KC_LCTL,  KC_LWIN,        KC_LALT,                                  KC_SPC,                                   KC_RALT,  MO(WIN_FN), TO(NW_LS),  KC_LEFT,  KC_DOWN,  KC_RGHT),
		 
    [XXX] = LAYOUT_iso_83(
         _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______,            _______,
         _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______,            _______,
         _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,                      _______,
         _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______,            _______,
         _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,              _______,  _______,
         _______,  _______,  _______,                                _______,                                _______,  _______,    _______,  _______,  _______,  _______)
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [MAC_BASE] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [MAC_FN]   = { ENCODER_CCW_CW(RGB_VAD, RGB_VAI)},
    [WIN_BASE] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [WIN_FN]   = { ENCODER_CCW_CW(RGB_VAD, RGB_VAI)},
    [NW_LS]    = { ENCODER_CCW_CW(RGB_VAD, RGB_VAI)},
    [NW_SEC]   = { ENCODER_CCW_CW(RGB_VAD, RGB_VAI)},
    [XXX]      = { ENCODER_CCW_CW(RGB_VAD, RGB_VAI)}
};
#endif // ENCODER_MAP_ENABLE

