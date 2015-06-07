#include "Universe.h"

Universe* Universe::x_instance = NULL;

Universe::Universe ()
{
    x_EngineState = STARTING;

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
    if (x_EngineState == RUNNING)
    {
        return false;
    }
    x_EngineState = INITIALIZING;

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
    }

    x_EngineState = RUNNING;
    return true;
}

void Universe::Start ()
{

}

void Universe::Pause ()
{

}

void Universe::Stop ()
{

}

void Universe::Destroy()
{

}