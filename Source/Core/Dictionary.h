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
#include "../Files/File.h"
#include "../Utils/Log.h"
#include <string>

namespace LSEngine
{
    /**
     * This is for in=game dialog, and making the language system support many languages, by loading in the specified
     * language for dialog instead of just hard-coding it inside of the game. Having Multi-Language support in a game
     * can add entire countries to your promotion scheme. Their is also a tool to automaticly generate all the .json
     * dictionary files for you, so all you need to do is know one language and the tool will take care of the rest
     * for you. And since translation services are never perfect, you can always edit the files manually and fix some
     * of the stupid things that get generated in there.
     */
    class Dictionary
    {
    public:

        Dictionary();

        ~Dictionary();

        /**
         * Get the Dialog for the correct language.
         *
         * @parm key The Value's Key
         */
        std::string Get ( std::string key );

        /**
         * List (Enumeration) of all supported Languages.
         */
        enum Language
        {
            Afrikaans,
            Albanian,
            Arabic,
            Armenian,
            Azerbaijani,
            Basque,
            Belarusian,
            Bengali,
            Bosnian,
            Bulgarian,
            Catalan,
            Cebuano,
            Chichewa,
            Chinese,
            Croatian,
            Czech,
            Danish,
            Dutch,
            English,
            Esperanto,
            Estonian,
            Filipino,
            Finnish,
            French,
            Galician,
            Georgian,
            German,
            Greek,
            Gujarati,
            Haitian_Creole,
            Hausa,
            Hebrew,
            Hindi,
            Hmong,
            Hungarian,
            Icelandic,
            Igbo,
            Indonesian,
            Irish,
            Italian,
            Japanese,
            Javanese,
            Kannada,
            Kazakh,
            Khmer,
            Korean,
            Lao,
            Latin,
            Latvian,
            Lithuanian,
            Macedonian,
            Malagasy,
            Malay,
            Malayalam,
            Maltese,
            Maori,
            Marathi,
            Mongolian,
            Myanmar,
            Nepali,
            Norwegian,
            Persian,
            Polish,
            Portuguese,
            Punjabi,
            Romanian,
            Russian,
            Serbian,
            Sesotho,
            Sinhala,
            Slovak,
            Slovenian,
            Somali,
            Spanish,
            Sundanese,
            Swahili,
            Swedish,
            Tajik,
            Tamil,
            Telugu,
            Thai,
            Turkish,
            Ukrainian,
            Urdu,
            Uzbek,
            Vietnamese,
            Welsh,
            Yiddish,
            Yoruba,
            Zulu,
        };

        /**
         * Load the
         */
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

        /**
         * Create a JSON Save File when one is not present.
         **/
        void GenerateSave();

    private:

        /**
         * The current langauge of the dicionary
         */
        static Language x_Language;

        static Json::Value x_Dictionary;
    };
}

#endif //LAST_STAND_ENGINE_DICTIONARY_H
