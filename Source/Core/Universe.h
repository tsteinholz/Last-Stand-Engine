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

#ifndef LAST_STAND_ENGINE_UNIVERSE_H
#define LAST_STAND_ENGINE_UNIVERSE_H

#include "Dictionary.h"
#include "../Utils/Log.h"

#ifdef __WIN32__
#include "../../Dependencies/include/SDL.h"
#include "../../Dependencies/include/SDL_video.h"
#else
#include <SDL2/SDL.h>            // SDL
#include <SDL2/SDL_video.h>      // SDL
#include <SDL2/SDL_image.h>      // SDL_Image
#include <SDL2/SDL_ttf.h>        // SDL_TTF
#include <SDL2/SDL_mixer.h>      // SDL_Mixer
#include <SDL2/SDL2_rotozoom.h>  // SDL_GFX
#include <SDL2/SDL2_framerate.h> // SDL_GFX
#include "GlobalSettings.h"
#include <string>
#endif

/**
* The Singleton Shortcut to get the instance of the Universe
* just by the call of 'TheUniverse'. Super convenient.
**/
#define TheUniverse LSEngine::Universe::GetInstance ()

namespace LSEngine
{
    /**
    * This is the mother class of the game. This Class represnts
    * the entire game, thus its name "The Universe". Everything
    * that goes on in the game will go on in the universe (this
    * class). This makes levels and code eaier to manage.
    **/
    class Universe
    {
    public:
        /**
        * This is the method used to get / create the
        * Universe, since there can only be one Universe
        * at a time due to thie Singleton Pattern. This is the
        * only way to get or create a Universe.
        *
        * @returns The Universe
        **/
        static Universe &GetInstance();

        /**
        * The diffrent modes and states that the Game Engine
        * could possibly be in.
        **/
        enum EngineState
        {
            /**
            * This is the very first state when the engine
            * gets executed, used mainly for set-up. The atcual
            * window creation is done in the Initialization step.
            **/
            STARTING = 0,

            /**
            * At this state the engine is loading the window,
            * all the calls in this state are low-level OpenGL
            * calls to get everything running with the proper
            * settings and prefrences configured.
            **/
            INITIALIZING = 1,

            /**
            * This is the Engine State that it should be in most
            * of the time. In this state the programmer has the
            * most amount of controll over the game and what it
            * doing.
            **/
            RUNNING = 2,

            /**
            * At this state the engine has been told to close
            * one way or another. This is when everything should
            * get to a stopping point because it will soon be
            * removed from memory.
            **/
            STOPPING = 3,
        };

        /**
        * This is the current Engine State of the Engine in
        * real time and will only be modified by the Universe
        * itself.
        **/
        EngineState TheEngineState;

        /**
        *
        */
        const int FrameRate = 0;

        /**
        * This is the method used to set up the Universe. Since
        * The Singleton Pattern is being used here, this is the
        * closest thing to a constructor. The settings can only
        * inserted in this function one time, to change any
        * settings a diffrent method must be used.
        *
        * @returns true if successful.
        **/
        bool Initialize(
                unsigned int windowWidth = 800,
                unsigned int windowHeight = 600
        );

        /**
        *
        */
        void Start();

        /**
        *
        */
        void Pause();

        /**
        *
        */
        void Stop();

        LSEngine::GlobalSettings *Settings;
        //LastStandEngine::Dictionary *Dictionary;

    protected:

    private:

        /**
        * This is the Constructor for the Universe, it is put
        * in private to re-insure that only one Universe can be
        * in existence at one time. This is the Singleton Pattern
        * and is used on this class very strictly.
        **/
        Universe();

        ~Universe();

        static Universe *x_instance;

        /**
        *
        */
        void MainLoop();

        SDL_Surface *x_Surface;

        SDL_Window *x_Window;

        SDL_Renderer *x_Renderer;
    };
}
#endif
