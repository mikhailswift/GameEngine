//
// Created by Mikhail Swift on 11/14/15.
//

#include <string>
#include "GameWindow.h"

namespace GameEngine
{
    int GameWindow::getHeight() { return height; }
    int GameWindow::getWidth() { return width; }
    int GameWindow::getX() { return x; }
    int GameWindow::getY() { return y; }
    char* GameWindow::getTitle() { return title; }

    SDLGameWindow::SDLGameWindow(char *t, int width, int height)
    {
        if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
            handleError();
        title = t;
        window = std::unique_ptr<SDL_Window, SDL_Deleter>(SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_HIDDEN));
    }

    SDLGameWindow::~SDLGameWindow()
    {
        SDL_DestroyWindow(window.get());
    }

    void SDLGameWindow::handleError()
    {
        std::string error = "Error: ";
        error.append(SDL_GetError());
        throw error;
    }

    void SDLGameWindow::render(Game::Game *game)
    {
        SDL_Surface *surface = SDL_GetWindowSurface(window.get());
        SDL_FillRect(surface, NULL, SDL_MapRGB(surface->format, 0xFF, 0xFF, 0xFF));
        SDL_UpdateWindowSurface(window.get());
    }

    void SDLGameWindow::start()
    {
        SDL_ShowWindow(window.get());
    }

    void SDLGameWindow::stop()
    {
        SDL_HideWindow(window.get());
    }
}