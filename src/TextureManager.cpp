#include "../include/TextureManager.h"

namespace SdlWrapper
{
    void TextureManager::loadTexture(UniqueRenderer& renderer, const std::string& path)
    {
        auto textureIterator = mTextures.find(path);
        if (textureIterator != mTextures.end())
            return;

        Texture texture(renderer, path);
        mTextures.insert(std::make_pair(path, texture));

    }

    Texture TextureManager::getTexture(UniqueRenderer& renderer, const std::string& path)
    {
        auto textureIterator = mTextures.find(path);
        if (textureIterator != mTextures.end())
            return textureIterator->second;

        Texture texture(renderer, path);
        mTextures.insert(std::make_pair(path, texture));

        return texture; 

    }
}