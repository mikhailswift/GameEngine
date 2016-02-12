//
// Created by Mikhail Swift on 11/14/15.
//

#ifndef GAMEENGINE_GAMEENGINE_H
#define GAMEENGINE_GAMEENGINE_H

#include "GameWindow.h"
#include "Game.h"
#include "Input/Input.h"

namespace GameEngine
{
    class Engine
    {
    public:
        Engine(GameWindow* window, Game::Game* game, Input::Input* input, uint16_t fpsCap);
        ~Engine();
        void start();
        void pause(bool unpause = false);
        void stop();
    private:
        const double_t FrameTime;
        bool isRunning;
        bool isPaused;
        double_t fpsCap;
        std::unique_ptr<GameWindow> window;
        std::unique_ptr<Game::Game> game;
        std::unique_ptr<Input::Input> input;
        void run();
        void processEvents();
    };
}

#endif //GAMEENGINE_GAMEENGINE_H
