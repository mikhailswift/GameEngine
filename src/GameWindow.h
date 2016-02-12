//
// Created by Mikhail Swift on 11/14/15.
//

#ifndef GAMEENGINE_GAMEWINDOW_H
#define GAMEENGINE_GAMEWINDOW_H

#include <memory>
#include <SDL2/SDL.h>
#include <iostream>
#include "Game.h"

namespace GameEngine
{
    class GameWindow
    {
    public:
        virtual ~GameWindow();
        uint16_t getHeight();
        uint16_t getWidth();
        uint16_t getX();
        uint16_t getY();
        std::string getTitle();
        virtual void start() = 0;
        virtual void stop() = 0;
        virtual void render(Game::Game *game) = 0;
    protected:
        uint16_t width, height, x, y;
        std::string title;
    };

    // SDL Specifics
    struct SDL_Deleter
    {
        void operator()(SDL_Window *window) const { SDL_DestroyWindow(window); }
    };

    class SDLGameWindow : public GameWindow
    {
    public:
        SDLGameWindow(std::string title, uint16_t width, uint16_t height);
        ~SDLGameWindow();
        void render(Game::Game *game);
        void start();
        void stop();
    private:
        std::unique_ptr<SDL_Window, SDL_Deleter> window;
        void handleError();
    };
}
#endif //GAMEENGINE_GAMEWINDOW_H
