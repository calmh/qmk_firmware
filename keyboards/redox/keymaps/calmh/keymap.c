// make redox:calmh:avrdude

#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

enum unicode_names {
    UC_AA,
    UC_AA_CAP,
    UC_AE,
    UC_AE_CAP,
    UC_OE,
    UC_OE_CAP,
};

const uint32_t PROGMEM unicode_map[] = {
    [UC_AA]     = 0x00E5,
    [UC_AA_CAP] = 0x00C5,
    [UC_AE]     = 0x00E4,
    [UC_AE_CAP] = 0x00C4,
    [UC_OE]     = 0x00F6,
    [UC_OE_CAP] = 0x00D6,
};

// Shortcut to make keymap more readable
#define KC_BKSL KC_BSLASH


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [0] = LAYOUT(
     KC_ESC  ,KC_1    ,KC_2    ,KC_3    ,KC_4    ,KC_5    ,                                            KC_6    ,KC_7    ,KC_8    ,KC_9    ,KC_0    ,KC_MINUS ,
     KC_TAB  ,KC_Q    ,KC_W    ,KC_E    ,KC_R    ,KC_T    ,LGUI(KC_SPACE)   ,                 LGUI(LCTL(KC_Q))   ,KC_Y    ,KC_U    ,KC_I    ,KC_O    ,KC_P    ,KC_EQL  ,
     KC_GRAVE,KC_A    ,KC_S    ,KC_D    ,KC_F    ,KC_G    ,KC_LBRC ,                          KC_RBRC ,KC_H    ,KC_J    ,KC_K    ,KC_L    ,KC_SCLN ,KC_QUOT ,
     KC_LSFT ,KC_Z    ,KC_X    ,KC_C    ,KC_V    ,KC_B    ,KC_F12  ,KC_DEL  ,        KC_F1 ,KC_F2 ,KC_N    ,KC_M    ,KC_COMM ,KC_DOT  ,KC_SLASH ,KC_RSFT ,
     KC_LCTL ,KC_LALT ,KC_LGUI ,KC_HYPR ,     MO(2)   ,    KC_SPC ,KC_BSPC  ,        KC_ENT  ,KC_SPC  ,    MO(1) ,     KC_BSLASH,  XP(UC_AA, UC_AA_CAP), XP(UC_AE, UC_AE_CAP), XP(UC_OE, UC_OE_CAP)
  ),

  [1] = LAYOUT(
     _______ ,KC_F1   ,KC_F2   ,KC_F3   ,KC_F4   ,KC_F5   ,                                            KC_F6   ,KC_F7   ,KC_F8   ,KC_F9   ,KC_F10  ,_______ ,
     _______ ,KC_BTN1 ,KC_MS_U ,KC_BTN2 ,KC_WH_U ,_______ ,_______ ,                          _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,
     _______ ,KC_MS_L ,KC_MS_D ,KC_MS_R ,KC_WH_D ,_______ ,_______ ,                          _______ ,KC_LEFT ,KC_DOWN ,KC_UP   ,KC_RIGHT,_______ ,_______ ,
     _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,        _______ ,_______ ,KC_MEDIA_PREV_TRACK ,KC_AUDIO_VOL_DOWN ,KC_AUDIO_VOL_UP ,KC_MEDIA_NEXT_TRACK ,_______ ,_______ ,
     _______ ,_______ ,_______ ,_______ ,     _______ ,    _______ ,_______ ,        _______ ,KC_MEDIA_PLAY_PAUSE ,    _______ ,     _______ ,_______ ,_______ ,_______
  ),

  [2] = LAYOUT(
     RESET   ,KC_F1   ,KC_F2   ,KC_F3   ,KC_F4   ,KC_F5   ,                                            KC_F6   ,KC_F7   ,KC_F8   ,KC_F9   ,KC_F10  ,UC_MOD ,
     _______ ,RGB_M_P ,RGB_TOG ,RGB_MOD ,RGB_HUD ,RGB_HUI ,_______ ,                          _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,UC_RMOD ,
     _______ ,_______ ,_______ ,_______ ,RGB_SAD ,RGB_SAI ,_______ ,                          _______ ,KC_HOME ,KC_PGDN ,KC_PGUP ,KC_END  ,_______ ,UC_OSX ,
     _______ ,_______ ,_______ ,_______ ,RGB_VAD ,RGB_VAI ,_______ ,_______ ,        _______ ,_______ ,_______ ,KC_F14  ,KC_F15  ,_______ ,_______ ,_______ ,
     _______ ,_______ ,_______ ,_______ ,     _______ ,    _______ ,_______ ,        _______ ,_______ ,    _______ ,     _______ ,_______ ,_______ ,_______
  )
};

void matrix_init_user(void) {
  set_unicode_input_mode(UC_OSX);
}
