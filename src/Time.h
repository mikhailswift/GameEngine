//
// Created by Mikhail Swift on 11/15/15.
//

#ifndef GAMEENGINE_TIME_H
#define GAMEENGINE_TIME_H

namespace GameEngine
{
    typedef uint32_t engineTime_t;

    extern const engineTime_t SECOND;

    extern engineTime_t GetTime();

    extern engineTime_t GetDelta();
}

#endif //GAMEENGINE_TIME_H
