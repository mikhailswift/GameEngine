//
// Created by Mikhail Swift on 11/14/15.
//

#include <SDL2/SDL.h>
#include <memory>
#include <iostream>

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;


namespace GameEngine
{
    struct SDL_Deleter
    {
        void operator()(SDL_Window *window) const { SDL_DestroyWindow(window); }
    };

    class Engine
    {
    public:
        Engine();
        void Start();
        void Stop();
        bool DoLoop();
    private:
        std::unique_ptr<SDL_Window, SDL_Deleter> _window;
        void HandleError();
    };

    Engine::Engine()
    {
        if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
            HandleError();

        _window = std::unique_ptr<SDL_Window, SDL_Deleter>(
                SDL_CreateWindow("Test", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_HIDDEN));
    }

    void Engine::Start()
    {
        if (_window == NULL)
            HandleError();

        SDL_ShowWindow(_window.get());
    }

    void Engine::Stop()
    {
        SDL_HideWindow(_window.get());
    }

    bool Engine::DoLoop()
    {
        SDL_Surface *surface = SDL_GetWindowSurface(_window.get());
        SDL_FillRect(surface, NULL, SDL_MapRGB(surface->format, 0xFF, 0xFF, 0xFF));
        SDL_UpdateWindowSurface(_window.get());
        SDL_Delay(5000);
        return false;
    }

    void Engine::HandleError()
    {
        std::string error = "Error: ";
        error = error.append(SDL_GetError());
        throw error;
    }
}

int main(int argc, char **argv)
{
    try
    {
        std::unique_ptr<GameEngine::Engine> engine = std::unique_ptr<GameEngine::Engine>(new GameEngine::Engine());
        engine->Start();
        while (true) {
            bool shouldContinue = engine->DoLoop();
            if (!shouldContinue)
                break;
        }

        engine->Stop();
        return EXIT_SUCCESS;
    }
    catch (const char *msg)
    {
        printf("%s\n", msg);
        return EXIT_FAILURE;
    }
}
