//
// Created by Mikhail Swift on 2/11/16.
//

#ifndef GAMEENGINE_INPUT_H
#define GAMEENGINE_INPUT_H

#include <memory>
#include "Keyboard.h"
#include "Mouse.h"

namespace GameEngine
{
    namespace Input
    {
        class Input
        {
        public:
            virtual ~Input();

        protected:
            std::unique_ptr<Mouse> mouse;
            std::unique_ptr<Keyboard> keyboard;
            Input();
        };

        class SDLInput : public Input
        {
        };
    }
}

#endif //GAMEENGINE_INPUT_H
