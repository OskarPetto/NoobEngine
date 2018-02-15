#include "../include/Animation.h"

namespace SdlWrapper
{
    Animation::Animation(const int framesPerRect, const std::vector<SDL_Rect>& rects)
        : mFramesPerRect(framesPerRect > 1 ? framesPerRect : 1), mCurrentRect(0), 
          mFrameCounter(0), mRects(rects) {}
        
    
    const SDL_Rect& Animation::getNextRect()
    {   
        int returnIndex = mCurrentRect;
        
        mFrameCounter++;
        
        if (mFrameCounter == mFramesPerRect)
        {
            mCurrentRect = (mCurrentRect + 1) % mRects.size();
            mFrameCounter = 0;
        }
        return mRects[returnIndex];
    }

    
}