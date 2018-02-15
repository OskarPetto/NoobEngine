#include "../include/Game.h"

namespace SdlWrapper
{

    Game::Game(const std::string& title, Uint32 width, Uint32 height, 
               const SDL_Color& background, UpdateHandler handleUpdate) 
        : mRenderer(title, width, height), mBackground(background), 
          mStatus(GameState::RUNNING), mUpdateHandler(handleUpdate) {}

    void Game::loadTexture(const std::string& path, SDL_bool enableColorKey, 
                           const SDL_Color& colorKey)
    {
        mRenderer.loadTexture(path, enableColorKey, colorKey);
    }

    void Game::loadAnimation(const std::string& name, const int framesPerRect, 
                             const std::vector<SDL_Rect>& rects)
    {
        mRenderer.loadAnimation(name, framesPerRect, rects);
    }

    void Game::addAnimation(const std::string& path, const std::string& name,
                            const SDL_Point& position, double scale, 
                            int angle, const SDL_RendererFlip flip)
    {
        mDrawOperations.push_back([this, path, name, position, scale, angle, flip]()
            {
                mRenderer.drawAnimation(path, name, position, scale, angle, flip);
            });
    }

    void Game::addTexture(const std::string& path, const SDL_Rect& src, 
                          const SDL_Point& position, double scale, 
                          int angle, const SDL_RendererFlip flip)
    {
        mDrawOperations.push_back([this, path, src, position, scale, angle, flip]()
            {
                mRenderer.drawTexture(path, src, position, scale, angle, flip);
            });
    }

    void Game::addRect(const SDL_Rect& rect, const SDL_Color& color, FillType filling)
    {
        mDrawOperations.push_back([this, rect, color, filling]()
            {
                mRenderer.drawRect(rect, color, filling);
            });
    }

    void Game::addLine(const SDL_Point& from, const SDL_Point& to, 
                       const SDL_Color& color)
    {
        mDrawOperations.push_back([this, from, to, color]()
        {
            mRenderer.drawLine(from, to, color);
        });
    }

    void Game::addPoint(const SDL_Point& point, const SDL_Color& color)
    {
        mDrawOperations.push_back([this, point, color]()
        {
            mRenderer.drawPoint(point, color);
        });
    }

    void Game::addEventHandler(EventHandler handleEvent)
    {
        mEventHandlers.push_back(handleEvent);
    }

    void Game::loop(Uint32 fps)
    {   
        if (fps == 0)
            return;

        Uint32 msPerFrame = 1000 / fps;

        SDL_Event event;

        mGameTimer.start();

        while (mStatus != GameState::QUIT)
        {
            mFpsTimer.start();

            while (SDL_PollEvent(&event) != 0)
            {
                for (auto handleEvent : mEventHandlers)
                {
                    mStatus = handleEvent(event);

                    if (mStatus == GameState::RUNNING)
                    {
                        mGameTimer.resume();
                    }
                    else
                    {
                        mGameTimer.pause();
                    } 
                    
                    if (event.type == SDL_QUIT)
                    {
                        mStatus = GameState::QUIT;
                        break;
                    }
                }
    
            }
            
            mUpdateHandler(*this);    

            mRenderer.clear(mBackground);

            // perform draw operations and erase them

            for (auto draw : mDrawOperations)
            {
                draw();
            }

            mDrawOperations.clear();

            mRenderer.present();

            Uint32 fpsTime = mFpsTimer.getTime();

            if (fpsTime < msPerFrame)
            {
                SDL_Delay(msPerFrame - fpsTime);
            }

        }
        
    }

    Uint32 Game::getTime()
    {
        return mGameTimer.getTime();
    }

}