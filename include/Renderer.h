#pragma once

#include "TextureManager.h"

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

        void loadTexture(const std::string& path);

        void clear(const SDL_Color& background);
        
        void drawTexture(const std::string& path, const SDL_Point& point, double scale);

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

    };
}