#include "Universe.h"

Universe* Universe::x_instance = NULL;

Universe::Universe ()
{
    TheEngineState = STARTING;

    //Settings


    //Objects


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

    Utils::Log("INFO: SDL Version : ");

    if ( SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_JOYSTICK) < 0 )
    {
        Utils::LogError("SDL could not initialize! SDL ERROR: ");SDL_GetError();
        SDL_Quit();
    }
    else
    {
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
