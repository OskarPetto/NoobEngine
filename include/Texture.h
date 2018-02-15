#pragma once

#include "Exception.h"
#include <SDL2/SDL_image.h>
#include <string>

namespace SdlWrapper
{
    class Texture
    {
        public:
        explicit Texture(UniqueRenderer& renderer, const std::string& path, 
                         SDL_bool enableColorKey, const SDL_Color& colorKey);

        ~Texture();

        // No copying or moving allowed
        Texture(const Texture&) = delete;
        Texture(Texture&&) = delete;
        Texture& operator=(const Texture&) = delete;
        Texture& operator=(Texture&&) = delete;

        SDL_Texture *getTexture() const;
        int getWidth() const;
        int getHeight() const;

        private:
        SDL_Texture *mTexture; 

        int mWidth;
        int mHeight;

    };

}