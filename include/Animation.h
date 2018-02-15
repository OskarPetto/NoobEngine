#pragma once

#include "Exception.h"
#include <vector>
#include <string>

namespace SdlWrapper
{
    class Animation
    {
        public:
        Animation(const int framesPerRect, const std::vector<SDL_Rect>& rects);

        const SDL_Rect& getNextRect();

        private:

        int mFramesPerRect;
        int mCurrentRect;
        int mFrameCounter;
        const std::vector<SDL_Rect>& mRects;
    };

}

