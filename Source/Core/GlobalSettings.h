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

/**
 * These are client side settings that the client can and should change regarding all client side video and sound
 * options.
 */
class GlobalSettings {
public:

    GlobalSettings ();
    ~GlobalSettings ();

    /**
     *
     */
    bool LoadConfig () { LoadConfig("Settings.json"); }

    /**
     *
     */
    bool LoadConfig (std::string fileName);

    /**
     *
     */
    void SetBool ( std::string key, bool value );

    /**
    *
    */
    bool GetBool ( std::string key );

    /**
     *
     */
    void SetDouble ( std::string key, double value );

    double GetDouble ( std::string key );

    void SetFloat ( std::string key, float value );

    float GetFloat ( std::string key );

    void SetInt ( std::string key, int value );

    int GetInt ( std::string key );

    void SetLong ( std::string key, long value );

    long GetLong ( std::string key );

    void SetString ( std::string key, std::string value );

    std::string GetString ( std::string key );

    SDL_WindowFlags Window;

protected:

    /**
     *
     */
    std::map<std::string, bool> BoolSettings;

    /**
     *
     */
    std::map<std::string, std::string> StringSettings;

    /**
     *
     */
    std::map<std::string, int> IntSettings;

    /**
     *
     */
    std::map<std::string, double> DoubleSettings;

    /**
     *
     */
    std::map<std::string, float> FloatSettings;

    /**
     *
     */
    std::map<std::string, long> LongSettings;
};

#endif //LAST_STAND_ENGINE_SETTINGS_H
