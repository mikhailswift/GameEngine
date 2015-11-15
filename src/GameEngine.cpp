//
// Created by Mikhail Swift on 11/14/15.
//

#include "GameEngine.h"
#include "Time.h"

namespace GameEngine
{
    Engine::Engine(GameWindow *window_, Game::Game *game_, uint16_t fpsCap_) : FrameTime(1.0/(double_t)fpsCap_)
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
        uint16_t fps = 0;
        engineTime_t fpsTimer = 0;
        double_t unprocessedTime = 0;
        while (isRunning)
        {
            auto render = false;
            auto startTime = GameEngine::GetTime();
            auto passedTime = startTime - lastTime;
            lastTime = startTime;
            unprocessedTime += passedTime / (double_t)GameEngine::SECOND;
            fpsTimer += passedTime;
            while (unprocessedTime > FrameTime)
            {
                render = true;
                unprocessedTime -= FrameTime;
                processEvents();
                if (isPaused)
                    continue;

                // update game

                // if
                if (fpsTimer >= GameEngine::SECOND)
                {
                    std::cout << fps << std::endl;
                    fps = 0;
                    fpsTimer = 0;
                }
            }
            if (render)
            {
                fps++;
                window->render(game.get());
            }
            else
            {
                SDL_Delay(1);
            }
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
