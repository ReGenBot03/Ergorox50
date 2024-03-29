BOARD = GENERIC_RP_RP2040
BOOTLOADER = rp2040
BOOTMAGIC_ENABLE = yes

SPLIT_KEYBOARD = yes
SERIAL_DRIVER = vendor
WS2812_DRIVER = vendor
I2C_DRIVER_REQUIRED = yes
ANALOG_DRIVER_REQUIRED = yes

EXTRAKEY_ENABLE = yes
MOUSEKEY_ENABLE = yes
NKRO_ENABLE = yes
AUDIO_SUPPORTED = no
OLED_ENABLE = no

POINTING_DEVICE_ENABLE = yes
POINTING_DEVICE_DRIVER = cirque_pinnacle_i2c

BACKLIGHT_ENABLE = no
RGBLIGHT_SUPPORTED = yes
RGBLIGHT_ENABLE = yes

RGB_MATRIX_SUPPORTED = no
RGB_MATRIX_ENABLE = no
RGB_MATRIX_DRIVER = WS2812

SRC += analog.c