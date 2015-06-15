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

echo Generating Project for the Last Stand Engine...
read -e -p "Enter Project Name: " PROJECT_NAME
echo Generating ${PROJECT_NAME} Project Files

if [ -n "$PROJECT_NAME" ]
then
PROJECT_NAME="LastStandGame"
fi

mkdir ${PROJECT_NAME}
cd ${PROJECT_NAME}

echo Downloading Template Files
wget https://github.com/LastStandStudio/Last-Stand-Engine-Template/releases/download/0.1/Sources.zip

echo Setting Up Sources Folder
unzip Sources.zip
rm Sources.zip

echo Creating Resources Folder
mkdir Resources

echo Creating Source Folder
mkdir Source

echo Creating Distribution Folder
mkdir Distribution

echo Generation is now complete!
echo
echo Enviornment is now ready!
