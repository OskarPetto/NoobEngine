#pragma once

#include <SDL2/SDL.h>

namespace SdlWrapper
{
    class Timer
    {
        public:
        void start();
        void pause();
        void resume();
        Uint32 getTime();

        private:
        bool mPaused;
        Uint32 mStartTicks{0};
        Uint32 mPausedTicks{0};
    };
}