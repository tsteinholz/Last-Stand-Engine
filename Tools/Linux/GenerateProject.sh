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
