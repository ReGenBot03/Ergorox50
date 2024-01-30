#pragma once

/* Key Matrix */
#define MATRIX_ROW_PINS { GP12, GP11, GP10, GP9, GP8 }
#define MATRIX_COL_PINS { GP7, GP6, GP5, GP4, GP3, GP2 }
#define RGB_DI_PIN GP13
#define DRIVER_LED_TOTAL 52

/* I2C Driver Settings */
#define I2C_DRIVER I2CD1
#define I2C1_SDA_PIN GP26
#define I2C1_SCL_PIN GP27

/* Split parameters */
#define MASTER_LEFT
#define SERIAL_USART_FULL_DUPLEX
#define SERIAL_USART_PIN_SWAP
#define SERIAL_USART_TX_PIN GP0
#define SERIAL_USART_RX_PIN GP1
#define SPLIT_USB_DETECT
#define SPLIT_USB_TIMEOUT 2500
#define SPLIT_WATCHDOG_ENABLE
#define SPLIT_LAYER_STATE_ENABLE
#define SPLIT_POINTING_ENABLE

/* Right Thumb Device Settings - CirquePad */
#define POINTING_DEVICE_RIGHT
#define CIRQUE_PINNACLE_ADDR 0x2A
#define CIRQUE_PINNACLE_DIAMETER_MM 40
#define CIRQUE_PINNACLE_CURVED_OVERLAY
#define CIRQUE_PINNACLE_TAP_ENABLE
#define POINTING_DEVICE_GESTURES_SCROLL_ENABLE

/* Left Thumb Device Settings - Joystick */
#define JOYSTICK_AXIS_COUNT 2
#define JOYSTICK_BUTTON_COUNT 0
#define JS_X_PIN GP28
#define JS_X_MID 720
#define JS_Y_PIN GP29
#define JS_Y_MID 755
#define JS_DEAD 150


/* RGB Backlight */
#define NOP_FUDGE 0.4
#ifdef RGBLIGHT_ENABLE
#    define RGB_MATRIX_SPLIT    { 26, 26 }
#    define SPLIT_TRANSPORT_MIRROR
#    define RGBLIGHT_EFFECT_BREATHING
#    define RGBLIGHT_EFFECT_RAINBOW_MOOD
#    define RGBLIGHT_EFFECT_RAINBOW_SWIRL
#    define RGBLIGHT_EFFECT_KNIGHT
#    define RGBLIGHT_EFFECT_STATIC_GRADIENT
#    define RGBLIGHT_EFFECT_TWINKLE
#    define RGBLIGHT_EFFECT_RGB_TEST
#endif