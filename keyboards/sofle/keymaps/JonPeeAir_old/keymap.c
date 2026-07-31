#include <stdio.h>

#include QMK_KEYBOARD_H

#define INDICATOR_BRIGHTNESS 30
#define RGBLED_HALF 36

#define HSV_OVERRIDE_HELP(h, s, v, Override) h, s , Override
#define HSV_OVERRIDE(hsv, Override) HSV_OVERRIDE_HELP(hsv,Override)

// Light combinations
#define SET_INDICATORS(hsv)    {0, 1, HSV_OVERRIDE_HELP(hsv, INDICATOR_BRIGHTNESS)}, {RGBLED_HALF + 0, 1, HSV_OVERRIDE_HELP(hsv, INDICATOR_BRIGHTNESS)}
#define SET_UNDERGLOW(hsv)     {1, 6, hsv}, {RGBLED_HALF + 1, 6, hsv}
#define SET_NUMPAD(hsv)        {RGBLED_HALF + 16, 5, hsv}, {RGBLED_HALF + 23, 3, hsv}, {RGBLED_HALF + 28, 3, hsv}
#define SET_NUMROW(hsv)        {11, 2, hsv}, {21, 2, hsv}, {31, 2, hsv}, {RGBLED_HALF + 11, 2, hsv}, {RGBLED_HALF + 21, 2, hsv}, {RGBLED_HALF + 31, 2, hsv}
#define SET_INNER_COL(hsv)     {34, 4, hsv}, {RGBLED_HALF + 34, 4, hsv}
#define SET_OUTER_COL(hsv)     {8, 4, hsv}, {RGBLED_HALF + 8, 4, hsv}
#define SET_THUMB_CLUSTER(hsv) {26, 2, hsv}, {RGBLED_HALF + 26, 2, hsv}
#define SET_LAYER_ID(hsv)      {0, 1, HSV_OVERRIDE_HELP(hsv, INDICATOR_BRIGHTNESS)}, {RGBLED_HALF + 0, 1, HSV_OVERRIDE_HELP(hsv, INDICATOR_BRIGHTNESS)}, {1, 6, hsv}, {RGBLED_HALF + 1, 6, hsv}, {8, 4, hsv}, {RGBLED_HALF + 8, 4, hsv}, {26, 2, hsv}, {RGBLED_HALF + 26, 2, hsv}

enum sofle_layers {
    _DEFAULTS = 0,
    _QWERTY = 0,
    _LOWER,
    _RAISE,
    _ADJUST,
    _NUMPAD,
    _GAMING,
    _SWITCH
};

enum custom_keycodes {
    KC_QWERTY = SAFE_RANGE,
    KC_LOWER,
    KC_RAISE,
    KC_ADJUST,
    KC_D_MUTE
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* QWERTY
 * ,-----------------------------------------.                  ,-----------------------------------------.
 * | Esc  |   1  |   2  |   3  |   4  |   5  |                  |   6  |   7  |   8  |   9  |   0  |   `  |
 * |------+------+------+------+------+------|                  |------+------+------+------+------+------|
 * | Tab  |   q  |   w  |   e  |   r  |   t  |                  |   y  |   u  |   i  |   o  |   p  | Bspc |
 * |------+------+------+------+------+------|                  |------+------+------+------+------+------|
 * | LSft |   a  |   s  |   d  |   f  |   g  |                  |   h  |   j  |   k  |   l  |   ;  | RSft |
 * |------+------+------+------+------+------|------.    ,------|------+------+------+------+------+------|
 * | LCtl |   z  |   x  |   c  |   v  |   b  | Mute |    | Mute |   n  |   m  |   ,  |   .  |   /  | RCtl |
 * `-----------------------------------------,------,    .------.-----------------------------------------'
 *            | LGui | LAlt | RGB  |Lower | / Spce /      \ Spce \  |Raise | RGB  | RAlt | Game |
 *            `---------------Togl----------------'       `------------------Mode--------------'
 */
  [_QWERTY] = LAYOUT(
//,----------------------------------------------------.                       ,-----------------------------------------------------.
  KC_ESC , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   ,               LT(_SWITCH, KC_6), KC_7   , KC_8   , KC_9   , KC_0   , KC_GRV ,
//--------+--------+--------+--------+--------+--------|                       |--------+--------+--------+--------+--------+--------|
  KC_TAB , KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   ,                         KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , KC_BSPC,
//--------+--------+--------+--------+--------+--------|                       |--------+--------+--------+--------+--------+--------|
  KC_LSFT, KC_A   , KC_S   , KC_D   , KC_F   , KC_G   ,                         KC_H   , KC_J   , KC_K   , KC_L   , KC_SCLN, KC_RSFT,
//--------+--------+--------+--------+--------+--------|--------|     |--------|--------+--------+--------+--------+--------+--------|
  KC_LCTL, KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   , KC_MUTE,       KC_MUTE, KC_N   , KC_M   , KC_COMM, KC_DOT , KC_SLSH, KC_RCTL,
//--------+--------+--------+--------+--------+--------|--------|     |--------|--------+--------+--------+--------+--------+--------|
                    KC_LGUI, KC_LALT, RGB_TOG,KC_LOWER, KC_SPC ,       KC_SPC ,KC_RAISE, RGB_MOD, KC_RALT, TG(5)
//                 \--------+--------+--------+--------|--------|     |--------|--------+--------+--------+--------/
),




/* RAISE
 * ,-----------------------------------------.                  ,-----------------------------------------.
 * |      |      |      |      |      |      |                  |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                  |------+------+------+------+------+------|
 * | Del  | Ins  | PScr | Menu |XXXXXX|XXXXXX|                  | Home |XXXXXX|XXXXXX|XXXXXX| End  |      |
 * |------+------+------+------+------+------|                  |------+------+------+------+------+------|
 * |      |      |      | BriU | MwUp | PgUp |                  | Left | Down |  Up  | Rght |XXXXXX| Entr |
 * |------+------+------+------+------+------|------.    ,------|------+------+------+------+------+------|
 * |      |      |      | BriD | MwDn | PgDn |      |    |      |      |      |      |      |      |      |
 * `-----------------------------------------,------,    .------.-----------------------------------------'
 *            |      |      |      |      | /      /      \      \  |      |      |      |      |
 *            `-----------------------------------'       `------------------------------------'
 */
[_RAISE] = LAYOUT(
//,----------------------------------------------------.                       ,-----------------------------------------------------.
  _______, _______, _______, _______, _______, _______,                         _______, _______, _______, _______, _______, _______,
//--------+--------+--------+--------+--------+--------|                       |--------+--------+--------+--------+--------+--------|
  _______, KC_INS , KC_PSCR, KC_APP , XXXXXXX, XXXXXXX,                         KC_HOME, XXXXXXX, XXXXXXX, KC_END , KC_DEL , _______,
//--------+--------+--------+--------+--------+--------|                       |--------+--------+--------+--------+--------+--------|
  _______, _______, _______, KC_BRIU, KC_WH_U, KC_PGUP,                         KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT, _______, KC_ENT ,
//--------+--------+--------+--------+--------+--------|--------|     |--------|--------+--------+--------+--------+--------+--------|
  _______, _______, _______, KC_BRID, KC_WH_D, KC_PGDN, _______,       _______, _______, _______, _______, _______, _______, _______,
//--------+--------+--------+--------+--------+--------|--------|     |--------|--------+--------+--------+--------+--------+--------|
                    _______, _______, _______, _______, _______,       _______, _______, _______, _______, _______
//                 \--------+--------+--------+--------|--------|     |--------|--------+--------+--------+--------/
),




/* LOWER
 * ,-----------------------------------------.                  ,-----------------------------------------.
 * |      | F1   | F2   | F3   | F4   | F5   |                  | F6   | F7   | F8   | F9   | F10  | F11  |
 * |------+------+------+------+------+------|                  |------+------+------+------+------+------|
 * |      | Ins  | Pscr | Menu |XXXXXX|XXXXXX|                  |   ^  |   &  |   *  |   {  |   }  | F12  |
 * |------+------+------+------+------+------|                  |------+------+------+------+------+------|
 * |      | LAlt | LCtl | LSft |XXXXXX| Caps |                  |   -  |   =  |   |  |   [  |   ]  |   '  |
 * |------+------+------+------+------+------|------.    ,------|------+------+------+------+------+------|
 * |      | Undo | Cut  | Copy | Pste |XXXXXX|      |    |      |   _  |   +  |   \  |   (  |   )  |   ~  |
 * `-----------------------------------------,------,    .------.-----------------------------------------'
 *            |      |      |      |      | /      /      \      \  |      |      |      |      |
 *            `-----------------------------------'       `------------------------------------'
 */
[_LOWER] = LAYOUT(
//,----------------------------------------------------.                       ,-----------------------------------------------------.
  _______, KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  ,                         KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 ,
//--------+--------+--------+--------+--------+--------|                       |--------+--------+--------+--------+--------+--------|
  _______, KC_INS , KC_PSCR, KC_APP , XXXXXXX, XXXXXXX,                         KC_CIRC, KC_AMPR, KC_ASTR, KC_LCBR, KC_RCBR, KC_F12,
//--------+--------+--------+--------+--------+--------|                       |--------+--------+--------+--------+--------+--------|
  _______, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX, KC_CAPS,                         KC_MINS, KC_EQL , KC_PIPE, KC_LBRC, KC_RBRC, KC_QUOT,
//--------+--------+--------+--------+--------+--------|--------|     |--------|--------+--------+--------+--------+--------+--------|
  _______, KC_UNDO, KC_CUT , KC_COPY, KC_PSTE, XXXXXXX, _______,       _______, KC_UNDS, KC_PLUS, KC_BSLS, KC_LPRN, KC_RPRN, KC_TILD,
//--------+--------+--------+--------+--------+--------|--------|     |--------|--------+--------+--------+--------+--------+--------|
                    _______, _______, _______, _______, _______,       _______, _______, _______, _______, _______
//                 \--------+--------+--------+--------|--------|     |--------|--------+--------+--------+--------/
),




/* ADJUST
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |EPR_CLR|     |      |      |      |      |                    |trnsp |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |QK_BOOT|     |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |RGB_TOG|hue_U|sat_U |bri_U |      |      |-------.    ,-------|desk< |      |      |desk> |      |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * | mode | hue_D|sat_D |bri_D |      | QWTY |-------|    |-------|      | PREV | PLAY | NEXT |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            |trnsp |trnsp |trnsp |trsnp | /trnsp  /       \trnsp \  |trnsp |trnsp |trsnp |trnsp |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
  [_ADJUST] = LAYOUT(
  //,------------------------------------------------.                    ,---------------------------------------------------.
  EE_CLR,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|------+-------+--------+--------+--------+--------|                   |--------+-------+--------+--------+--------+---------|
  QK_BOOT,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|------+-------+--------+--------+--------+--------|                   |--------+-------+--------+--------+--------+---------|
  RGB_TOG,  RGB_HUI, RGB_SAI, RGB_VAI, XXXXXXX, XXXXXXX,             C(G(KC_LEFT)),KC_NO,KC_NO,C(G(KC_RGHT)),XXXXXXX, XXXXXXX,
  //|------+-------+--------+--------+--------+--------|  ===  |   |  ===  |--------+-------+--------+--------+--------+---------|
  RGB_MOD,  RGB_HUD, RGB_SAD, RGB_VAD, XXXXXXX, KC_QWERTY,XXXXXXX,   XXXXXXX, XXXXXXX, KC_MPRV, KC_MPLY, KC_MNXT, XXXXXXX, XXXXXXX,
  //|------+-------+--------+--------+--------+------|  ===  |   |  ===  |--------+-------+--------+--------+--------+---------|
                   _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______
  //            \--------+--------+--------+---------+-------|   |--------+---------+--------+---------+-------/
),




/* NUMPAD
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |trnsp |      |      |      |      |      |                    |      |NumLck|      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |   ^  |   7  |   8  |   9  |   *  |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------|   -  |   4  |   5  |   6  |   =  |   |  |
 * |------+------+------+------+------+------| trnsp |    | trnsp |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|   +  |   1  |   2  |   3  |   /  |trnsp |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            |trnsp | WIN  |trnsp |trnsp | /trnsp  /       \trnsp \  |trnsp | 0    |  .   |trnsp |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[_NUMPAD] = LAYOUT(
  //,------------------------------------------------.                    ,---------------------------------------------------.
  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   _______, KC_NUM,  XXXXXXX, XXXXXXX,XXXXXXX, XXXXXXX,
  //|------+-------+--------+--------+--------+------|                   |--------+-------+--------+--------+--------+---------|
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   KC_CIRC, KC_P7,  KC_P8,   KC_P9,   KC_PAST, XXXXXXX,
  //|------+-------+--------+--------+--------+------|                   |--------+-------+--------+--------+--------+---------|
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   KC_PMNS, KC_P4,  KC_P5,   KC_P6,   KC_PEQL,  KC_PIPE,
  //|------+-------+--------+--------+--------+------|  ===  |   |  ===  |--------+-------+--------+--------+--------+---------|
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,_______,   _______,KC_PPLS, KC_P1,  KC_P2,   KC_P3,   KC_PSLS, _______,
  //|------+-------+--------+--------+--------+------|  ===  |   |  ===  |--------+-------+--------+--------+--------+---------|
              _______, OSM(MOD_MEH), _______, _______, _______,   _______, _______,  KC_P0,   KC_PDOT, _______
  //            \--------+--------+--------+---------+-------|   |--------+---------+--------+---------+-------/
),




/* NUMPAD
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |trnsp |      |      |      |      |      |                    |      |NumLck|      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |   ^  |   7  |   8  |   9  |   *  |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------|   -  |   4  |   5  |   6  |   =  |   |  |
 * |------+------+------+------+------+------| trnsp |    | trnsp |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|   +  |   1  |   2  |   3  |   /  |trnsp |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            |trnsp | WIN  |trnsp |trnsp | /trnsp  /       \trnsp \  |trnsp | 0    |  .   |trnsp |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[_GAMING] = LAYOUT(
  //,------------------------------------------------.                    ,---------------------------------------------------.
  _______, _______, _______, _______, _______, _______,                    _______, _______, _______, _______, _______, _______,
  //|------+-------+--------+--------+--------+------|                   |--------+-------+--------+--------+--------+---------|
  _______, _______, _______, _______, _______, _______,                    _______, _______, _______, _______, _______, _______,
  //|------+-------+--------+--------+--------+------|                   |--------+-------+--------+--------+--------+---------|
  _______, _______, _______, _______, _______, _______,                    _______, _______, _______, _______, _______,  _______,
  //|------+-------+--------+--------+--------+------|  ===  |   |  ===  |--------+-------+--------+--------+--------+---------|
  _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______, _______, _______, _______, _______,
  //|------+-------+--------+--------+--------+------|  ===  |   |  ===  |--------+-------+--------+--------+--------+---------|
                    _______, _______, _______, KC_SPC, KC_LOWER,  _______, _______, _______, _______, _______
  //            \--------+--------+--------+---------+-------|   |--------+---------+--------+---------+-------/
),




/* SWITCH
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | qwer | cole |col_dh| low  | raise| adj  |                    |numpad|      |      |      |      |QK_BOOT|
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------|      |      |      |      |      |EE_CLR|
 * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
 * | SLEEP|      |      |      |      |      |-------|    |-------|      |      |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | Bspc | WIN  |LOWER | Enter| /Space  /       \Enter \  |SPACE | 0    |  .   | RAlt |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
  // layer switcher
[_SWITCH] = LAYOUT(
  //,------------------------------------------------.                    ,---------------------------------------------------.
  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,XXXXXXX, XXXXXXX,
  //|------+-------+--------+--------+--------+------|                   |--------+-------+--------+--------+--------+---------|
  TO(0),   TO(1),   TO(2),   TO(3),   TO(4),   TO(5),                      TO(6),   KC_NO,   KC_NO,   KC_NO,   KC_NO,   QK_BOOT,
  //|------+-------+--------+--------+--------+------|                   |--------+-------+--------+--------+--------+---------|
  KC_NO,   KC_NO, KC_BRIU,   KC_NO,   KC_NO,   KC_NO,                      KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   EE_CLR,
  //|------+-------+--------+--------+--------+------|  ===  |   |  ===  |--------+-------+--------+--------+--------+---------|
  KC_SYSTEM_SLEEP,KC_NO,KC_NO,KC_NO,  KC_NO,   KC_NO, KC_NO,      KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
  //|------+-------+--------+--------+--------+------|  ===  |   |  ===  |--------+-------+--------+--------+--------+---------|
                  KC_NO,    KC_NO,   KC_NO,   KC_NO,   KC_NO,     KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO
  //            \--------+--------+--------+---------+-------|   |--------+---------+--------+---------+-------/
),
};




#ifdef RGBLIGHT_ENABLE
char layer_state_str[72];
// Now define the array of layers. Later layers take precedence

#define DARK_PURPLE      180, 255, 120

// QWERTY,
const rgblight_segment_t PROGMEM layer_qwerty_lights[] = RGBLIGHT_LAYER_SEGMENTS(
	SET_INDICATORS(HSV_RED),
    SET_UNDERGLOW(DARK_PURPLE)
);

// _LOWER,
const rgblight_segment_t PROGMEM layer_num_lights[] = RGBLIGHT_LAYER_SEGMENTS(
	SET_INDICATORS(HSV_RED),
	SET_UNDERGLOW(HSV_ORANGE)
);

// _RAISE,
const rgblight_segment_t PROGMEM layer_symbol_lights[] = RGBLIGHT_LAYER_SEGMENTS(
	SET_INDICATORS(HSV_RED),
	SET_UNDERGLOW(HSV_GREEN)
);

// _COMMAND,
// Light on inner column and underglow
const rgblight_segment_t PROGMEM layer_command_lights[] = RGBLIGHT_LAYER_SEGMENTS(
  SET_LAYER_ID(HSV_PURPLE)
);

//_NUMPAD
const rgblight_segment_t PROGMEM layer_numpad_lights[] = RGBLIGHT_LAYER_SEGMENTS(
	SET_INDICATORS(HSV_ORANGE),
    SET_UNDERGLOW(HSV_ORANGE),
	SET_NUMPAD(HSV_BLUE),
    {8, 4, HSV_ORANGE},
    {26, 2, HSV_ORANGE},
    {RGBLED_HALF + 8, 4, HSV_ORANGE},
    {RGBLED_HALF + 26, 2, HSV_ORANGE}
);

// _GAMING,
const rgblight_segment_t PROGMEM layer_gaming_lights[] = RGBLIGHT_LAYER_SEGMENTS(
	SET_INDICATORS(HSV_RED),
	SET_UNDERGLOW(HSV_RED)
);

// _SWITCHER   // light up top row
const rgblight_segment_t PROGMEM layer_switcher_lights[] = RGBLIGHT_LAYER_SEGMENTS(
	SET_LAYER_ID(HSV_GREEN),
	SET_NUMROW(HSV_GREEN)
);

const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    layer_qwerty_lights,
	layer_num_lights,// overrides layer 1
	layer_symbol_lights,
    layer_command_lights,
	layer_numpad_lights,
    layer_gaming_lights,
	layer_switcher_lights  // Overrides other layers
);

layer_state_t layer_state_set_user(layer_state_t state) {
	rgblight_set_layer_state(0, layer_state_cmp(state, _DEFAULTS) && layer_state_cmp(default_layer_state,_QWERTY));
	rgblight_set_layer_state(1, layer_state_cmp(state, _LOWER));
	rgblight_set_layer_state(2, layer_state_cmp(state, _RAISE));
	rgblight_set_layer_state(3, layer_state_cmp(state, _ADJUST));
	rgblight_set_layer_state(4, layer_state_cmp(state, _NUMPAD));
	rgblight_set_layer_state(5, layer_state_cmp(state, _GAMING));
	rgblight_set_layer_state(6, layer_state_cmp(state, _SWITCH));
    return state;
}

void keyboard_post_init_user(void) {
    // Enable the LED layers
    rgblight_layers = my_rgb_layers;
    rgblight_sethsv(HSV_RED);
	rgblight_mode(RGBLIGHT_MODE_STATIC_LIGHT);
}

#endif



#ifdef OLED_ENABLE

/* KEYBOARD PET START */

/* settings */
#define MIN_WALK_SPEED      10
#define MIN_RUN_SPEED       80

/* advanced settings */
#define ANIM_FRAME_DURATION 50  // how long each frame lasts in ms
#define ANIM_SIZE           96   // number of bytes in array. If you change sprites, minimize for adequate firmware size. max is 1024

#define ANIM_FRAME_DURATION_BUNNY 100
#define ANIM_SIZE_BUNNY           96

/* timers */
uint32_t anim_timer = 0;
uint32_t anim_timer_bunny = 0;

/* current frame */
uint8_t current_frame = 0;
uint8_t current_frame_bunny = 0;

/* status variables */
int   current_wpm = 0;
led_t led_usb_state;

bool isSneaking = false;
bool isJumping  = false;
bool showedJump = true;
bool reverse_frames_bunny = false;

/* logic */
static void render_luna(int LUNA_X, int LUNA_Y) {

    /* Sit */
    static const char PROGMEM sit[2][ANIM_SIZE] = {

       {   /* 'sit1', 32x22px */
           0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x1c,
           0x02, 0x05, 0x02, 0x24, 0x04, 0x04, 0x02, 0xa9, 0x1e, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
           0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x10, 0x08, 0x68, 0x10, 0x08, 0x04, 0x03, 0x00, 0x00,
           0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x06, 0x82, 0x7c, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
           0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x04, 0x0c, 0x10, 0x10, 0x20, 0x20, 0x20, 0x28,
           0x3e, 0x1c, 0x20, 0x20, 0x3e, 0x0f, 0x11, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
       },

       {   /* 'sit2', 32x22px */
           0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x1c,
           0x02, 0x05, 0x02, 0x24, 0x04, 0x04, 0x02, 0xa9, 0x1e, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
           0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x90, 0x08, 0x18, 0x60, 0x10, 0x08, 0x04, 0x03, 0x00, 0x00,
           0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x0e, 0x82, 0x7c, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
           0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x04, 0x0c, 0x10, 0x10, 0x20, 0x20, 0x20, 0x28,
           0x3e, 0x1c, 0x20, 0x20, 0x3e, 0x0f, 0x11, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
       }
    };

    /* Walk */
    static const char PROGMEM walk[2][ANIM_SIZE] = {

        {   /* 'walk1', 32x22px */
            0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x40, 0x20, 0x10, 0x90, 0x90, 0x90, 0xa0, 0xc0, 0x80, 0x80,
            0x80, 0x70, 0x08, 0x14, 0x08, 0x90, 0x10, 0x10, 0x08, 0xa4, 0x78, 0x80, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x08, 0xfc, 0x01, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00,
            0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x18, 0xea, 0x10, 0x0f, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x1c, 0x20, 0x20, 0x3c, 0x0f, 0x11, 0x1f, 0x03,
            0x06, 0x18, 0x20, 0x20, 0x3c, 0x0c, 0x12, 0x1e, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        },

        /* 'walk2', 32x22px */
        {
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x40, 0x20, 0x20, 0x20, 0x40, 0x80, 0x00, 0x00, 0x00,
            0x00, 0xe0, 0x10, 0x28, 0x10, 0x20, 0x20, 0x20, 0x10, 0x48, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 0x20, 0xf8, 0x02, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
            0x03, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x10, 0x30, 0xd5, 0x20, 0x1f, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0x20, 0x30, 0x0c, 0x02, 0x05, 0x09, 0x12, 0x1e,
            0x02, 0x1c, 0x14, 0x08, 0x10, 0x20, 0x2c, 0x32, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        }
    };

    /* Run */
    static const char PROGMEM run[2][ANIM_SIZE] = {

        {   /* 'run1', 32x22px */
            0x00, 0x00, 0x00, 0x00, 0xe0, 0x10, 0x08, 0x08, 0xc8, 0xb0, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80,
            0x80, 0x40, 0x40, 0x3c, 0x14, 0x04, 0x08, 0x90, 0x18, 0x04, 0x08, 0xb0, 0x40, 0x80, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0xc4, 0xa4, 0xfc, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc8, 0x58, 0x28, 0x2a, 0x10, 0x0f, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x0e, 0x09, 0x04, 0x04, 0x04, 0x04, 0x02, 0x03, 0x02, 0x01, 0x01,
            0x02, 0x02, 0x04, 0x08, 0x10, 0x26, 0x2b, 0x32, 0x04, 0x05, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00,
        },

        {   /* 'run2', 32x22px */
            0x00, 0x00, 0x00, 0xe0, 0x10, 0x10, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80,
            0x80, 0x80, 0x78, 0x28, 0x08, 0x10, 0x20, 0x30, 0x08, 0x10, 0x20, 0x40, 0x80, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x03, 0x04, 0x08, 0x10, 0x11, 0xf9, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x10, 0xb0, 0x50, 0x55, 0x20, 0x1f, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x0c, 0x10, 0x20, 0x28, 0x37,
            0x02, 0x1e, 0x20, 0x20, 0x18, 0x0c, 0x14, 0x1e, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        }
    };

    /* Bark */
    static const char PROGMEM bark[2][ANIM_SIZE] = {

        {   /* 'bark1', 32x22px */
            0x00, 0xc0, 0x20, 0x10, 0xd0, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x40,
            0x3c, 0x14, 0x04, 0x08, 0x90, 0x18, 0x04, 0x08, 0xb0, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x03, 0x04, 0x08, 0x10, 0x11, 0xf9, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x80, 0xc8, 0x48, 0x28, 0x2a, 0x10, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x0c, 0x10, 0x20, 0x28, 0x37, 0x02, 0x02,
            0x04, 0x08, 0x10, 0x26, 0x2b, 0x32, 0x04, 0x05, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        },

        {   /* 'bark2', 32x22px */
            0x00, 0xe0, 0x10, 0x10, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x40,
            0x40, 0x2c, 0x14, 0x04, 0x08, 0x90, 0x18, 0x04, 0x08, 0xb0, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x03, 0x04, 0x08, 0x10, 0x11, 0xf9, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc0, 0x48, 0x28, 0x2a, 0x10, 0x0f, 0x20, 0x4a, 0x09, 0x10,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x0c, 0x10, 0x20, 0x28, 0x37, 0x02, 0x02,
            0x04, 0x08, 0x10, 0x26, 0x2b, 0x32, 0x04, 0x05, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        }
    };

    /* Sneak */
    static const char PROGMEM sneak[2][ANIM_SIZE] = {

        {   /* 'sneak1', 32x22px */
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x40, 0x40, 0x40, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0xc0, 0x40, 0x40, 0x80, 0x00, 0x80, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x1e, 0x21, 0xf0, 0x04, 0x02, 0x02, 0x02, 0x02, 0x03, 0x02, 0x02, 0x04,
            0x04, 0x04, 0x03, 0x01, 0x00, 0x00, 0x09, 0x01, 0x80, 0x80, 0xab, 0x04, 0xf8, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x1c, 0x20, 0x20, 0x3c, 0x0f, 0x11, 0x1f, 0x02, 0x06,
            0x18, 0x20, 0x20, 0x38, 0x08, 0x10, 0x18, 0x04, 0x04, 0x02, 0x02, 0x01, 0x00, 0x00, 0x00, 0x00,
        },

        {   /* 'sneak2', 32x22px */
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x40, 0x40, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0xe0, 0xa0, 0x20, 0x40, 0x80, 0xc0, 0x20, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x3e, 0x41, 0xf0, 0x04, 0x02, 0x02, 0x02, 0x03, 0x02, 0x02, 0x02, 0x04,
            0x04, 0x02, 0x01, 0x00, 0x00, 0x00, 0x04, 0x00, 0x40, 0x40, 0x55, 0x82, 0x7c, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0x20, 0x30, 0x0c, 0x02, 0x05, 0x09, 0x12, 0x1e, 0x04,
            0x18, 0x10, 0x08, 0x10, 0x20, 0x28, 0x34, 0x06, 0x02, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00,
        }
    };

    /* animation */
    void animate_luna(void) {
        /* jump */
        if (isJumping || !showedJump) {
            /* clear */
            oled_set_cursor(LUNA_X, LUNA_Y + 2);
            oled_write("     ", false);

            oled_set_cursor(LUNA_X, LUNA_Y - 1);

            showedJump = true;
        } else {
            /* clear */
            oled_set_cursor(LUNA_X, LUNA_Y - 1);
            oled_write("     ", false);

            oled_set_cursor(LUNA_X, LUNA_Y);
        }

        /* switch frame */
        current_frame = (current_frame + 1) % 2;

        /* current status */
        if (led_usb_state.caps_lock) {
            oled_write_raw_P(bark[current_frame], ANIM_SIZE);

        } else if (isSneaking) {
            oled_write_raw_P(sneak[current_frame], ANIM_SIZE);

        } else if (current_wpm <= MIN_WALK_SPEED) {
            oled_write_raw_P(sit[current_frame], ANIM_SIZE);

        } else if (current_wpm <= MIN_RUN_SPEED) {
            oled_write_raw_P(walk[current_frame], ANIM_SIZE);

        } else {
            oled_write_raw_P(run[current_frame], ANIM_SIZE);
        }
    }

#if OLED_TIMEOUT > 0

    /* the animation prevents the normal timeout from occuring */
    if (last_input_activity_elapsed() > OLED_TIMEOUT && last_led_activity_elapsed() > OLED_TIMEOUT) {
        oled_off();
        return;
    } else {
        oled_on();
    }

#endif

    /* animation timer */
    if (timer_elapsed32(anim_timer) > ANIM_FRAME_DURATION) {
        anim_timer = timer_read32();
        animate_luna();
    }
}

/* logic */
static void render_bunny(int BUNNY_X, int BUNNY_Y) {

    static const char PROGMEM idle[3][ANIM_SIZE_BUNNY] = {

        {   /* 'frame1', 32x24px */
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf0, 0x08, 0x04,
            0x04, 0xf8, 0xf0, 0x08, 0x04, 0x04, 0xe4, 0x28, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x80, 0x40, 0x78, 0xc7, 0x80,
            0x80, 0x18, 0x00, 0xa0, 0x80, 0x99, 0x46, 0x38, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x04, 0x1c, 0x20, 0x20, 0x20, 0x30, 0x18,
            0x20, 0x20, 0x20, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        },

        {   /* 'frame2', 32x24px */
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x10, 0x08,
            0x08, 0xf0, 0xe0, 0x10, 0x08, 0x08, 0xc8, 0x28, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x80, 0x40, 0x71, 0x8e, 0x00,
            0x00, 0x31, 0x01, 0x40, 0x00, 0x32, 0x8d, 0x70, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x04, 0x1c, 0x20, 0x20, 0x20, 0x30, 0x19,
            0x21, 0x20, 0x20, 0x1f, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        },

        {   /* 'frame3', 32x24px */
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x40, 0x20,
            0x20, 0xc0, 0x00, 0x80, 0x40, 0x40, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0xe3, 0x1c, 0x00,
            0x00, 0x63, 0x03, 0x80, 0x00, 0x64, 0x1a, 0xe2, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0x09, 0x19, 0x20, 0x20, 0x20, 0x31, 0x1a,
            0x22, 0x20, 0x20, 0x1e, 0x02, 0x02, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
        }
    };

    /* animation */
    void animate_bunny(void) {

        oled_set_cursor(BUNNY_X, BUNNY_Y - 1);
        oled_write("     ", false);

        oled_set_cursor(BUNNY_X, BUNNY_Y);
        oled_write_raw_P(idle[current_frame_bunny], ANIM_SIZE_BUNNY);

        /* switch frame */
        if (reverse_frames_bunny) {
            if (current_frame_bunny > 0) {
                current_frame_bunny--;
            }
            else {
                reverse_frames_bunny = false;
                current_frame_bunny++;
            }
        }
        else {
            if (current_frame_bunny < 2) {
                current_frame_bunny++;
            }
            else {
                reverse_frames_bunny = true;
                current_frame_bunny--;
            }
        }
    }

// #if OLED_TIMEOUT > 0
//
//     /* the animation prevents the normal timeout from occuring */
//     if (last_input_activity_elapsed() > OLED_TIMEOUT && last_led_activity_elapsed() > OLED_TIMEOUT) {
//         oled_off();
//         return;
//     } else {
//         oled_on();
//     }
//
// #endif

    /* animation timer */
    if (timer_elapsed32(anim_timer_bunny) > ANIM_FRAME_DURATION_BUNNY) {
        anim_timer_bunny = timer_read32();
        animate_bunny();
    }
}



/* KEYBOARD PET END */

static void right_oled(void) {

    // static const char PROGMEM me[] = {
    //     0x00, 0x00, 0x00, 0x00, 0xc0, 0x20, 0x30, 0x10, 0x10, 0x10, 0x20, 0x20, 0x40, 0xc0, 0x00, 0x00,
    //     0x00, 0xe0, 0x38, 0x0c, 0x04, 0x04, 0x18, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    //     0x00, 0x00, 0x00, 0x00, 0x01, 0x0f, 0x18, 0x30, 0x60, 0xc0, 0x80, 0x00, 0x00, 0x00, 0x03, 0x8e,
    //     0xff, 0xc0, 0x80, 0x80, 0x80, 0x00, 0xe0, 0x3f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    //     0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x38, 0xee, 0x02, 0x01, 0x01, 0x61, 0x61, 0x01, 0x01, 0x01,
    //     0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x03, 0x62, 0x66, 0x04, 0x0c, 0x38, 0xe0, 0x00, 0x00,
    //     0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0xc3, 0x66, 0x6c, 0x78, 0xf0, 0xa0, 0x40, 0x80,
    //     0x20, 0x40, 0x42, 0x26, 0x42, 0x40, 0x20, 0x00, 0x00, 0x00, 0x00, 0x80, 0xe0, 0x3f, 0x00, 0x00,
    //     0x00, 0x00, 0x00, 0x00, 0x00, 0xf8, 0x0e, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x0e, 0x3d,
    //     0xe1, 0x02, 0x06, 0x0c, 0x1c, 0x14, 0x14, 0x1c, 0x06, 0x0e, 0xf9, 0x03, 0x1e, 0xf0, 0x00, 0x00,
    //     0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 0x70, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0x03,
    //     0x01, 0x01, 0x01, 0x01, 0x02, 0x84, 0x84, 0xc4, 0x4f, 0xc9, 0x4d, 0x41, 0x7f, 0x03, 0x00, 0x00,
    //     0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x81, 0x81, 0x81, 0xbf, 0xe1, 0x01, 0x01,
    //     0x01, 0x01, 0x01, 0x01, 0xf1, 0xf1, 0x00, 0x00, 0x00, 0x0f, 0xf8, 0x40, 0xc0, 0x00, 0x00, 0x00,
    //     0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04,
    //     0x04, 0x04, 0x04, 0x07, 0x00, 0x03, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x03, 0x00, 0x00, 0x00
    // };
    //
    // oled_write_raw_P(me, sizeof(me));

    render_bunny(0, 5);

    // Hue
    uint8_t h = rgblight_get_hue();
    char h_str[4];
    oled_set_cursor(0, 9);
    oled_write("H:", false);
    h_str[3] = '\0';
    h_str[2] = '0' + h % 10;
    h_str[1] = '0' + (h /= 10) % 10;
    h_str[0] = '0' + h / 10;
    oled_write(h_str, false);

    // Saturation
    uint8_t s = rgblight_get_sat();
    char s_str[4];
    oled_set_cursor(0, 10);
    oled_write("S:", false);
    s_str[3] = '\0';
    s_str[2] = '0' + s % 10;
    s_str[1] = '0' + (s /= 10) % 10;
    s_str[0] = '0' + s / 10;
    oled_write(s_str, false);

    // Value
    uint8_t v = rgblight_get_val();
    char v_str[4];
    oled_set_cursor(0, 11);
    oled_write("V:", false);
    v_str[3] = '\0';
    v_str[2] = '0' + v % 10;
    v_str[1] = '0' + (v /= 10) % 10;
    v_str[0] = '0' + v / 10;
    oled_write(v_str, false);


    /* wpm counter */
    uint8_t n = get_current_wpm();
    char    wpm_str[4];
    oled_set_cursor(0, 14);
    wpm_str[3] = '\0';
    wpm_str[2] = '0' + n % 10;
    wpm_str[1] = '0' + (n /= 10) % 10;
    wpm_str[0] = '0' + n / 10;
    oled_write(wpm_str, false);

    oled_set_cursor(0, 15);
    oled_write(" wpm", false);
}

static void left_oled(void) {
    // Print current mode
    oled_write_P(PSTR("\n\n"), false);
    oled_write_ln_P(PSTR("Beep"), false);
    oled_write_ln_P(PSTR("Boop"), false);
    oled_write_ln_P(PSTR(""), false);

	//snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Undef-%ld", layer_state)

    switch (get_highest_layer(default_layer_state)) {
        case _QWERTY:
            oled_write_ln_P(PSTR("Qwrt"), false);
            break;
        default:
            oled_write_ln_P(PSTR("Undef"), false);
    }

    oled_write_P(PSTR("\n\n"), false);

    // Print current layer
    oled_write_ln_P(PSTR("LAYER"), false);
    switch (get_highest_layer(layer_state)) {
        case _QWERTY:
            oled_write_P(PSTR("Base\n"), false);
            break;
        case _RAISE:
            oled_write_P(PSTR("Raise"), false);
            break;
        case _LOWER:
            oled_write_P(PSTR("Lower"), false);
            break;
        case _ADJUST:
            oled_write_P(PSTR("Adj\n"), false);
            break;
        case _NUMPAD:
            oled_write_P(PSTR("Nump\n"), false);
            break;
        case _GAMING:
            oled_write_P(PSTR("Game\n"), false);
            break;
        case _SWITCH:
            oled_write_P(PSTR("Swit\n"), false);
            break;
        default:
            oled_write_ln_P(PSTR("Undef"), false);
    }

    render_luna(0, 13);
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    // return rotation;
    return OLED_ROTATION_270;
}

bool oled_task_user(void) {
    /* KEYBOARD PET VARIABLES START */

    current_wpm   = get_current_wpm();
    led_usb_state = host_keyboard_led_state();

    /* KEYBOARD PET VARIABLES END */

    if (is_keyboard_master()) {
        left_oled();
    } else {
        right_oled();
    }
    return false;
}

#endif




bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_QWERTY:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_QWERTY);
            }
            return false;
        case KC_LOWER:
            if (record->event.pressed) {
                layer_on(_LOWER);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            } else {
                layer_off(_LOWER);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            }
            return false;
        case KC_RAISE:
            if (record->event.pressed) {
                layer_on(_RAISE);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            } else {
                layer_off(_RAISE);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            }
            return false;
        case KC_ADJUST:
            if (record->event.pressed) {
                layer_on(_ADJUST);
            } else {
                layer_off(_ADJUST);
            }
            return false;
        case KC_D_MUTE:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_MEH));
                register_code(KC_UP);
            } else {
                unregister_mods(mod_config(MOD_MEH));
                unregister_code(KC_UP);
            }
            break;

        /* KEYBOARD PET STATUS START */

        case KC_LCTL:
        case KC_RCTL:
            if (record->event.pressed) {
                isSneaking = true;
            } else {
                isSneaking = false;
            }
            break;
        case KC_SPC:
            if (record->event.pressed) {
                isJumping  = true;
                showedJump = false;
            } else {
                isJumping = false;
            }
            break;

        /* KEYBOARD PET STATUS END */
    }
    return true;
}




#ifdef ENCODER_ENABLE

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
	}
    else if (index == 1) {
        switch (get_highest_layer(layer_state)) {
        case _QWERTY:
            if (clockwise) {
                tap_code(KC_WH_D);
            } else {
                tap_code(KC_WH_U);
            }
            break;
        case _RAISE:
        case _LOWER:
            if (clockwise) {
                tap_code(KC_BRID);
            } else {
                tap_code(KC_BRIU);
            }
            break;
        default:
            if (clockwise) {
                tap_code(KC_WH_U);
            } else {
                tap_code(KC_WH_D);
            }
            break;
        }
    }
    return false;
}
#endif
