SRC += r_okm.c

DEBOUNCE_TYPE = sym_eager_pk

ifeq ($(strip $(MACROS_ENABLE)), yes)
    OPT_DEFS += -DMACROS_ENABLE
endif
