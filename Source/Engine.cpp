#include <Engine.h>

namespace LSEngine
{
    bool Engine::Quit = false;
    float Engine::DeltaTime = 0.0;
    Window* Engine::GameWindow = nullptr;

    Engine& Engine::GetInstance()
    {
        static Engine instance;
        return instance;
    }
    
    bool Engine::Initialize()
    {
        // Initialize Loggers
/*
        try
        {
            std::vector<spdlog::sink_ptr> sinks;
            sinks.push_back(std::make_shared<spdlog::sinks::stdout_sink_st>());
            sinks.push_back(std::make_shared<spdlog::sinks::rotating_file_sink_mt>("Somnia", "log", 1024 * 1024, 5, false));
            auto combined_logger = std::make_shared<spdlog::logger>("Somnia", begin(sinks), end(sinks));
            spdlog::register_logger(combined_logger);
            spdlog::set_level(spdlog::level::debug);
        }
        catch (const spdlog::spdlog_ex& ex)
        {
            std::cout << "Log failed: " << ex.what() << std::endl;
        }

        log->info("Loading Libraries");

        // Initialize Language
        LANGUAGE.setLanguage(Language::ENGLISH);
        log->info("Language: ") << LANGUAGE.get("test");
        auto log = spdlog::get("Somnia");
        */

        // Initialize SDL2
        if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
        {
//            log->critical("SDL2 Failed to initialize!");
//            log->error(SDL_GetError());
            return false;
        }
        else
        {
//            log->debug("SDL2 Loaded");
        }
    
        // Initialize SDL2 Image
        if ((IMG_Init(IMG_INIT_JPG) & IMG_INIT_JPG) || (IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG) || (IMG_Init(IMG_INIT_TIF) & IMG_INIT_TIF))
        {
            //log->debug("SDL2 Image Loaded");
        }
        else
        {
            //log->critical("SDL2 Image Failed to initialize!");
            //log->error(IMG_GetError());
            return false;
        }
    
        // Initialize SDL2 Mixer
        if ((Mix_Init(MIX_INIT_FLAC) & MIX_INIT_FLAC) || (Mix_Init(MIX_INIT_MODPLUG) & MIX_INIT_MODPLUG) || (Mix_Init(MIX_INIT_MP3) & MIX_INIT_MP3) || (Mix_Init(MIX_INIT_OGG) & MIX_INIT_OGG))
        {
            //log->debug("SDL2 Mixer Loaded");
        }
        else
        {
            //log->critical("SDL2 Mixer Failed to initialize!");
            //log->error(Mix_GetError());
            return false;
        }
    
        // Initialize SDL2 Net
        if (SDLNet_Init() < 0)
        {   
            //log->critical("SDL2 Net Failed to initialize!");
            //log->error(SDLNet_GetError());
            return false;
        }
        else
        {
            //log->debug("SDL2 Net Loaded");
        }
    
        // Initialize SDL2 TTF
        if (TTF_Init() < 0)
        {
            //log->critical("SDL2 TTF Failed to initialize!");
            //log->error(TTF_GetError());
            return false;
        }
        else
        {
            //log->debug("SDL2 TTF Loaded");
        }

        // TODO : Fix this fucking block of code (linux)
        /* Initialize Steamworks SDK
        if (SteamAPI_Init())
        {
            log->debug("Steamworks SDK Loaded");
        }
        else
        {
            log->critical("Steamworks SDK Failed to initialize!");
            return false;
        }
        log->info("All Libraries have been Loaded");

        log->info("Creating launcher splash screen");
        // Create Launcher Window
        GameWindow = new Window("Somnia", 605, 256, true);
        
        SDL_Surface* bg = SDL_ConvertSurface(
            IMG_Load("Resources/Engine/launcher.jpg"),
            SDL_GetWindowSurface(GameWindow->SDLWindow)->format,
            0
        );
        if (!bg)
        {
            log->error(SDL_GetError());
            log->error("The Launcher Background Image did not load!");
        }
        log->info("success");
        SDL_BlitSurface(bg, NULL, SDL_GetWindowSurface(GameWindow->SDLWindow), NULL);
        SDL_FreeSurface(bg);
        SDL_UpdateWindowSurface(GameWindow->SDLWindow);
        SDL_Delay(2000);
        log->info("Closing Splash Screen...");
        log->info("Creating Game Window...");
        
        // Create Game Window
        delete GameWindow;
        */
        GameWindow = new Window("Somnia");

        // TODO : Add Loading Videos here

        return true; // Everything has been initialized successfully
    }

    Engine::Engine() {}

    Engine::~Engine() {}
}