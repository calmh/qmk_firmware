#include "ergodox_ez.h"
#include "debug.h"
#include "action_layer.h"
#include "version.h"

enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE, // can always be here
  EPRM,
  VRSN,
  RGB_SLD,
};

/* docker run -e keymap=calmh -e keyboard=ergodox_ez --rm -v $('pwd'):/qmk:rw edasque/qmk_firmware */

/*
LALT(KC_SCOLON), // å
LALT(KC_LBRACKET), // ä
LALT(KC_RBRACKET), // ö
*/
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [0] = LAYOUT_ergodox(
      KC_ESCAPE,  KC_1,     KC_2,     KC_3,     KC_4,   KC_5,   LGUI(KC_SPACE)                                        ,
      KC_TAB,     KC_Q,     KC_W,     KC_E,     KC_R,   KC_T,   KC_LBRACKET,
      KC_GRAVE,   KC_A,     KC_S,     KC_D,     KC_F,   KC_G,
      KC_LSHIFT,  KC_Z,     KC_X,     KC_C,     KC_V,   KC_B,   KC_RBRACKET,
      KC_LCTL,    KC_LALT,  KC_LGUI,  TT(1),    TT(2),

                                KC_DELETE, LGUI(LCTL(KC_Q)),
                                           KC_PGUP,
                    KC_SPACE,  KC_BSPACE,  KC_PGDN,


      KC_TRNS,    KC_6,         KC_7,      KC_8,      KC_9,     KC_0,       KC_MINUS,
      KC_TRNS,    KC_Y,         KC_U,      KC_I,      KC_O,     KC_P,       KC_EQUAL,
                  KC_H,         KC_J,      KC_K,      KC_L,     KC_SCOLON,  KC_QUOTE,
      KC_TRNS,    KC_N,         KC_M,      KC_COMMA,  KC_DOT,   KC_SLASH,   KC_RSHIFT,
    LALT(KC_SCOLON)/*å*/,  LALT(KC_LBRACKET)/*ä*/, LALT(KC_RBRACKET)/*ö*/,  KC_BSLASH,  MO(2),

                      KC_LEFT,  KC_RIGHT,
                      KC_UP,
                      KC_DOWN, KC_ENTER,  KC_SPACE
    ),

  [1] = LAYOUT_ergodox(
    KC_TRNS,        KC_F1,    KC_F2,        KC_F3,        KC_F4,        KC_F5,    KC_TRNS,
    KC_TRNS,        KC_EXLM,  KC_AT,        KC_LCBR,      KC_RCBR,      KC_PIPE,  KC_TRNS,
    KC_TRNS,        KC_HASH,  KC_DLR,       KC_LPRN,      KC_RPRN,      KC_GRAVE,
    KC_TRNS,        KC_PERC,  KC_CIRC,      KC_LBRACKET,  KC_RBRACKET,  KC_TILD,  KC_TRNS,
    KC_TRNS,        KC_TRNS,  KC_TRNS,      KC_TRNS,      KC_TRNS,

                                    KC_TRNS,  KC_POWER,
                                              KC_TRNS,
                    KC_TRNS,        KC_TRNS,  KC_TRNS,

    KC_TRNS,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,
    KC_TRNS,    KC_UP,    KC_7,     KC_8,     KC_9,     KC_ASTR,  KC_F12,
              KC_DOWN,    KC_4,     KC_5,     KC_6,     KC_PLUS,  KC_TRNS,
    KC_TRNS,  KC_AMPR,    KC_1,     KC_2,     KC_3,   KC_BSLASH,  KC_TRNS,
                          KC_TRNS,  KC_KP_0,  KC_TRNS,  KC_EQUAL, KC_TRNS,

                    KC_TRNS,  KC_TRNS,
                    KC_TRNS,
                    KC_TRNS,  KC_TRNS,  KC_TRNS
    ),

  [2] = LAYOUT_ergodox(
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_BTN1, KC_MS_U, KC_BTN2, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_MS_L, KC_MS_D, KC_MS_R, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,

                                           KC_TRNS, KC_TRNS,
                                                    KC_F15,
                                  KC_TRNS, KC_TRNS, KC_F14,
    // right hand
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                KC_LEFT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_UP,   KC_TRNS, KC_TRNS,
                         KC_TRNS, KC_LEFT, KC_DOWN, KC_RIGHT, KC_TRNS,

                    KC_MEDIA_PREV_TRACK, KC_MEDIA_NEXT_TRACK,
                    KC_AUDIO_VOL_UP,
                    KC_AUDIO_VOL_DOWN, KC_MEDIA_PLAY_PAUSE, KC_AUDIO_MUTE
),

};

const uint16_t PROGMEM fn_actions[] = {
  [1] = ACTION_LAYER_TAP_TOGGLE(1)
};

// leaving this in place for compatibilty with old keymaps cloned and re-compiled.
const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
      switch(id) {
        case 0:
        if (record->event.pressed) {
          SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
        }
        break;
      }
    return MACRO_NONE;
};

void matrix_init_user(void) {
#ifdef RGBLIGHT_COLOR_LAYER_0
  rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
#endif
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    // dynamically generate these.
    case EPRM:
      if (record->event.pressed) {
        eeconfig_init();
      }
      return false;
      break;
    case VRSN:
      if (record->event.pressed) {
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
      }
      return false;
      break;
    case RGB_SLD:
      if (record->event.pressed) {
        rgblight_mode(1);
      }
      return false;
      break;

  }
  return true;
}

uint32_t layer_state_set_user(uint32_t state) {

    uint8_t layer = biton32(state);

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    switch (layer) {
      case 0:
        #ifdef RGBLIGHT_COLOR_LAYER_0
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
        #endif
        break;
      case 1:
        ergodox_right_led_1_on();
        #ifdef RGBLIGHT_COLOR_LAYER_1
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_1);
        #endif
        break;
      case 2:
        ergodox_right_led_2_on();
        #ifdef RGBLIGHT_COLOR_LAYER_2
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_2);
        #endif
        break;
      case 3:
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_3
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_3);
        #endif
        break;
      case 4:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        #ifdef RGBLIGHT_COLOR_LAYER_4
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_4);
        #endif
        break;
      case 5:
        ergodox_right_led_1_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_5
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_5);
        #endif
        break;
      case 6:
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_6
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_6);
        #endif
        break;
      case 7:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_7
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_6);
        #endif
        break;
      default:
        break;
    }
    return state;

};
