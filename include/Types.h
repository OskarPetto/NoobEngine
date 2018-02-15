#pragma once

#include <memory>
#include <SDL2/SDL.h>

namespace SdlWrapper
{
    struct SdlDeleter
    {
        void operator()(SDL_Window* ptr) const 
        {   
            if (ptr) 
            {
                SDL_DestroyWindow(ptr);
            }
        }

        void operator()(SDL_Renderer* ptr) const 
        {
            if (ptr) 
            {
                SDL_DestroyRenderer(ptr);
            }
        }
        
        void operator()(SDL_Texture* ptr) const 
        {
            if (ptr) 
            {
                SDL_DestroyTexture(ptr);
            }
        }

        void operator()(SDL_Surface* ptr) const 
        {
            if (ptr) 
            {
                SDL_FreeSurface(ptr);
            }
        }
    };

    using UniqueWindow = std::unique_ptr<SDL_Window, SdlDeleter>;
    using UniqueRenderer = std::unique_ptr<SDL_Renderer, SdlDeleter>;
    //using UniqueTexture = std::unique_ptr<SDL_Texture, SdlDeleter>;
    using UniqueSurface = std::unique_ptr<SDL_Surface, SdlDeleter>;

    // template <class T>
    // class SharedSdlRessource
    // {
    //     public:
    //     explicit SharedSdlRessource(T* t = nullptr)
    //         : ptr(t, SdlDeleter()) {}
    
    //     void reset(T* t = nullptr)
    //     {
    //         ptr.reset(t, SdlDeleter());
    //     }

    //     T *get() const
    //     {
    //         return ptr.get();
    //     }

    //     private:
    //     std::shared_ptr<T> ptr;
    // };

    // using SharedWindow = SharedSdlRessource<SDL_Window>;
    // using SharedRenderer = SharedSdlRessource<SDL_Renderer>;
    // using SharedTexture = SharedSdlRessource<SDL_Texture>;
    // using SharedSurface = SharedSdlRessource<SDL_Surface>;

}