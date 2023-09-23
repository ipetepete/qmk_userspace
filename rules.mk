#   change to "no" to disable the options, or define them in the Makefile in
#   the appropriate keymap folder that will get included automatically
#
BOOTMAGIC_ENABLE = yes       # Virtual DIP switch configuration(+1000)
MOUSEKEY_ENABLE = yes       # Mouse keys(+4700)
EXTRAKEY_ENABLE = yes       # Audio control and System control(+450)
CONSOLE_ENABLE = no         # Console for debug(+400)
COMMAND_ENABLE = no        # Commands for debug and configuration
MIDI_ENABLE = no            # MIDI controls
AUDIO_ENABLE = no           # Audio output on port C6
UNICODE_ENABLE = no         # Unicode
UNICODEMAP_ENABLE = no
BLUETOOTH_ENABLE = no       # Enable Bluetooth with the Adafruit EZ-Key HID
RGBLIGHT_ENABLE = no        # Enable WS2812 RGB underlight.  Do not enable this with audio at the same time.
TAP_DANCE_ENABLE = yes
CAPS_WORD_ENABLE = yes
NKRO_ENABLE = no            # Nkey Rollover - if this doesn't work, see here: https://github.com/tmk/tmk_keyboard/wiki/FAQ#nkro-doesnt-work

ifeq ($(strip $(KEYBOARD)), planck)
	# Do not enable SLEEP_LED_ENABLE. it uses the same timer as BACKLIGHT_ENABLE
	BACKLIGHT_ENABLE = yes      # Enable keyboard backlight functionality
	SLEEP_LED_ENABLE = no    # Breathing sleep LED during USB suspend
endif

INTROSPECTION_KEYMAP_C = ipetepete.c
