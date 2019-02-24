#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _SYMB 1
#define _NAV 2
#define _ADJUST 3

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  SV_AA,
  SV_AE,
  SV_OE,
};

// Shortcut to make keymap more readable
#define KC_BKSL KC_BSLASH


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT(
     KC_ESC  ,KC_1    ,KC_2    ,KC_3    ,KC_4    ,KC_5    ,                                            KC_6    ,KC_7    ,KC_8    ,KC_9    ,KC_0    ,KC_MINUS ,
     KC_TAB  ,KC_Q    ,KC_W    ,KC_E    ,KC_R    ,KC_T    ,LGUI(KC_SPACE)   ,                 LGUI(LCTL(KC_Q))   ,KC_Y    ,KC_U    ,KC_I    ,KC_O    ,KC_P    ,KC_EQL  ,
     KC_GRAVE,KC_A    ,KC_S    ,KC_D    ,KC_F    ,KC_G    ,KC_LBRC ,                          KC_RBRC ,KC_H    ,KC_J    ,KC_K    ,KC_L    ,KC_SCLN ,KC_QUOT ,
     KC_LSFT ,KC_Z    ,KC_X    ,KC_C    ,KC_V    ,KC_B    ,KC_F12  ,KC_DEL  ,        KC_F1 ,KC_F2 ,KC_N    ,KC_M    ,KC_COMM ,KC_DOT  ,KC_SLASH ,KC_RSFT ,
     KC_LCTL ,KC_LALT ,KC_LGUI ,MO(3) ,     MO(1)   ,    KC_SPC ,KC_BSPC  ,        KC_ENT  ,KC_SPC  ,    MO(2) ,     KC_BSLASH,  SV_AA,    SV_AE,      SV_OE
  ),

  [_SYMB] = LAYOUT(
     _______ ,KC_F1   ,KC_F2   ,KC_F3   ,KC_F4   ,KC_F5   ,                                            KC_F6   ,KC_F7   ,KC_F8   ,KC_F9   ,KC_F10  ,XXXXXXX ,
     _______ ,KC_EXLM ,KC_AT   ,KC_LCBR ,KC_RCBR ,KC_PIPE ,_______ ,                          _______ ,XXXXXXX ,KC_KP_7 ,KC_KP_8 ,KC_KP_9 ,XXXXXXX ,XXXXXXX ,
     _______ ,KC_HASH ,KC_DLR  ,KC_LBRC ,KC_RBRC ,KC_GRV  ,_______ ,                          _______ ,XXXXXXX ,KC_KP_4 ,KC_KP_5 ,KC_KP_6 ,XXXXXXX ,XXXXXXX ,
     _______ ,KC_PERC ,KC_CIRC ,KC_LPRN ,KC_RPRN ,KC_TILD ,_______ ,_______ ,        _______ ,_______ ,XXXXXXX ,KC_KP_1 ,KC_KP_2 ,KC_KP_3 ,XXXXXXX ,XXXXXXX ,
     _______ ,_______ ,_______ ,_______ ,     _______ ,    _______ ,_______ ,        _______ ,_______ ,    KC_KP_0 ,     KC_KP_0 ,KC_PDOT ,XXXXXXX ,XXXXXXX
  ),

  [_NAV] = LAYOUT(
     _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,                                            _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,
     XXXXXXX ,KC_BTN1 ,KC_MS_U ,KC_BTN2 ,KC_WH_U ,XXXXXXX ,_______ ,                          _______ ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
     XXXXXXX ,KC_MS_L ,KC_MS_D ,KC_MS_R ,KC_WH_D ,XXXXXXX ,_______ ,                          _______ ,KC_LEFT ,KC_DOWN ,KC_UP   ,KC_RIGHT,XXXXXXX ,XXXXXXX ,
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,_______ ,_______ ,        _______ ,XXXXXXX ,KC_MEDIA_PREV_TRACK ,KC_AUDIO_VOL_DOWN ,KC_AUDIO_VOL_UP ,KC_MEDIA_NEXT_TRACK ,XXXXXXX ,XXXXXXX ,
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,     XXXXXXX ,    XXXXXXX ,_______ ,        _______ ,KC_MEDIA_PLAY_PAUSE ,    XXXXXXX ,     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX
  ),

  [_ADJUST] = LAYOUT(
     XXXXXXX ,KC_F1   ,KC_F2   ,KC_F3   ,KC_F4   ,KC_F5   ,                                            KC_F6   ,KC_F7   ,KC_F8   ,KC_F9   ,KC_F10  ,XXXXXXX ,
     XXXXXXX ,RESET   ,RGB_M_P ,RGB_TOG ,RGB_MOD ,RGB_HUD ,RGB_HUI ,                          RGB_SAD ,RGB_SAI ,RGB_VAD ,RGB_VAI ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,                          XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,_______ ,XXXXXXX ,        XXXXXXX ,_______ ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,     XXXXXXX ,    XXXXXXX ,XXXXXXX ,        XXXXXXX ,XXXXXXX ,    XXXXXXX ,     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX
  )

};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  bool ls = keyboard_report->mods & MOD_BIT (KC_LSFT);
  bool rs = keyboard_report->mods & MOD_BIT (KC_RSFT);

  switch (keycode) {
    case SV_AA:
      if (record->event.pressed) {
        SEND_STRING(SS_LALT("a"));
      }
      return false;
      break;

    case SV_AE:
      if (record->event.pressed) {
        if (ls) {
          unregister_code(KC_LSFT);
        }
        if (rs) {
          unregister_code(KC_RSFT);
        }

        SEND_STRING(SS_LALT("u")); // dead key ¨

        if (ls) {
          register_code(KC_LSFT);
        }
        if (rs) {
          register_code(KC_RSFT);
        }

        SEND_STRING("a");
      }
      return false;
      break;

    case SV_OE:
      if (record->event.pressed) {
        if (ls) {
          unregister_code(KC_LSFT);
        }
        if (rs) {
          unregister_code(KC_RSFT);
        }

        SEND_STRING(SS_LALT("u")); // dead key ¨

        if (ls) {
          register_code(KC_LSFT);
        }
        if (rs) {
          register_code(KC_RSFT);
        }

        SEND_STRING("o");
      }
      return false;
      break;
  }
  return true;
}
