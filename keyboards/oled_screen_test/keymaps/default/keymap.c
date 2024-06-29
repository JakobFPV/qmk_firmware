#include QMK_KEYBOARD_H

enum custom_keycodes {
    OPENSPOTIFY,
    OPENBRAVE,
    OPENEXPLORER,
    OPENVS
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {

        case OPENSPOTIFY:
            if (record->event.pressed) {
                SEND_STRING(SS_LWIN("r"));
                _delay_ms(250);
                SEND_STRING("spotify" SS_TAP(X_ENTER));  // Corrected the string
            }
            break;

        case OPENBRAVE:
            if (record->event.pressed) {
                SEND_STRING(SS_LWIN("r"));
                _delay_ms(250);
                SEND_STRING("brave" SS_TAP(X_ENTER));  // Corrected the string
            }
            break;

        case OPENEXPLORER:
            if (record->event.pressed) {
                SEND_STRING(SS_LWIN("r"));
                _delay_ms(250);
                SEND_STRING("explorer" SS_TAP(X_ENTER));  // Corrected the string
            }
            break;

        case OPENVS:
            if (record->event.pressed) {
                SEND_STRING(SS_LWIN("r"));
                _delay_ms(250);
                SEND_STRING("code" SS_TAP(X_ENTER));  // Corrected the string
            }
            break;
    }

    return true;  // Moved return true; outside the switch case
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [0] = LAYOUT_ortho_4x3(
        KC_MUTE,   KC_VOLD,   KC_VOLU,   TO(1),
        KC_MPRV,   KC_MPLY,   KC_MNXT,   OPENSPOTIFY,
        TO(4),   OPENBRAVE,   OPENVS,   TO(3)
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
    ),  // Added missing comma here

    [3] = LAYOUT_ortho_4x3(
        TO(0),   TO(0),   TO(0),   TO(0),
        TO(0),   TO(0),   TO(0),   TO(0),
        TO(5),   TO(0),   TO(0),   TO(0)
    ),  // Added missing comma here

    [4] = LAYOUT_ortho_4x3(
        KC_1,   KC_2,   KC_3,   KC_4,
        KC_Q,   KC_W,   KC_E,   KC_F,
        KC_A,   KC_S,   KC_D,   KC_SPACE
    )

};
