#pragma once

#include "Exception.h"
#include <string>
#include <SDL2/SDL_image.h>

namespace SdlWrapper
{
    class Texture
    {
        public:
        Texture(UniqueRenderer& renderer, const std::string& path);

        SharedTexture getTexture() const;
        int getWidth() const;
        int getHeight() const;

        private:
        SharedTexture mTexture{nullptr}; 

        int mWidth;
        int mHeight;
    };

}