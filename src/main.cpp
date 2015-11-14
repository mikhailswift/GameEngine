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
        std::unique_ptr<GameEngine::GameWindow> window = std::unique_ptr<GameEngine::GameWindow>(new GameEngine::SDLGameWindow("Test", SCREEN_WIDTH, SCREEN_HEIGHT));
        std::unique_ptr<Game::Game> game = std::unique_ptr<Game::Game>(new Game::Game());
        std::unique_ptr<GameEngine::Engine> engine = std::unique_ptr<GameEngine::Engine>(new GameEngine::Engine(window.get(), game.get()));
        engine->start();
        return EXIT_SUCCESS;
    }
    catch (const char *msg)
    {
        printf("%s\n", msg);
        return EXIT_FAILURE;
    }
}
