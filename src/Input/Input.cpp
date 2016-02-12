//
// Created by Mikhail Swift on 2/11/16.
//

#include "Input.h"
namespace GameEngine
{
    namespace Input
    {
        Input::Input()
        {
            mouse = std::unique_ptr<Mouse>(new Mouse());
            keyboard = std::unique_ptr<SDLKeyboard>(new Mouse());
        }
    }
}