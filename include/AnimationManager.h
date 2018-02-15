#pragma once

#include "Animation.h"
#include <unordered_map>

namespace SdlWrapper
{

    class AnimationManager
    {
        public:
        void loadAnimation(const std::string& name, const int framesPerRect, 
                           const std::vector<SDL_Rect>& rects);
                            
        const SDL_Rect& getNextRect(const std::string& name);

        private:

        std::unordered_map<std::string, Animation> mAnimations;

    };

}