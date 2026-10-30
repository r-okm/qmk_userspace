#!/bin/sh
# Userspace only overlays keymaps, so keyboard definitions missing from qmk_firmware
# (any keyboard.json under keyboards/ outside keymaps/) are copied into it.
# Usage: bin/install_keyboards.sh [qmk_firmware_dir]  (default: qmk config user.qmk_home)
set -eu

userspace=$(cd "$(dirname "$0")/.." && pwd)
qmk_home=${1:-$(qmk config -ro user.qmk_home | cut -d= -f2)}
if [ ! -d "$qmk_home/keyboards" ]; then
    echo "qmk_firmware not found: $qmk_home" >&2
    exit 1
fi

# Marks a directory as installed by this script, so a rerun can replace it
# while a definition that ships upstream is never overwritten.
marker=.installed_from_userspace

cd "$userspace"
find keyboards -name keyboard.json -not -path '*/keymaps/*' | while read -r json; do
    kb=$(dirname "$json")
    dst="$qmk_home/$kb"
    if [ -e "$dst" ] && [ ! -e "$dst/$marker" ]; then
        echo "$kb already exists in qmk_firmware; remove it from userspace or rename it" >&2
        exit 1
    fi
    rm -rf "$dst"
    mkdir -p "$dst"
    tar -C "$kb" --exclude=./keymaps -cf - . | tar -C "$dst" -xf -
    touch "$dst/$marker"
    echo "Installed $kb"
done
