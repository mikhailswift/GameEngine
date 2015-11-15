//
// Created by Mikhail Swift on 11/14/15.
//

#include "GameEngine.h"
#include "Time.h"

namespace GameEngine
{
    Engine::Engine(GameWindow *window_, Game::Game *game_, double_t fpsCap_) : FrameTime(1.0/fpsCap_)
    {
        window = std::unique_ptr<GameWindow>(window_);
        game = std::unique_ptr<Game::Game>(game_);
        fpsCap = fpsCap_;
        isPaused = false;
        isRunning = false;
    }

    Engine::~Engine()
    {
        game.reset();
        window.reset();
        SDL_Quit();
    }

    void Engine::start()
    {
        if (isRunning)
            return;

        isRunning = true;
        window.get()->start();
        run();
    }

    void Engine::stop()
    {
        if (!isRunning)
            return;

        isRunning = false;
        window.get()->stop();
    }

    void Engine::pause(bool unpause)
    {
        isPaused = !unpause;
    }

    void Engine::run()
    {
        auto lastTime = GameEngine::GetTime();
        double_t unprocessedTime = 0;
        while (isRunning)
        {
            auto render = false;
            auto startTime = GameEngine::GetTime();
            auto passedTime = startTime - lastTime;
            lastTime = startTime;
            unprocessedTime += passedTime / (double_t)GameEngine::SECOND;
            while (unprocessedTime > FrameTime)
            {
                render = true;
                unprocessedTime -= FrameTime;
                processEvents();
                if (isPaused)
                    continue;

                // update game
            }
            if (render)
                window->render(game.get());
        }
    }

    void Engine::processEvents()
    {
        SDL_Event event;
        SDL_PollEvent(&event);
        switch (event.type)
        {
            case SDL_QUIT:
                stop();
                break;
            default:
                break;
        }
    }
}
