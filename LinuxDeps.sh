#!/usr/bin/env bash
echo Last Stand Studio Dependencies

OS=$(uname -s)
ARCH=$(uname -m)
VER=$(uname -r)

if [ -f "/etc/arch-release" ]; then
	echo  [*] Arch Linux Distro Detected
	OS=Arch
	pacman -S sdl2 jsoncpp
elif [ -f etc/debian_version ]; then
	echo  [*] Debian Based Distro Detected
	OS=Debian
elif [ -f /etc/redhat-release ]; then
	echo  [*] RedHat Distro Detected
	OS=RedHat
else
	echo Current Distro is not supported
fi
