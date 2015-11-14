//
// Created by Mikhail Swift on 11/14/15.
//

#include <SDL2/SDL.h>

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

namespace GameEngine
{
    void HandleError();
}

int main()
{
    SDL_Window *window = NULL;
    SDL_Surface *surface = NULL;
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        GameEngine::HandleError();
        return 0;
    }

    window = SDL_CreateWindow("tits", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (window == NULL)
    {
        GameEngine::HandleError();
        return 0;
    }

    surface = SDL_GetWindowSurface(window);
    SDL_FillRect(surface, NULL, SDL_MapRGB(surface->format, 0xFF, 0xFF, 0xFF));
    SDL_UpdateWindowSurface(window);
    SDL_Delay(2000);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}

namespace GameEngine
{
    void HandleError()
    {
        printf("SHIT! %s", SDL_GetError());
    }
}