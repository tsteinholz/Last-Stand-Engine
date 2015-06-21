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

#include "Dictionary.h"

LSEngine::Dictionary::Language LSEngine::Dictionary::x_Language = LSEngine::Dictionary::Language::English;
Json::Value x_Dictionary = {};

LSEngine::Dictionary::Dictionary()
{
    x_Language = Load ();
}

LSEngine::Dictionary::~Dictionary()
{
    Save();
}

LSEngine::Dictionary::Language LSEngine::Dictionary::Load()
{
    //TODO : Find/Load File

    //if file not found then...
    GenerateSave();
}

void LSEngine::Dictionary::Save()
{

}

std::string LSEngine::Dictionary::Get(std::string key )
{
    return NULL;
}

LSEngine::Dictionary::Language LSEngine::Dictionary::GetLang()
{
    return x_Language;
}

void LSEngine::Dictionary::SetLang(LSEngine::Dictionary::Language language)
{
    LSEngine::Dictionary::x_Language = language;
}

void LSEngine::Dictionary::GenerateSave()
{
    Json::Value settings = Json::Value(Json::objectValue);

    settings["Language"] = Language::English;

    Json::StyledWriter writer;

    EngineLog << "Saving Language.json..";
    LSEngine::File::Write("Language.json", writer.write(settings));
}
