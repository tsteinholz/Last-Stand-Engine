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
        Set ( "AntiAliasing", true );
        Set ( "Window", SDL_WINDOW_FULLSCREEN_DESKTOP );
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

template<class T>
void GlobalSettings::Set(std::string string, T t) {
    Settings.insert( std::pair<std::string, T> ( string, t ) );
}

template<class T>
T GlobalSettings::Get(std::string key) {
    return Settings.find ( key );
}

bool GlobalSettings::GetBool(std::string key) {
    return (bool) Get ( key );
}

double GlobalSettings::GetDouble(std::string key) {
    return (double) Get ( key );
}

float GlobalSettings::GetFloat(std::string key) {
    return (float) Get ( key );
}

int GlobalSettings::GetInt(std::string key) {
    return (int) Get ( key );
}

long GlobalSettings::GetLong(std::string key) {
    return (long) Get ( key );
}

std::string GlobalSettings::GetString(std::string key) {
    return (std::string) Get ( key );
}
