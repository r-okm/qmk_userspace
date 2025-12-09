SRC += r-okm.c

ifeq ($(strip $(MACROS_ENABLE)), yes)
    OPT_DEFS += -DMACROS_ENABLE
endif
