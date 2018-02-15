#pragma once

#include "Texture.h"
#include <unordered_map>

namespace SdlWrapper
{
    class TextureManager
    {
        public:
        void loadTexture(UniqueRenderer& renderer, const std::string& path,
                         SDL_bool enableColorKey, const SDL_Color& colorKey);
                            
        const Texture& getTexture(const std::string& path) const;

        private:
        std::unordered_map<std::string, std::unique_ptr<Texture>> mTextures;
    };
}