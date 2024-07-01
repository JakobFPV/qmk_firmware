#include QMK_KEYBOARD_H

enum custom_keycodes {
    OPENSPOTIFY,
    OPENBRAVE,
    OPENEXPLORER,
    OPENVS,
    SPEAKERS,
    HEADPHONES
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {

        case OPENSPOTIFY:
            if (record->event.pressed) {
                SEND_STRING(SS_LWIN("r"));
                _delay_ms(250);
                SEND_STRING("spotify" SS_TAP(X_ENTER));
            }
            break;

        case OPENBRAVE:
            if (record->event.pressed) {
                SEND_STRING(SS_LWIN("r"));
                _delay_ms(250);
                SEND_STRING("brave" SS_TAP(X_ENTER));
            }
            break;

        case OPENEXPLORER:
            if (record->event.pressed) {
                SEND_STRING(SS_LWIN("r"));
                _delay_ms(250);
                SEND_STRING("explorer" SS_TAP(X_ENTER));
            }
            break;

        case OPENVS:
            if (record->event.pressed) {
                SEND_STRING(SS_LWIN("r"));
                _delay_ms(250);
                SEND_STRING("code" SS_TAP(X_ENTER));
            }
            break;

        case SPEAKERS:
            if (record->event.pressed) {
                register_code(KC_LCTL);
                register_code(KC_LSFT);
                register_code(KC_1);

                unregister_code(KC_1);
                unregister_code(KC_LSFT);   
                unregister_code(KC_LCTL);
            }
            break;

        case HEADPHONES:
            if (record->event.pressed) {
                register_code(KC_LCTL);
                register_code(KC_LSFT);
                register_code(KC_2);

                unregister_code(KC_2);
                unregister_code(KC_LSFT);   
                unregister_code(KC_LCTL);
            }
            break;
    }

    return true;
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [0] = LAYOUT_ortho_4x3(
        KC_MUTE,   KC_VOLD,   KC_VOLU,   TO(1),
        KC_MPRV,   KC_MPLY,   KC_MNXT,   OPENSPOTIFY,
        TO(3),   SPEAKERS,   HEADPHONES,   TO(3)
    ),

    [1] = LAYOUT_ortho_4x3(
        KC_3,   KC_3,   KC_3,   TO(0),
        KC_3,   KC_3,   KC_3,   KC_3,
        KC_3,   KC_3,   KC_3,   KC_3
    ),

    [2] = LAYOUT_ortho_4x3(
        TO(0),   TO(0),   TO(0),   TO(0),
        TO(0),   TO(0),   TO(0),   TO(0),
        TO(0),   TO(0),   TO(0),   KC_SLEP
    ),

    [3] = LAYOUT_ortho_4x3(
        KC_1,   KC_W,   KC_E,   KC_2,
        KC_A,   KC_S,   KC_D,   KC_F,
        KC_3,   KC_4,   KC_LEFT_SHIFT,   KC_SPACE
    )

};
