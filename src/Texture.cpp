#include "../include/Texture.h"

namespace SdlWrapper
{
    Texture::Texture(UniqueRenderer& renderer, const std::string& path, 
                     SDL_bool enableColorKey, const SDL_Color& colorKey)
    {
        UniqueSurface surface{IMG_Load(path.c_str())};

        checkPointer(surface.get());

        checkReturnValue(SDL_SetColorKey(surface.get(), enableColorKey,
                                             SDL_MapRGB(surface.get()->format, 
                                             colorKey.r, colorKey.g, colorKey.b)));

        mTexture = SDL_CreateTextureFromSurface(renderer.get(), surface.get());

        checkPointer(mTexture);

        checkReturnValue(SDL_QueryTexture(mTexture, nullptr, nullptr, &mWidth, &mHeight));

    }

    Texture::~Texture()
    {
        SdlDeleter()(mTexture);
    }

    SDL_Texture *Texture::getTexture() const
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