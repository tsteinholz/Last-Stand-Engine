/*/-----------------------------------------------------------------------------------------------------------------/*/
/*/                                                                                                                 /*/
/*/                                 ______________________________________                                          /*/
/*/                        ________|                                      |_______                                  /*/
/*/                        \       |     This file is a part of the       |      /                                  /*/
/*/                         \      |    Last Stand Studio Game Engine     |     /                                   /*/
/*/                         /      |______________________________________|     \                                   /*/
/*/                        /__________)                                (_________\                                  /*/
/*/                                                                                                                 /*/
/*/                                     Copyright Last Stand Studio 2015                                            /*/
/*/                                                                                                                 /*/
/*/               The Last Stand Gaming Engine is free software: you can redistribute it and/or modify              /*/
/*/               it under the terms of the GNU General Public License as published by                              /*/
/*/               the Free Software Foundation, either version 3 of the License, or                                 /*/
/*/               (at your option) any later version.                                                               /*/
/*/                                                                                                                 /*/
/*/               The Last Stand Gaming Engine is distributed in the hope that it will be useful,                   /*/
/*/               but WITHOUT ANY WARRANTY; without even the implied warranty of                                    /*/
/*/               MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the                                     /*/
/*/               GNU General Public License for more details.                                                      /*/
/*/                                                                                                                 /*/
/*/               You should have received a copy of the GNU General Public License                                 /*/
/*/               along with The Last Stand Gaming Engine. If not, see <http://www.gnu.org/licenses/>.              /*/
/*/                                                                                                                 /*/
/*/                                                                                                                 /*/
/*/-----------------------------------------------------------------------------------------------------------------/*/

#include "GlobalSettings.h"

GlobalSettings::GlobalSettings ()
{
    if ( !LoadConfig() )
    {
        SetBool( "AntiAliasing", true );

        Window = SDL_WINDOW_FULLSCREEN_DESKTOP;
    }
}

GlobalSettings::~GlobalSettings()
{
    //TODO - Save any unsaved changes to the file
}

bool GlobalSettings::LoadConfig()
{
    //TODO using File utils load a file called settings.(haven't decided the file extension)
    return false;
}

void GlobalSettings::SetBool(std::string key, bool value) {
    BoolSettings.insert( std::pair<std::string, bool> (key, value) );}

bool GlobalSettings::GetBool(std::string key) {
    std::map<std::string, bool>::const_iterator iterator = BoolSettings.find ( key );
    if ( iterator == BoolSettings.end() ) return false;
    return iterator->second;
}

void GlobalSettings::SetDouble(std::string key, double value) {
    DoubleSettings.insert( std::pair <std::string, double> ( key, value ) );
}

double GlobalSettings::GetDouble(std::string key) {
    std::map<std::string, double>::const_iterator iterator = DoubleSettings.find ( key );
    if ( iterator == DoubleSettings.end() ) return -1;
    return iterator->second;
}

void GlobalSettings::SetFloat(std::string key, float value) {
    FloatSettings.insert( std::pair <std::string, float> ( key, value ) );
}

float GlobalSettings::GetFloat(std::string key) {
    std::map<std::string, float>::const_iterator iterator = FloatSettings.find ( key );
    if ( iterator == FloatSettings.end() ) return -1;
    return iterator->second;
}

void GlobalSettings::SetInt(std::string key, int value) {
    IntSettings.insert(std::pair<std::string, int> ( key, value ) );
}

int GlobalSettings::GetInt(std::string key) {
    std::map<std::string, int>::const_iterator iterator = IntSettings.find ( key );
    if ( iterator == IntSettings.end() ) return -1;
    return iterator->second;
}

void GlobalSettings::SetLong(std::string key, long value) {
    LongSettings.insert (std::pair<std::string, long> ( key , value ) );
}

long GlobalSettings::GetLong(std::string key) {
    std::map<std::string, long>::const_iterator iterator = LongSettings.find ( key );
    if ( iterator == LongSettings.end() ) return -1;
    return iterator->second;
}

void GlobalSettings::SetString(std::string key, std::string value) {
    StringSettings.insert ( std::pair<std::string, std::string> ( key, value ) );
}

std::string GlobalSettings::GetString(std::string key) {
    std::map<std::string, std::string>::const_iterator iterator = StringSettings.find ( key );
    if ( iterator == StringSettings.end() ) return "";
    return iterator->second;
}
