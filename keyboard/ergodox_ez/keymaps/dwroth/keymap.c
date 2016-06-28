#include "ergodox_ez.h"
#include "debug.h"
#include "action_layer.h"

#define BASE 0 // default layer
#define SYMB 1 // symbols
#define MDIA 2 // media keys
#define NAV  3 // arrows and word boundaries

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |    =   |   1  |   2  |   3  |   4  |   5  | Mute |           | Lock |   6  |   7  |   8  |   9  |   0  |   -    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |  Tab   |   Q  |   W  |   E  |   R  |   T  | Hyper|           |  Meh |   Y  |   U  |   I  |   O  |   P  |   \    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |  Nav   |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |; Medi|   '    |
 * |--------+------+------+------+------+------| Coder|           | Coder|------+------+------+------+------+--------|
 * | LShift |Z Ctrl|   X  |   C  |   V  |   B  |(Hold)|           | 1off |   N  |   M  |   ,  |   .  |/ Ctrl| RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |  Esc |      | Crtl |  Opt |  Cmd |                                       |  Cmd |  Opt | Crtl |      |  `~  |
 *   `----------------------------------'                                       `----------------------------------'
 *                                       ,--------------.       ,--------------.
 *                                       | Down  |  Up  |       | Left | Right |
 *                                ,------|-------|------|       |------+-------+------.
 *                                |      |       | Home |       | PgUp |       |      |
 *                                | Back | Delete|------|       |------| Enter |Space |
 *                                | Space|       | End  |       | PgDn |       |      |
 *                                `---------------------'       `---------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[BASE] = KEYMAP(  // layer 0 : default
        // left hand
        KC_EQL,               KC_1,           KC_2,          KC_3,            KC_4,               KC_5,               KC__MUTE,    
        KC_TAB,               KC_Q,           KC_W,          KC_E,            KC_R,               KC_T,               ALL_T(KC_NO),    
        MO(NAV),     KC_A,           KC_S,          KC_D,            KC_F,               KC_G,                            
        KC_LSFT,              CTL_T(KC_Z),    KC_X,          KC_C,            KC_V,               KC_B,               MO(SYMB),
        KC_ESC,               KC_NO,          KC_LCTL,       KC_LALT,         KC_LGUI,                                                    
                                                                              KC_DOWN,            KC_UP,                         
                                                                                                  KC_HOME,                         
                                                                              KC_BSPC,            KC_DELETE,          KC_END,      
        
        // right hand
        HYPR(KC_F16),               KC_6,            KC_7,         KC_8,            KC_9,               KC_0,               KC_MINS,
        MEH_T(KC_NO),         KC_Y,            KC_U,         KC_I,            KC_O,               KC_P,               KC_BSLS,
                              KC_H,            KC_J,         KC_K,            KC_L,               LT(MDIA, KC_SCLN),  KC_QUOT,
        OSL(SYMB),            KC_N,            KC_M,         KC_COMM,         KC_DOT,             CTL_T(KC_SLSH),     KC_RSFT,
                              KC_RGUI,         KC_RALT,      KC_RCTL,         KC_NO,              KC_GRV,
        KC_LEFT,              KC_RIGHT,
        KC_PGUP,
        KC_PGDN,              KC_ENT,          KC_SPC
    ),
/* Keymap 1: Symbol Layer
 *.0=
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  |  F10 |   F11  |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |   !  |   @  |   {  |   }  |   |  |      |           |      |   Up |   7  |   8  |   9  |   *  |   F12  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | CapsLk |   #  |   $  |   (  |   )  |   `  |------|           |------| Down |   4  |   5  |   6  |   +  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   %  |   ^  |   [  |   ]  |   ~  |      |           |      |   .  |   1  |   2  |   3  |   \  |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |   0  |   0  |   =  |   &  |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |   _  |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// SYMBOLS
[SYMB] = KEYMAP(
       // left hand
       KC_TRNS,KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_TRNS,
       KC_TRNS,KC_EXLM,KC_AT,  KC_LCBR,KC_RCBR,KC_PIPE,KC_TRNS,
       KC_CAPS,KC_HASH,KC_DLR, KC_LPRN,KC_RPRN,KC_GRV,
       KC_TRNS,KC_PERC,KC_CIRC,KC_LBRC,KC_RBRC,KC_TILD,KC_TRNS,
       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
                                       KC_TRNS,KC_TRNS,
                                               KC_TRNS,
                               KC_TRNS,KC_TRNS,KC_TRNS,
       // right hand
       KC_TRNS, KC_F6,   KC_F7,  KC_F8,   KC_F9,   KC_F10,      KC_F11,
       KC_TRNS, KC_UP,   KC_7,   KC_8,    KC_9,    KC_ASTR,     KC_F12,
                KC_DOWN, KC_4,   KC_5,    KC_6,    KC_PLUS,     KC_TRNS,
       KC_TRNS, KC_DOT,  KC_1,   KC_2,    KC_3,    KC_BSLS,     KC_TRNS,
                         KC_0,   KC_0,    KC_EQL,  LSFT(KC_7),  KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, LSFT(KC_MINS)
),
/* Keymap 2: Media and mouse keys
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * | Teensy |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      | MsUp |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |MsLeft|MsDown|MsRght|      |------|           |------|      |      |      |      |      |  Play  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      | Prev | Next |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      | Lclk | Rclk |                                       |VolUp |VolDn | Mute |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |Brwser|
 *                                 |      |      |------|       |------|      |Back  |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// MEDIA AND MOUSE
[MDIA] = KEYMAP(
       RESET,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_MS_U, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_MS_L, KC_MS_D, KC_MS_R, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_BTN1, KC_BTN2,
                                           KC_TRNS, KC_TRNS,
                                                    KC_TRNS,
                                  KC_TRNS, KC_TRNS, KC_TRNS,
    // right hand
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MPLY,
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_MPRV, KC_MNXT, KC_TRNS, KC_TRNS,
                          KC_VOLU, KC_VOLD, KC_MUTE, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_WBAK
),

/* Keymap 3: Nav Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |PrevWd|NextWd|      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |------|           |------| Left | Down |  Up  | Right|      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       | ScrL | ScrR |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |Space |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// MEDIA AND MOUSE
[NAV] = KEYMAP(
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                           KC_TRNS, KC_TRNS,
                                                    KC_TRNS,
                                  KC_SPC,  KC_TRNS, KC_TRNS,
    // right hand
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS,  KC_TRNS, KC_TRNS, LALT(KC_LEFT), RALT(KC_RIGHT), KC_TRNS, KC_TRNS,
                 KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, KC_TRNS, KC_TRNS, 
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                          HYPR(KC_LEFT), HYPR(KC_RIGHT), KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
)
};

const uint16_t PROGMEM fn_actions[] = {
    // [1] = ACTION_LAYER_TAP_TOGGLE(SYMB)                // FN1 - Momentary Layer 1 (Symbols)
};

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {

};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

    uint8_t layer = biton32(layer_state);

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    switch (layer) {
      // TODO: Make this relevant to the ErgoDox EZ.
        case 1:
            ergodox_right_led_1_on();
            break;
        case 2:
            ergodox_right_led_2_on();
            break;
        case 3:
            ergodox_right_led_3_on();
        default:
            // none
            break;
    }

};
