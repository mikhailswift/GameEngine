//
// Created by Mikhail Swift on 11/14/15.
//

#include "GameWindow.h"
#include "GameEngine.h"

const uint16_t SCREEN_WIDTH = 640;
const uint16_t SCREEN_HEIGHT = 480;
const uint16_t FRAME_CAP = 5000;

int32_t main(int argc, char **argv)
{
    try
    {
        // todo: dependency injection?
        auto window = std::unique_ptr<GameEngine::GameWindow>(
                new GameEngine::SDLGameWindow("Test", SCREEN_WIDTH, SCREEN_HEIGHT));
        auto game = std::unique_ptr<Game::Game>(new Game::Game());
        auto input = std::unique_ptr<GameEngine::Input::SDLInput>(new GameEngine::Input::SDLInput());
        auto engine = std::unique_ptr<GameEngine::Engine>(
                new GameEngine::Engine(
                        window.get(),
                        game.get(),
                        input.get(),
                        FRAME_CAP));
        engine->start();
        return EXIT_SUCCESS;
    }
    catch (const char *msg)
    {
        printf("%s\n", msg);
        return EXIT_FAILURE;
    }
}
