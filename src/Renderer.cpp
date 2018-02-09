#include "../include/Renderer.h"


namespace SdlWrapper
{
    Renderer::Renderer(const std::string& title, Uint32 width, Uint32 height)
        : mWindow()
    {
        
        mWindow.reset(SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                                   width, height, SDL_WINDOW_SHOWN));

        checkPointer(mWindow.get());

        mRenderer.reset(SDL_CreateRenderer(mWindow.get(), -1, 0));

        checkPointer(mRenderer.get());

    }

    void Renderer::loadTexture(const std::string& path)
    {
        mTextureManager.loadTexture(mRenderer, path);
    }

    void Renderer::clear(const SDL_Color& background)
    {
        checkReturnValue(SDL_SetRenderDrawColor(mRenderer.get(), background.r, 
                                                background.g, background.b, 
                                                background.a));

        checkReturnValue(SDL_RenderClear(mRenderer.get()));
    }

    void Renderer::drawTexture(const std::string& path, const SDL_Point& point, double scale)
    {
        if (scale <= 0)
            return;
            
        Texture texture = mTextureManager.getTexture(mRenderer, path);  

        SDL_Rect src{};
        SDL_Rect dst{};


        src.w = texture.getWidth();
        src.h = texture.getHeight();

        dst.x = point.x;
        dst.y = point.y;

        dst.w = (int)(texture.getWidth() * scale);
        dst.h = (int)(texture.getHeight() * scale);

        checkReturnValue(SDL_RenderCopy(mRenderer.get(), texture.getTexture().get(), &src, &dst));

    }

    void Renderer::drawRect(const SDL_Rect& rect, const SDL_Color& color, 
                            FillType filling)
    {
        checkReturnValue(SDL_SetRenderDrawColor(mRenderer.get(), color.r, color.g, 
                                                color.b, color.a));
        
        checkReturnValue(SDL_RenderDrawRect(mRenderer.get(), &rect));

        if (filling == FillType::FILLED)
            checkReturnValue(SDL_RenderFillRect(mRenderer.get(), &rect));
    }

    void Renderer::drawLine(const SDL_Point& from, const SDL_Point& to, 
                            const SDL_Color& color)
    {
        checkReturnValue(SDL_SetRenderDrawColor(mRenderer.get(), color.r, color.g, 
                                        color.b, color.a));

        checkReturnValue(SDL_RenderDrawLine(mRenderer.get(), from.x, from.y, to.x, to.y));
    }

    void Renderer::drawPoint(const SDL_Point& point, const SDL_Color& color)
    {
        checkReturnValue(SDL_SetRenderDrawColor(mRenderer.get(), color.r, color.g, 
                                                color.b, color.a));

        checkReturnValue(SDL_RenderDrawPoint(mRenderer.get(), point.x, point.y));
    }

    void Renderer::showMessage(MessageType type, const std::string& title, 
                               const std::string& message)
    {
        checkReturnValue(SDL_ShowSimpleMessageBox(static_cast<Uint32>(type), title.c_str(), message.c_str(), mWindow.get()));
    }

    void Renderer::present()
    {
        SDL_RenderPresent(mRenderer.get());
    }

}