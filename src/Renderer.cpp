#include "../include/Renderer.h"

namespace SdlWrapper
{
    Renderer::Renderer(const std::string& title, Uint32 width, Uint32 height)
        : mWindow()
    {
        
        mWindow.reset(SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                                   width, height, SDL_WINDOW_SHOWN));

        checkPointer(mWindow.get());

        mRenderer.reset(SDL_CreateRenderer(mWindow.get(), -1, 
                        SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC));

        checkPointer(mRenderer.get());

    }

    void Renderer::loadTexture(const std::string& path, SDL_bool enableColorKey, 
                               const SDL_Color& colorKey)
    {
        mTextureManager.loadTexture(mRenderer, path, enableColorKey, colorKey);
    }

    void Renderer::loadAnimation(const std::string& name, const int framesPerRect, 
                                 const std::vector<SDL_Rect>& rects)
    {
        mAnimationManager.loadAnimation(name, framesPerRect, rects);
    }

    void Renderer::clear(const SDL_Color& background)
    {
        checkReturnValue(SDL_SetRenderDrawColor(mRenderer.get(), background.r, 
                                                background.g, background.b, 
                                                background.a));

        checkReturnValue(SDL_RenderClear(mRenderer.get()));
    }

    void Renderer::drawAnimation(const std::string& path, const std::string& name, 
                                 const SDL_Point& position, double scale, 
                                 int angle, const SDL_RendererFlip flip)
    {
        SDL_Rect src = mAnimationManager.getNextRect(name);

        this->drawTexture(path, src, position, scale, angle, flip);        

    }

    void Renderer::drawTexture(const std::string& path, const SDL_Rect& src, 
                               const SDL_Point& position, double scale, 
                               int angle, const SDL_RendererFlip flip)
    {

        SDL_Rect dst;

        dst.x = position.x;
        dst.y = position.y;
        dst.w = (int) (src.w * scale);
        dst.h = (int) (src.h * scale);

        if (angle == 0 && flip == SDL_FLIP_NONE)
        {
            checkReturnValue(SDL_RenderCopy(mRenderer.get(), 
                             mTextureManager.getTexture(path).getTexture(),
                             &src, &dst));
        }
        else
        {
            checkReturnValue(SDL_RenderCopyEx(mRenderer.get(), 
                             mTextureManager.getTexture(path).getTexture(),
                             &src, &dst, angle, nullptr, flip));
        }      

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