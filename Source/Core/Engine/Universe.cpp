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

#include "Universe.h"

Universe* Universe::x_instance = NULL;

Universe::Universe ()
{
    TheEngineState = STARTING;

    //Settings


    //Objects


}

Universe::~Universe()
{

}

Universe& Universe::GetInstance ()
{
    if ( x_instance == NULL )
    {
        x_instance = new Universe ();
    }
    return *x_instance;
}

bool Universe::Initialize ( unsigned int w, unsigned int h, const std::string& t, bool aa, bool f, bool r)
{
    if (TheEngineState == RUNNING)
    {
        return false;
    }
    TheEngineState = INITIALIZING;

    //TODO : Create a window - Apply proper Settings.

    if ( SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_JOYSTICK) < 0 )
    {
        EngineLog << "SDL could not initialize! SDL ERROR: " << SDL_GetError();
        SDL_Quit();
        return false;
    }
    else
    {
        EngineLog << "SDL Video, Audio, and Joystick support has been initialized";
        Universe::x_Window = SDL_CreateWindow(
                t.c_str(),
                SDL_WINDOWPOS_CENTERED,
                SDL_WINDOWPOS_CENTERED,
                w,
                h,
                SDL_WINDOW_FULLSCREEN_DESKTOP
        );

        Universe::x_Renderer = SDL_CreateRenderer(x_Window, -1, 0);
    }

    TheEngineState = RUNNING;
    return true;
}

void Universe::Start ()
{
    if (TheEngineState != Universe::RUNNING)
    {
        Universe::Initialize();
    }
    MainLoop();
}

void Universe::MainLoop ()
{
    while (TheEngineState == Universe::RUNNING)
    {
        SDL_SetRenderDrawColor(x_Renderer, 0, 0, 0, 225);
        SDL_RenderClear(x_Renderer);
        SDL_RenderPresent(x_Renderer);

        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
                case SDL_MOUSEBUTTONDOWN:
                    EngineLog << "Closing down Window.";
                    Stop();
                    break;
            }
        }
    }
}

void Universe::Pause ()
{

}

void Universe::Stop ()
{
    TheEngineState = Universe::STOPING;
    SDL_Quit();
}
