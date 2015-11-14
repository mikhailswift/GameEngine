//
// Created by Mikhail Swift on 11/14/15.
//

#include <SDL2/SDL.h>
#include <memory>

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

namespace GameEngine
{
    void HandleError()
    {
        printf("Error: %s", SDL_GetError());
    }

    struct SDL_Deleter
    {
        void operator()(SDL_Window *window) const { SDL_DestroyWindow(window); }
    };
}

int main()
{
    std::unique_ptr<SDL_Window, GameEngine::SDL_Deleter> window;
    SDL_Surface *surface = NULL;
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        GameEngine::HandleError();
        return 0;
    }

    window = std::unique_ptr<SDL_Window, GameEngine::SDL_Deleter>
            (SDL_CreateWindow("Test", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN));
    if (window == NULL)
    {
        GameEngine::HandleError();
        return 0;
    }

    surface = SDL_GetWindowSurface(window.get());
    SDL_FillRect(surface, NULL, SDL_MapRGB(surface->format, 0xFF, 0xFF, 0xFF));
    SDL_UpdateWindowSurface(window.get());
    SDL_Delay(2000);
    SDL_Quit();
    return 0;
}
