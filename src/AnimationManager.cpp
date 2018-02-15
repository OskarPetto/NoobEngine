#include "../include/AnimationManager.h"

namespace SdlWrapper
{
    void AnimationManager::loadAnimation(const std::string& name, const int framesPerRect, 
                                         const std::vector<SDL_Rect>& rects)
    {
        auto animationIterator = mAnimations.find(name);
        if (animationIterator != mAnimations.end())
            return;

        Animation animation(framesPerRect, rects);
        mAnimations.insert(std::make_pair(name, animation));

    }

    const SDL_Rect& AnimationManager::getNextRect(const std::string& name)
    {
        auto animationIterator = mAnimations.find(name);
        if (animationIterator == mAnimations.end())
            throw std::runtime_error(name + " was not loaded\n");


        return animationIterator->second.getNextRect();
        
    }

}