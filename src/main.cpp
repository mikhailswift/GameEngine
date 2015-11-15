//
// Created by Mikhail Swift on 11/14/15.
//

#include "GameWindow.h"
#include "GameEngine.h"

const uint16_t SCREEN_WIDTH = 640;
const uint16_t SCREEN_HEIGHT = 480;
const double_t FRAME_CAP = 5000L;

int32_t main(int argc, char **argv)
{
    try
    {
        std::unique_ptr<GameEngine::Engine> engine = std::unique_ptr<GameEngine::Engine>(
                new GameEngine::Engine(
                        new GameEngine::SDLGameWindow("Test", SCREEN_WIDTH, SCREEN_HEIGHT),
                        new Game::Game(),
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
