/* Copyright 2019 Franklin Harding
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

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
    OVERLEAF_CUSTOM_1,
    OVERLEAF_CUSTOM_2,
    OVERLEAF_AUTOINDENT,
    OVERLEAF_TOGGLE_FOLD,
    OVERLEAF_FOLD_OTHERS,
    RESET_KEY
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
      OVERLEAF_CUSTOM_1,        OVERLEAF_CUSTOM_2,
      OVERLEAF_TOGGLE_FOLD,     OVERLEAF_FOLD_OTHERS,
      RESET_KEY,                    OVERLEAF_AUTOINDENT      
    ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case OVERLEAF_CUSTOM_1:
      if (record->event.pressed) {
        register_code(KC_LCMD);
        tap_code(KC_I);
        unregister_code(KC_LCMD);

        register_code(KC_LSHIFT);
        tap_code(KC_LEFT);
        unregister_code(KC_LSHIFT);

        register_code(KC_LSHIFT);
        register_code(KC_LCTRL);
        tap_code(KC_M);
        unregister_code(KC_LSHIFT);
        unregister_code(KC_LCTRL);

        tap_code(KC_LEFT);
        tap_code(KC_LEFT);

        tap_code(KC_BSPACE);
        tap_code(KC_BSPACE);
        tap_code(KC_BSPACE);
        tap_code(KC_BSPACE);
        tap_code(KC_BSPACE);
        tap_code(KC_BSPACE);

        SEND_STRING("add");
      }
      break;
    case OVERLEAF_CUSTOM_2:
      if (record->event.pressed) {
        register_code(KC_LCMD);
        tap_code(KC_I);
        unregister_code(KC_LCMD);

        register_code(KC_LSHIFT);
        tap_code(KC_LEFT);
        unregister_code(KC_LSHIFT);

        register_code(KC_LSHIFT);
        register_code(KC_LCTRL);
        tap_code(KC_M);
        unregister_code(KC_LSHIFT);
        unregister_code(KC_LCTRL);

        tap_code(KC_LEFT);
        tap_code(KC_LEFT);

        tap_code(KC_BSPACE);
        tap_code(KC_BSPACE);
        tap_code(KC_BSPACE);
        tap_code(KC_BSPACE);
        tap_code(KC_BSPACE);
        tap_code(KC_BSPACE);

        SEND_STRING("remove");
      }
      break;
    case OVERLEAF_TOGGLE_FOLD:
      if (record->event.pressed) {
        tap_code(KC_F2);
      }
      break;
    case OVERLEAF_FOLD_OTHERS:
      if (record->event.pressed) {
        register_code(KC_LCMD);
        register_code(KC_LOPT);
        tap_code(KC_0);
        unregister_code(KC_LCMD);
        unregister_code(KC_LOPT);
      }
      break;
    case OVERLEAF_AUTOINDENT: {
      if (record->event.pressed){
        tap_code(KC_F1);
        SEND_STRING("auto indent");
        // tap_code(KC_ENTER);
      }
    }
    case RESET_KEY:
      if (record->event.pressed) {
        SEND_STRING(SS_TAP(X_ENTER));
        reset_keyboard();
      }
      break;
  }

  return true;
}

void matrix_init_user(void) {}

void matrix_scan_user(void) {}

void led_set_user(uint8_t usb_led) {}