//
// Created by Mikhail Swift on 11/14/15.
//

#include "GameWindow.h"

namespace GameEngine
{
    GameWindow::~GameWindow() {  }
    uint16_t GameWindow::getHeight() { return height; }
    uint16_t GameWindow::getWidth() { return width; }
    uint16_t GameWindow::getX() { return x; }
    uint16_t GameWindow::getY() { return y; }
    std::string GameWindow::getTitle() { return title; }

    SDLGameWindow::SDLGameWindow(std::string title_, uint16_t width_, uint16_t height_)
    {
        if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
            handleError();
        title = title_;
        width = width_;
        height = height_;
        window = std::unique_ptr<SDL_Window, SDL_Deleter>(SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_HIDDEN));
    }

    SDLGameWindow::~SDLGameWindow()
    {
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