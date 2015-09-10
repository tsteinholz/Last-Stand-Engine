#pragma once
#ifndef SOMNIA_ENGINE_ENGINE_H
#define SOMNIA_ENGINE_ENGINE_H

#include <Graphics/Window.h>
//#include <Language/Language.h>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_net.h>
#include <SDL2/SDL_ttf.h>

//#include <Steam/steam_api.h>

#define ENGINE LSEngine::Engine::GetInstance()

namespace LSEngine
{
    class Engine
    {
    public:

        static Engine& GetInstance();
    
        enum State
        {
            INITIALIZING,
            EXECUTING,
            HALTING,
        };

        bool Initialize();

        static bool Quit;

        static float DeltaTime;
        
        static Window* GameWindow;

    private:
        Engine();
        ~Engine();
        Engine(const Engine& other) = delete;
        Engine& operator=(const Engine&) = delete;
    };
}

#endif //SOMNIA_ENGINE_ENGINE_H