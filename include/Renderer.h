#pragma once

#include "TextureManager.h"
#include "AnimationManager.h"

namespace SdlWrapper
{
    enum class MessageType : Uint32
    {
        ERROR = SDL_MESSAGEBOX_ERROR,
        WARNING = SDL_MESSAGEBOX_WARNING,
        INFO = SDL_MESSAGEBOX_INFORMATION
    };

    enum class FillType : bool
    {
        FILLED,
        NONE
    };

    class Renderer
    {
        public:
        explicit Renderer(const std::string& title, Uint32 width, Uint32 height);

        void loadTexture(const std::string& path, SDL_bool enableColorKey, 
                         const SDL_Color& colorKey);

        void loadAnimation(const std::string& name, const int framesPerRect, 
                           const std::vector<SDL_Rect>& rects);

        void clear(const SDL_Color& background);

        void drawAnimation(const std::string& path, const std::string& name,
                           const SDL_Point& position, double scale, 
                           int angle, const SDL_RendererFlip flip);

        void drawTexture(const std::string& path, const SDL_Rect& src,
                         const SDL_Point& position, double scale, 
                         int angle, const SDL_RendererFlip flip);

        void drawRect(const SDL_Rect& rect, const SDL_Color& color, FillType filling);

        void drawLine(const SDL_Point& from, const SDL_Point& to, 
                      const SDL_Color& color);
        
        void drawPoint(const SDL_Point& point, const SDL_Color& color);

        void showMessage(MessageType type, const std::string& title, 
                         const std::string& message);
        
        void present();

        private:

        UniqueWindow mWindow;
        UniqueRenderer mRenderer;

        TextureManager mTextureManager;
        AnimationManager mAnimationManager;
    };
}