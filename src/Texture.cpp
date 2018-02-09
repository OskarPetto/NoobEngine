#include "../include/Texture.h"

namespace SdlWrapper
{
    Texture::Texture(UniqueRenderer& renderer, const std::string& path)
    {
        UniqueSurface surface{IMG_Load(path.c_str())};

        checkPointer(surface.get());

        mTexture.reset(SDL_CreateTextureFromSurface(renderer.get(), surface.get()));

        checkPointer(mTexture.get());

        checkReturnValue(SDL_QueryTexture(mTexture.get(), nullptr, nullptr, &mWidth, &mHeight));

    }

    SharedTexture Texture::getTexture() const
    {
        return mTexture;
    }

    int Texture::getWidth() const
    {
        return mWidth;
    }

    int Texture::getHeight() const
    {
        return mHeight;
    }

}