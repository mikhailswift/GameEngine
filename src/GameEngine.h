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
        void start();
        void stop();
        bool doLoop();
    private:
        GameWindow *window;
        Game::Game *game;
    };
}

#endif //GAMEENGINE_GAMEENGINE_H
