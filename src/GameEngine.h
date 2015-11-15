//
// Created by Mikhail Swift on 11/14/15.
//

#ifndef GAMEENGINE_GAMEENGINE_H
#define GAMEENGINE_GAMEENGINE_H

#include "GameWindow.h"
#include "Game.h"

namespace GameEngine
{
    class Engine
    {
    public:
        Engine(GameWindow *window, Game::Game* game);
        ~Engine();
        void start();
        void stop();
        bool doLoop();
    private:
        std::unique_ptr<GameWindow> window;
        std::unique_ptr<Game::Game> game;
    };
}

#endif //GAMEENGINE_GAMEENGINE_H
