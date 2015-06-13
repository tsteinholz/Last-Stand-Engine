#*/-----------------------------------------------------------------------------------------------------------------/*#
#*/                                                                                                                 /*#
#*/                                 ______________________________________                                          /*#
#*/                        ________|                                      |_______                                  /*#
#*/                        \       |     This file is a part of the       |      /                                  /*#
#*/                         \      |    Last Stand Studio Game Engine     |     /                                   /*#
#*/                         /      |______________________________________|     \                                   /*#
#*/                        /__________)                                (_________\                                  /*#
#*/                                                                                                                 /*#
#*/                                     Copyright Last Stand Studio 2015                                            /*#
#*/                                                                                                                 /*#
#*/               The Last Stand Gaming Engine is free software: you can redistribute it and/or modify              /*#
#*/               it under the terms of the GNU General Public License as published by                              /*#
#*/               the Free Software Foundation, either version 3 of the License, or                                 /*#
#*/               (at your option) any later version.                                                               /*#
#*/                                                                                                                 /*#
#*/               The Last Stand Gaming Engine is distributed in the hope that it will be useful,                   /*#
#*/               but WITHOUT ANY WARRANTY; without even the implied warranty of                                    /*#
#*/               MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the                                     /*#
#*/               GNU General Public License for more details.                                                      /*#
#*/                                                                                                                 /*#
#*/               You should have received a copy of the GNU General Public License                                 /*#
#*/               along with The Last Stand Gaming Engine. If not, see <http://www.gnu.org/licenses/>.              /*#
#*/                                                                                                                 /*#
#*/                                                                                                                 /*#
#*/-----------------------------------------------------------------------------------------------------------------/*#

#!/usr/bin/env bash

echo Last Stand Studio Dependencies

OS=$(uname -s)
ARCH=$(uname -m)
VER=$(uname -r)

if [ -f /etc/arch-release ]; then

	echo  [*] Arch Linux Distro Detected!
	OS=Arch
	pacman -S sdl2 jsoncpp

elif [ -f etc/debian_version ]; then

	echo  [*] Debian Based Distro Detected!
	OS=Debian
	apt-get install dev-libsdl2

elif [ -f /etc/redhat-release ]; then

	echo  [*] RedHat Distro Detected!
	OS=RedHat

else
	echo  [*] Current Distro is not supported! Feel free to pull request any modifications to fix this.
fi
