MCU = atmega32u2
# F_CPU = 16000000
# ARCH = AVR8
# F_USB = $(F_CPU)
# OPT_DEFS += -DINTERRUPT_CONTROL_ENDPOINT
# OPT_DEFS += -DBOOTLOADER_SIZE=4096
BOOTLOADER = atmel-dfu

BOOTMAGIC_ENABLE = lite      # Virtual DIP switch configuration(+1000)
CONSOLE_ENABLE = yes        # Console for debug(+400)
COMMAND_ENABLE = yes        # Commands for debug and configuration
TAP_DANCE_ENABLE = yes

# LEADER_ENABLE = yes

# ifdef COMBO_ENABLE
#   SRC += combo.c
# endif

# ifdef TAP_DANCE_ENABLE
#   SRC += tap_dance.c
# endif

NKRO_ENABLE = no
RGBLIGHT_ENABLE = yes
