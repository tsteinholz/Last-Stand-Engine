#pragma once
#ifndef SOMNIA_ENGINE_GRAPHICS_WINDOW_H
#define SOMNIA_ENGINE_GRAPHICS_WINDOW_H

#include <Graphics/Color.h>
//#include <Utils/Settings.h>

#include <string>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include <spdlog/spdlog.h>


namespace LSEngine
{
    class Window
    {
    public:

        Window(const std::string& title="Somnia", uint32_t width=0, uint32_t height=0, bool border = false);
        ~Window();
    
        SDL_Window* SDLWindow;
        SDL_Renderer* SDLRenderer;

    private:
    
        uint32_t Width;
        uint32_t Height;
        std::string Title;
        bool Border;
        bool FullScreen;
        bool Antialiasing;
        Uint8 SDLFlags;
        Uint8 SDLRenFlags;
    
        void LoadSettings();
        
        void Create();

        void Destroy();

        void SetFullScreen(bool val);

        void SetAntiAliasing(bool val);

        void SetIcon(const std::string& file = "Resources/Engine/somnia.png");
         
    };
}

#endif //SOMNIA_ENGINE_GRAPHICS_WINDOW_H