//
// Created by Mikhail Swift on 11/15/15.
//

#include <SDL_timer.h>
#include "Time.h"

namespace GameEngine
{
    const engineTime_t SECOND = 1000;

    engineTime_t GetTime()
    {
        return SDL_GetTicks();
    }
}
