#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "Exception.h"

namespace SdlWrapper
{

    class SdlInitializer
    {
        public:
        SdlInitializer();
        ~SdlInitializer();

        private:
        static unsigned int sInstanceCount;

    };
}