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
    bool LoadConfig ();

    template <class T>
    void Set (std::string, T);

    template <class T>
    T Get ( std::string key );

    bool GetBool ( std::string key );

    double GetDouble ( std::string key );

    float GetFloat ( std::string key );

    int GetInt ( std::string key );

    long GetLong ( std::string key );

    std::string GetString ( std::string key );

    /**
     *
     */
    bool AntiAliasing;

    /**
     *
     */
    SDL_WindowFlags Window;

private:

    //TODO Fix this
    template <class T>
    std::map<const std::string&, T> Settings;
};

#endif //LAST_STAND_ENGINE_SETTINGS_H
