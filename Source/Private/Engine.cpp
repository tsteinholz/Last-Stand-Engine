#include "Engine.h"

namespace LSEngine
{
    bool Engine::Quit = false;
    float Engine::DeltaTime = 0.0;
    Window* Engine::GameWindow = 0;

    Engine& Engine::GetInstance()
    {
        static Engine instance;
        return instance;
    }

    bool Engine::Initialize()
    {
        // TODO : Initialize Loggers
        //try
        //{
            //std::vector<spdlog::sink_ptr> sinks;
            //sinks.push_back(std::make_shared<spdlog::sinks::stdout_sink_st>());
            //sinks.push_back(std::make_shared<spdlog::sinks::rotating_file_sink_mt>("LSEngine", "log", 1024 * 1024, 5, false));
            //auto combined_logger = std::make_shared<spdlog::logger>("LSEngine", begin(sinks), end(sinks));
            //spdlog::register_logger(combined_logger);
            //spdlog::set_level(spdlog::level::debug);
        //}
        //catch (const spdlog::spdlog_ex& ex)
        {
            //std::cout << "Log failed: " << ex.what() << std::endl;
        }
        //auto log = spdlog::get("Somnia");

        // TODO : Initialize Language

        // TODO : Initialize Settings

        // Initialize SDL2
        if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
        {
            // log->critical("SDL2 Failed to initialize!");
            // log->error(SDL_GetError());
            return false;
        }
        else
        {
            //log->debug("SDL2 Loaded");
        }

        // Initialize SDL2 Image
        if ((IMG_Init(IMG_INIT_JPG) & IMG_INIT_JPG) || (IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG) || (IMG_Init(IMG_INIT_TIF) & IMG_INIT_TIF))
        {
            // log->debug("SDL2 Image Loaded");
        }
        else
        {
            // log->critical("SDL2 Image Failed to initialize!");
            // log->error(IMG_GetError());
            return false;
        }

        // Initialize SDL2 Mixer
        if ((Mix_Init(MIX_INIT_FLAC) & MIX_INIT_FLAC)       ||
            (Mix_Init(MIX_INIT_MODPLUG) & MIX_INIT_MODPLUG) ||
            (Mix_Init(MIX_INIT_MP3) & MIX_INIT_MP3)         ||
            (Mix_Init(MIX_INIT_OGG) & MIX_INIT_OGG))
        {
            // log->debug("SDL2 Mixer Loaded");
        }
        else
        {
            // log->critical("SDL2 Mixer Failed to initialize!");
            // log->error(Mix_GetError());
            return false;
        }

        // Initialize SDL2 Net
        if (SDLNet_Init() < 0)
        {
            // log->critical("SDL2 Net Failed to initialize!");
            // log->error(SDLNet_GetError());
            return false;
        }
        else
        {
            // log->debug("SDL2 Net Loaded");
        }

        // Initialize SDL2 TTF
        if (TTF_Init() < 0)
        {
            // log->critical("SDL2 TTF Failed to initialize!");
            // log->error(TTF_GetError());
            return false;
        }
        else
        {
            // log->debug("SDL2 TTF Loaded");
        }

        // log->info("All Libraries have been Loaded");

        return true; // Everything has been initialized successfully
    }

    Engine::Engine() { }

    Engine::~Engine() { }
}
