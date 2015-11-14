//
// Created by Mikhail Swift on 11/14/15.
//

#include "GameEngine.h"

namespace GameEngine
{
    Engine::Engine(GameWindow *w, Game::Game *g)
    {
        window = w;
        game = g;
    }

    void Engine::start()
    {
        window->start();
        while (true)
        {
            if (!doLoop())
                break;
        }

        stop();
    }

    void Engine::stop()
    {
        window->stop();
    }

    bool Engine::doLoop()
    {
        /*SDL_Event *event;
        while(SDL_PollEvent(event))
        {
            if (event-> type == SDL_QUIT)
                return false;
        }*/

        window->render(game);
        SDL_Delay(5000);
        return false;
    }
}
