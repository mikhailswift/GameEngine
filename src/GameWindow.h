//
// Created by Mikhail Swift on 11/14/15.
//

#ifndef GAMEENGINE_GAMEWINDOW_H
#define GAMEENGINE_GAMEWINDOW_H

#include <memory>
#include <SDL2/SDL.h>
#include "Game.h"

namespace GameEngine
{
    class GameWindow
    {
    protected:
        int width, height, x, y;
        char* title;
    public:
        virtual ~GameWindow();
        int getHeight();
        int getWidth();
        int getX();
        int getY();
        char* getTitle();
        // "rendering the game" may not make the most sense, but it's just a prototype for the moment
        virtual void render(Game::Game *game)=0;
        virtual void start() = 0;
        virtual void stop() = 0;
    };

    // SDL Specifics
    struct SDL_Deleter
    {
        void operator()(SDL_Window *window) const { SDL_DestroyWindow(window); }
    };

    class SDLGameWindow : public GameWindow
    {
    public:
        SDLGameWindow(char* title, int width, int height);
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
