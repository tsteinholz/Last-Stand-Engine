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

#ifndef LAST_STAND_ENGINE_DICTIONARY_H
#define LAST_STAND_ENGINE_DICTIONARY_H

#include "../Files/json/json.h"
#include <string>

namespace LastStandEngine {
    /**
     * This is for in=game dialog, and making the language system support many languages, by loading in the specified
     * language for dialog instead of just hard-coding it inside of the game. Having Multi-Language support in a game
     * can add entire countries to your promotion scheme. Their is also a tool to automaticly generate all the .json
     * dictionary files for you, so all you need to do is know one language and the tool will take care of the rest
     * for you. And since translation services are never perfect, you can always edit the files manually and fix some
     * of the stupid things that get generated in there.
     */
    class Dictionary {
    public:
        Dictionary();
        ~Dictionary();

        /**
         *
         * @parm key
         * @parm value
         */
        std::string Get ( std::string key , std::string value );

        enum Language
        {
            English,
            German,
            Spanish,
        };

        Language Load ();

        void Save();

        /** @return The Currently set language */
        Language GetLang ();

        /**
         * Set the current language of the dictionary
         *
         * @parm Language That gets Set to current
         */
        void SetLang ( Language);

    private:
        /**
         * The current langauge of the dicionary
         */
        static Language x_Language;

        static Json::Value x_Dictionary;
    };
}

#endif //LAST_STAND_ENGINE_DICTIONARY_H
