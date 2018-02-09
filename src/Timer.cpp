#include "../include/Timer.h"

namespace SdlWrapper
{
    void Timer::start()
    {
        mPaused = false;
        mStartTicks = SDL_GetTicks();
        mPausedTicks = mStartTicks;
    }

    void Timer::pause()
    {
        if (mPaused)
            return;

        mPaused = true;
        mPausedTicks = SDL_GetTicks();
    }

    void Timer::resume()
    {
        if (!mPaused)
            return;
        
        mPaused = false;
        mStartTicks += (SDL_GetTicks() - mPausedTicks);
    }

    Uint32 Timer::getTime()
    {
        if (mPaused)
            return mPausedTicks - mStartTicks;

        return SDL_GetTicks() - mStartTicks;
    }
}