# name of your application
APPLICATION = light_sensor

# If no BOARD is found in the environment, use this default:
#BOARD ?= native
BOARD ?= samr21-xpro

# This has to be the absolute path to the RIOT base directory:
RIOTBASE ?= $(CURDIR)/../../RIOT-hauke

FEATURES_REQUIRED += periph_adc
#USEMODULE += xtimer

# Comment this out to disable code in RIOT that does safety checking
# which is not needed in a production environment but helps in the
# development process:
#CFLAGS += -DDEVELHELP

include $(RIOTBASE)/Makefile.include
