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

#include <Graphics/Window.h>

namespace LSEngine
{
    Window::Window(const std::string& title, uint32_t width, uint32_t height, bool border)
    : Title(title), Width(width), Height(height), Border(border)
    { Create(); }

    Window::~Window() 
    { Destroy(); }

    void Window::LoadSettings()
    {
        //SETTINGS.Load();
        if (Border)
        {
            FullScreen = false;
            SDLFlags = SDL_WINDOW_BORDERLESS;
        }
        else
        {
            //FullScreen = SETTINGS.GetFullscreen();
            SDLFlags = FullScreen ? SDL_WINDOW_FULLSCREEN : SDL_WINDOW_SHOWN;
            //Width = SETTINGS.GetWidth();
            //Height = SETTINGS.GetHeight();
        }
        //Antialiasing = SETTINGS.GetAA();
        SDLRenFlags = Antialiasing ? SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC : SDL_RENDERER_ACCELERATED;
    }

    void Window::Create()
    {
        LoadSettings();
        //auto log = spdlog::get("Somnia");
        SDLWindow = SDL_CreateWindow(
            Title.c_str(),
            SDL_WINDOWPOS_CENTERED,
            SDL_WINDOWPOS_CENTERED,
            Width,
            Height,
            SDLFlags
            );
        //if (!SDLWindow) { log->critical(SDL_GetError()); }

        SDLRenderer = SDL_CreateRenderer(SDLWindow, -1, SDLRenFlags);
        //if (!SDLRenderer) { log->critical(SDL_GetError()); }

        LSEngine::Color bg = LSEngine::Color(0x7F141F);
        SDL_SetRenderDrawColor(SDLRenderer, bg.R(), bg.G(), bg.B(), bg.A());
        SDL_RenderSetLogicalSize(SDLRenderer, Width, Height);

        SetIcon();
    }

    void Window::Destroy()
    {
        if (SDLRenderer)
        {
            SDL_DestroyRenderer(SDLRenderer);
            SDLRenderer = nullptr;
        }
        if (SDLWindow)
        {
            SDL_DestroyWindow(SDLWindow);
            SDLWindow = nullptr;
        }
    }

    void Window::SetFullScreen(bool val)
    {
        if (FullScreen == val) return;
        Destroy();
        //SETTINGS.SetFullscreen(val);
        Create();
    }

    void Window::SetAntiAliasing(bool val)
    {
        if (Antialiasing == val) return;
        Destroy();
        //SETTINGS.SetAA(val);
        Create();
    }

    void Window::SetIcon(const std::string & file)
    {
        SDL_Surface* ico = IMG_Load(file.c_str());
        if (!ico) 
        {
            //auto log = spdlog::get("Somnia");
            //log->error(IMG_GetError());
        }

        SDL_SetWindowIcon(SDLWindow, ico);
        SDL_FreeSurface(ico);
    }
}