#include "../include/TextureManager.h"

namespace SdlWrapper
{
    void TextureManager::loadTexture(UniqueRenderer& renderer, const std::string& path, 
                                     SDL_bool enableColorKey, const SDL_Color& colorKey)
    {
        auto textureIterator = mTextures.find(path);
        if (textureIterator != mTextures.end())
            return;

        mTextures.insert(std::make_pair(path, std::unique_ptr<Texture>(new Texture(
                                              renderer, path, enableColorKey, colorKey))));

    }

    const Texture& TextureManager::getTexture(const std::string& path) const
    {
        auto textureIterator = mTextures.find(path);
        if (textureIterator == mTextures.end())
            throw std::runtime_error(path + " was not loaded\n");

        return *(textureIterator->second.get()); 
    }
}