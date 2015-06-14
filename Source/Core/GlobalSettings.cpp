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

#include <jansson.h>
#include "GlobalSettings.h"
#include "../Utils/Log.h"

std::map<std::string, bool> GlobalSettings::BoolSettings = {};
std::map<std::string, double> GlobalSettings::DoubleSettings = {};
std::map<std::string, float> GlobalSettings::FloatSettings = {};
std::map<std::string, int> GlobalSettings::IntSettings = {};
std::map<std::string, long> GlobalSettings::LongSettings = {};
std::map<std::string, std::string> GlobalSettings::StringSettings = {};

GlobalSettings::GlobalSettings ()
{
    if ( !LoadConfig() )
    {
        // These are the Default Values.
        SetBool ( "AntiAliasing", true );
        SetBool ( "CapFrameRate", false );
        SetBool ( "Debug", false );
        SetBool ( "Fullscreen", false );
        SetString ( "WindowTitle", "Last Stand Engine" );
    }
    ReloadSettings();
}

GlobalSettings::~GlobalSettings()
{
    //TODO - Save any unsaved changes to the file
    Json::Value responce = Json::Value ( Json::objectValue );

    responce["bools"] = JBoolSettings;
    responce["doubles"] = JDoubleSettings;
    responce["floats"] = JFloatSettings;
    responce["ints"] = JIntSettings;
    responce["longs"] = JLongSettings;
    responce["strings"] = JStringSettings;

    Json::StyledWriter writer;

    EngineLog << writer.write(responce);
}

bool GlobalSettings::LoadConfig( std::string fileName)
{
    //TODO using File utils load a file called settings.(haven't decided the file extension)
    return false;
}

void GlobalSettings::ReloadSettings()
{
    EngineLog << "#######: CURENT SETTINGS :#######";
    for (std::map<std::string, bool>::const_iterator it = BoolSettings.begin(); it != BoolSettings.end(); it++)
    {
        std::string value = it->second ? "true" : "false";
        JBoolSettings[it->first] = it->second;
        EngineLog << it->first + " = " + value;
    }
    for (std::map<std::string, double>::const_iterator it = DoubleSettings.begin(); it != DoubleSettings.end(); it++)
    {
        JDoubleSettings[it->first] = it->second;
        EngineLog << it->first + " = " + std::to_string ( it->second );
    }
    for (std::map<std::string, float>::const_iterator it = FloatSettings.begin(); it != FloatSettings.end(); it++)
    {
        JFloatSettings[it->first] = it->second;
        EngineLog << it->first + " = " + std::to_string( it->second );
    }
    for (std::map<std::string, int>::const_iterator it = IntSettings.begin(); it != IntSettings.end(); it++)
    {
        JIntSettings[it->first] = it->second;
        EngineLog << it->first + " = " + std::to_string( it->second );
    }
    for (std::map<std::string, long>::const_iterator it = LongSettings.begin(); it != LongSettings.end(); it++)
    {
        JLongSettings[it->first] = it->second;
        EngineLog << it->first + " = " + std::to_string( it->second );
    }
    for (std::map<std::string, std::string>::const_iterator it = StringSettings.begin(); it != StringSettings.end(); it++)
    {
        JStringSettings[it->first] = it->second;
        EngineLog << it->first + " = " + it->second;
    }
    EngineLog << "#######: END OF CURENT SETTINGS :#######";
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
