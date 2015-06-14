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

#ifndef LAST_STAND_ENGINE_SETTINGS_H
#define LAST_STAND_ENGINE_SETTINGS_H

#include <map>
#include <SDL_stdinc.h>
#include <SDL_video.h>
#include <string>
#include "../Files/json/json.h"

/**
 * These are client side settings that the client can and should change regarding all client side video and sound
 * options. This file will read and write to the Settings.json file.
 */
class GlobalSettings {
public:

    GlobalSettings ();
    ~GlobalSettings ();

    bool LoadConfig () { return LoadConfig("Settings.json"); }

    bool LoadConfig (std::string fileName);

    void Reload ();

    void Save ();

    static void SetBool ( std::string key, bool value );

    static bool GetBool ( std::string key );

    static void SetDouble ( std::string key, double value );

    static double GetDouble ( std::string key );

    static void SetFloat ( std::string key, float value );

    static float GetFloat ( std::string key );

    static void SetInt ( std::string key, int value );

    static int GetInt ( std::string key );

    static void SetString ( std::string key, std::string value );

    static std::string GetString ( std::string key );

protected:

    static std::map<std::string, bool> BoolSettings;

    static Json::Value JBoolSettings;

    static std::map<std::string, double> DoubleSettings;

    static Json::Value JDoubleSettings;

    static std::map<std::string, float> FloatSettings;

    static Json::Value JFloatSettings;

    static std::map<std::string, int> IntSettings;

    static Json::Value JIntSettings;

    static std::map<std::string, std::string> StringSettings;

    static Json::Value JStringSettings;
};

#endif //LAST_STAND_ENGINE_SETTINGS_H
