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
#include "../Utils/Log.h"
#include "../Files/File.h"

std::map<std::string, bool> GlobalSettings::BoolSettings = {};
std::map<std::string, double> GlobalSettings::DoubleSettings = {};
std::map<std::string, int> GlobalSettings::IntSettings = {};
std::map<std::string, std::string> GlobalSettings::StringSettings = {};

Json::Value GlobalSettings::JBoolSettings = {};
Json::Value GlobalSettings::JDoubleSettings = {};
Json::Value GlobalSettings::JIntSettings = {};
Json::Value GlobalSettings::JStringSettings = {};

GlobalSettings::GlobalSettings ()
{
    if ( !LoadConfig() )
    {
        EngineLog << "Using Default Setting Values";
        SetBool ( "AntiAliasing", true );
        SetBool ( "CapFrameRate", false );
        SetBool ( "Debug", false );
        SetBool ( "Fullscreen", false );

        SetString ( "WindowTitle", "Last Stand Engine" );
    }
    Reload();
}

GlobalSettings::~GlobalSettings()
{
    Save ();
}

bool GlobalSettings::LoadConfig( std::string fileName)
{
    //TODO using File utils load a file called settings.(haven't decided the file extension)
    return false;
}

void GlobalSettings::Reload()
{
    //TODO : Optimise this function

    EngineLog << "#######: CURENT SETTINGS :#######";
    // Boolean Settings
    for (std::map<std::string, bool>::const_iterator it = BoolSettings.begin(); it != BoolSettings.end(); it++)
    {
        std::string value = it->second ? "true" : "false";
        JBoolSettings[it->first] = it->second;
        EngineLog << it->first + " = " + value;
    }
    // Double Settings
    for (std::map<std::string, double>::const_iterator it = DoubleSettings.begin(); it != DoubleSettings.end(); it++)
    {
        JDoubleSettings[it->first] = it->second;
        EngineLog << it->first + " = " + std::to_string ( it->second );
    }
    // Integer Settings
    for (std::map<std::string, int>::const_iterator it = IntSettings.begin(); it != IntSettings.end(); it++)
    {
        JIntSettings[it->first] = it->second;
        EngineLog << it->first + " = " + std::to_string( it->second );
    }
    // String Settings
    for (std::map<std::string, std::string>::const_iterator it = StringSettings.begin(); it != StringSettings.end(); it++)
    {
        JStringSettings[it->first] = it->second;
        EngineLog << it->first + " = " + it->second;
    }
    EngineLog << "#######: END OF CURENT SETTINGS :#######";
    Save ();
}

void GlobalSettings::Save ()
{
    Json::Value settings = Json::Value ( Json::objectValue );

    settings["Boolean Settings"] = JBoolSettings;
    settings["Double Settings"]  = JDoubleSettings;
    settings["Integer Settings"] = JIntSettings;
    settings["String Settings"]  = JStringSettings;

    Json::StyledWriter writer;

    EngineLog << "Saving Settings.json..";
    LastStandEngine::File::Write ( "Settings.json", writer.write (settings) );
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

void GlobalSettings::SetInt(std::string key, int value) {
    IntSettings.insert(std::pair<std::string, int> ( key, value ) );
}

int GlobalSettings::GetInt(std::string key) {
    std::map<std::string, int>::const_iterator iterator = IntSettings.find ( key );
    if ( iterator == IntSettings.end() ) return -1;
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
