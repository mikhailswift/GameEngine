//
// Created by Mikhail Swift on 11/14/15.
//

#include "GameEngine.h"

namespace GameEngine
{
    Engine::Engine(GameWindow *w, Game::Game *g)
    {
        window = std::unique_ptr<GameWindow>(w);
        game = std::unique_ptr<Game::Game>(g);
    }

    Engine::~Engine()
    {
        game.reset();
        window.reset();
        SDL_Quit();
    }

    void Engine::start()
    {
        window.get()->start();
        while (true)
        {
            if (!doLoop())
                break;
        }

        stop();
    }

    void Engine::stop()
    {
        window.get()->stop();
    }

    bool Engine::doLoop()
    {
        SDL_Event event;
        while(SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
                return false;
        }

        window->render(game.get());
        SDL_Delay(2);
        return true;
    }
}
