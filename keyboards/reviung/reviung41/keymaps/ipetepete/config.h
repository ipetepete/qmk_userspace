#pragma once
#define BOTH_SHIFTS_TURNS_ON_CAPS_WORD
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET // Activates the double-tap behavior
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_TIMEOUT 200U // Timeout window in ms in which the double tap can occur.
// RGB not working with conversion to RP2040
//#undef WS2812_DI_PIN
//#define WS2812_DI_PIN D0

//#undef WS2812_DRIVER
//#define WS2812_DRIVER = vendor
