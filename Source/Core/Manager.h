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

#ifndef LAST_STAND_ENGINE_MANAGER_H
#define LAST_STAND_ENGINE_MANAGER_H

#include "../Audio/AudioManager.h"
#include "../Networking/NetworkManager.h"
#include "../Input/InputManager.h"
#include "IManages.h"

#define TheManager Manager::GetInstance ();

/**
 * This is the master of all managers. This class will be active in every game, to keep everything managed as
 * efficiently as possible. This class is designed to have only one instance running all the time, this means
 * that the class has been designed very modular and efficient.
 */
class Manager : IManages {
public:

    Manager& GetInstance ();

    static AudioManager*   Audio;
    static InputManager*   Inputs;
    static NetworkManager* Network;

protected:

private:
    Manager ();
    ~Manager();
};

#endif //LAST_STAND_ENGINE_MANAGER_H
