#include QMK_KEYBOARD_H

enum custom_keycodes {
    OPENSPOTIFY,
    OPENBRAVE,
    OPENEXPLORER,
    OPENVS,
    tenclick
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {


    case OPENSPOTIFY:
        if (record->event.pressed) {
           SEND_STRING(SS_LWIN("r"));
           _delay_ms(250);
           SEND_STRING("spotifz");
           SEND_STRING(SS_TAP(X_ENTER));
        }
        break;


    case OPENBRAVE:
        if (record->event.pressed) {
           SEND_STRING(SS_LWIN("r"));
           _delay_ms(250);
           SEND_STRING("brave");
           SEND_STRING(SS_TAP(X_ENTER));
        }
        break;


    case OPENEXPLORER:
        if (record->event.pressed) {
           SEND_STRING(SS_LWIN("r"));
           _delay_ms(250);
           SEND_STRING("explorer");
           SEND_STRING(SS_TAP(X_ENTER));
        }
        break;


    case OPENVS:
        if (record->event.pressed) {
           SEND_STRING(SS_LWIN("r"));
           _delay_ms(250);
           SEND_STRING("code");
           SEND_STRING(SS_TAP(X_ENTER));
        }
        break;

    case tenclick:
        if (record->event.pressed) {
           register_code(KC_MS_BTN1);
           unregister_code(KC_MS_BTN1);
           _delay_ms(20);
           register_code(KC_MS_BTN1);
           unregister_code(KC_MS_BTN1);
           _delay_ms(20);
           register_code(KC_MS_BTN1);
           unregister_code(KC_MS_BTN1);
           _delay_ms(20);
           register_code(KC_MS_BTN1);
           unregister_code(KC_MS_BTN1);
           _delay_ms(20);
           register_code(KC_MS_BTN1);
           unregister_code(KC_MS_BTN1);
           _delay_ms(20);
           register_code(KC_MS_BTN1);
           unregister_code(KC_MS_BTN1);
           _delay_ms(20);
           register_code(KC_MS_BTN1);
           unregister_code(KC_MS_BTN1);
           _delay_ms(20);
           register_code(KC_MS_BTN1);
           unregister_code(KC_MS_BTN1);
           _delay_ms(20);
           register_code(KC_MS_BTN1);
           unregister_code(KC_MS_BTN1);
           _delay_ms(20);
           register_code(KC_MS_BTN1);
           unregister_code(KC_MS_BTN1);
           _delay_ms(20);
        }
        break;


    }

    return true;
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [0] = LAYOUT_ortho_4x3(
        KC_MUTE,   KC_VOLD,   KC_VOLU,   TO(1),
        KC_MPRV,   KC_MPLY,   KC_MNXT,   OPENSPOTIFY,
        TO(4),   OPENBRAVE,   OPENVS,   TO(3)
    ),

    [1] = LAYOUT_ortho_4x3(
        KC_MS_BTN1,   KC_2,   KC_2,   TO(2),
        tenclick,   KC_2,   KC_2,   KC_2,
        KC_2,   KC_2,   KC_2,   KC_2
    ),

    [2] = LAYOUT_ortho_4x3(
        KC_3,   KC_3,   KC_3,   TO(0),
        KC_3,   KC_3,   KC_3,   KC_3,
        KC_3,   KC_3,   KC_3,   KC_3
    ),

    [3] = LAYOUT_ortho_4x3(
        TO(0),   TO(0),   TO(0),   TO(0),
        TO(0),   TO(0),   TO(0),   TO(0),
        TO(0),   TO(0),   TO(0),   KC_SLEP
    )

    [4] = LAYOUT_ortho_4x3(
        TO(0),   TO(0),   TO(0),   TO(0),
        TO(0),   TO(0),   TO(0),   TO(0),
        TO(5),   TO(0),   TO(0),   TO(0)
    )

    [5] = LAYOUT_ortho_4x3(
        KC_1,   KC_2,   KC_3,   KC_4,
        KC_Q,   KC_W,   KC_E,   KC_F,
        KC_A,   KC_S,   KC_D,   KC_SPACE
    )

};


#ifdef OLED_ENABLE

bool oled_task_user() {
    // Set cursor position
    oled_set_cursor(0, 1);

    oled_write("Hello Janne", false);


    return false;
}

#endif
