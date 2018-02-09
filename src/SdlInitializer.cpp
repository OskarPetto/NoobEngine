#include "../include/SdlInitializer.h"  

namespace SdlWrapper
{
    unsigned int SdlInitializer::sInstanceCount = 0;

    SdlInitializer::SdlInitializer()
    {
        if (sInstanceCount == 0)
        {
            checkReturnValue(SDL_Init(SDL_INIT_VIDEO));

            int imgFlags = IMG_INIT_JPG | IMG_INIT_PNG;
            int imgInitted = IMG_Init(imgFlags);
            checkReturnValue(imgInitted - imgFlags);
        }

        sInstanceCount++;
    
    }

    SdlInitializer::~SdlInitializer()
    {   
        sInstanceCount--;

        if (sInstanceCount == 0)
        {
            IMG_Quit();
            SDL_Quit();
        }
    
    }
}