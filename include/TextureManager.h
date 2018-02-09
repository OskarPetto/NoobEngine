#pragma once

#include "Texture.h"
#include <unordered_map>

namespace SdlWrapper
{
    class TextureManager
    {
        public:
        void loadTexture(UniqueRenderer& renderer, 
                            const std::string& path);
                            
        Texture getTexture(UniqueRenderer& renderer, 
                            const std::string& path);

        private:
        std::unordered_map<std::string, Texture> mTextures;
    };
}