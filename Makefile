.SILENT:

MAKEFLAGS += --no-print-directory

QMK_USERSPACE := $(patsubst %/,%,$(dir $(shell realpath "$(lastword $(MAKEFILE_LIST))")))
ifeq ($(QMK_USERSPACE),)
    QMK_USERSPACE := $(shell pwd)
endif

QMK_FIRMWARE_ROOT = $(shell qmk config -ro user.qmk_home | cut -d= -f2 | sed -e 's@^None$$@@g')
ifeq ($(QMK_FIRMWARE_ROOT),)
    $(error Cannot determine qmk_firmware location. `qmk config -ro user.qmk_home` is not set)
endif

EXTERNAL_KEYBOARDS := keyboards/salicylic_acid3/j67g

%: overlay-external-keyboards
	+$(MAKE) -C $(QMK_FIRMWARE_ROOT) $(MAKECMDGOALS) QMK_USERSPACE=$(QMK_USERSPACE)

overlay-external-keyboards:
	@for kb in $(EXTERNAL_KEYBOARDS); do \
		mkdir -p $(QMK_FIRMWARE_ROOT)/$$(dirname $$kb); \
		rm -rf $(QMK_FIRMWARE_ROOT)/$$kb; \
		cp -r $(QMK_USERSPACE)/$$kb $(QMK_FIRMWARE_ROOT)/$$kb; \
	done
