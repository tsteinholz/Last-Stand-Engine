/*/-----------------------------------------------------------------------------------------------------------------/*/
/*/                                                                                                                 /*/
/*/                                 ______________________________________                                          /*/
/*/                        ________|                                      |_______                                  /*/
/*/                        \       |     This file is a part of the       |      /                                  /*/
/*/                         \      |    Last Stand Studio Game Engine     |     /                                   /*/
/*/                         /      |______________________________________|     \                                   /*/
/*/                        /__________)                                (_________\                                  /*/
/*/                                                                                                                 /*/
/*/                                    Copyright Last Stand Studio 2015                                             /*/
/*/                                                                                                                 /*/
/*/                                          The MIT License (MIT)                                                  /*/
/*/                                                                                                                 /*/
/*/                   Permission is hereby granted, free of charge, to any person obtaining a copy                  /*/
/*/                   of this software and associated documentation files (the "Software"), to deal                 /*/
/*/                   in the Software without restriction, including without limitation the rights                  /*/
/*/                   to use, copy, modify, merge, publish, distribute, sublicense, and/or sell                     /*/
/*/                   copies of the Software, and to permit persons to whom the Software is                         /*/
/*/                   furnished to do so, subject to the following conditions:                                      /*/
/*/                                                                                                                 /*/
/*/                   The above copyright notice and this permission notice shall be included in                    /*/
/*/                   all copies or substantial portions of the Software.                                           /*/
/*/                                                                                                                 /*/
/*/                   THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR                    /*/
/*/                   IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,                      /*/
/*/                   FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE                   /*/
/*/                   AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER                        /*/
/*/                   LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,                 /*/
/*/                   OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN                     /*/
/*/                   THE SOFTWARE.                                                                                 /*/
/*/                                                                                                                 /*/
/*/                                                                                                                 /*/
/*/-----------------------------------------------------------------------------------------------------------------/*/

#pragma once
#ifndef LSENGINE_GRAPHICS_WINDOW_H
#define LSENGINE_GRAPHICS_WINDOW_H

#include "Graphics/Color.h"
//#include <Utils/Settings.h>

#include <string>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>


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

#endif // LSENGINE_GRAPHICS_WINDOW_H