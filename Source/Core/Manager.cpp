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

#include "Manager.h"

Manager* Manager::x_Instance = NULL;

Manager::Manager()
{
    EnableAll();
}

Manager::~Manager ()
{
    DisableAll();
}

Manager& Manager::GetInstance()
{
    if ( x_Instance == NULL )
    {
        x_Instance = new Manager ();
    }
    return *x_Instance;
}

void Manager::DisableAll()
{
    DisableAudio();
    DisableNetworking();
    DisableInputs();
}

void Manager::DisableAudio()
{
    if ( Audio != NULL )
    {
        delete Audio;
    }
    x_AudioEnabled = false;
}

void Manager::DisableInputs()
{
    if ( Inputs != NULL )
    {
        delete Inputs;
    }
    x_InputEnabled = false;
}

void Manager::DisableNetworking()
{
    if ( Network != NULL )
    {
        delete Network;
    }
    x_NetworkEnabled = false;
}

void Manager::EnableAll()
{
    EnableAudio();
    EnableInputs();
    EnableNetworking();
}

void Manager::EnableAudio()
{
    if ( Audio == NULL )
    {
        Audio = new AudioManager ();
    }
    x_AudioEnabled = true;
}

void Manager::EnableInputs()
{
    if ( Inputs == NULL )
    {
        Inputs = new InputManager ();
    }
    x_InputEnabled = true;
}

void Manager::EnableNetworking()
{
    if ( Network == NULL )
    {
        Network = new NetworkManager ();
    }
    x_NetworkEnabled = true;
}