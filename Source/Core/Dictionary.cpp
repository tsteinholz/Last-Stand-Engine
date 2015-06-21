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

LastStandEngine::Dictionary::Language LastStandEngine::Dictionary::x_Language = LastStandEngine::Dictionary::Language::English;
Json::Value x_Dictionary = {};

LastStandEngine::Dictionary::Dictionary()
{
    x_Language = Load ();
}

LastStandEngine::Dictionary::~Dictionary()
{
    Save();
}

LastStandEngine::Dictionary::Language LastStandEngine::Dictionary::Load()
{

}

void LastStandEngine::Dictionary::Save()
{

}

std::string LastStandEngine::Dictionary::Get(std::string key, std::string value)
{
    return NULL;
}

LastStandEngine::Dictionary::Language LastStandEngine::Dictionary::GetLang()
{
    return x_Language;
}

void LastStandEngine::Dictionary::SetLang(LastStandEngine::Dictionary::Language language)
{
    LastStandEngine::Dictionary::x_Language = language;
}
