//
// Created by Mikhail Swift on 11/14/15.
//

#include "GameWindow.h"
#include "GameEngine.h"

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

int main(int argc, char **argv)
{
    try
    {
        std::unique_ptr<GameEngine::Engine> engine = std::unique_ptr<GameEngine::Engine>(
                new GameEngine::Engine(
                        new GameEngine::SDLGameWindow("Test", SCREEN_WIDTH, SCREEN_HEIGHT),
                        new Game::Game()));
        engine->start();
        return EXIT_SUCCESS;
    }
    catch (const char *msg)
    {
        printf("%s\n", msg);
        return EXIT_FAILURE;
    }
}
