#include "../include/Game.h"

namespace SdlWrapper
{

    Game::Game(const std::string& title, Uint32 width, Uint32 height, 
               const SDL_Color& background) 
        : mRenderer(title, width, height), mBackground(background), 
          mStatus(GameState::RUNNING) {}

    void Game::loadTexture(const std::string& path)
    {
        mRenderer.loadTexture(path);
    }

    void Game::addTexture(const std::string& path, const SDL_Point& point, double scale)
    {
        mDrawOperations.push_back([this, path, point, scale]() 
            {
                mRenderer.drawTexture(path, point, scale);
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

    void Game::addEventHandler(EventType event, EventHandler handleEvent)
    {
        mEventHandlers.insert(std::make_pair(event, handleEvent));
    }

    void Game::addUpdateHandler(UpdateHandler handleUpdate)
    {
        mUpdateHandlers.push_back(handleUpdate);
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
                invokeEventHandler(event);
                
                if (event.type == SDL_QUIT)
                    mStatus = GameState::QUIT;

            }
            
            Uint32 gameTime = mGameTimer.getTime();

            for (auto handleUpdate : mUpdateHandlers)
            {
                handleUpdate(gameTime);    
            }

            mRenderer.clear(mBackground);

            // perform draw operations and erase them

            auto newEnd = std::remove_if(mDrawOperations.begin(), 
                                        mDrawOperations.end(),
                                        [](std::function<void()> draw) 
                                        {
                                            draw();
                                            return true;
                                        });

            mDrawOperations.erase(newEnd, mDrawOperations.end());

            mRenderer.present();

            Uint32 fpsTime = mFpsTimer.getTime();

            if (fpsTime < msPerFrame)
            {
                SDL_Delay(msPerFrame - fpsTime);
            }

        }
        
    }

    void Game::invokeEventHandler(const SDL_Event& event)
    {
        auto handleIter = mEventHandlers.find(event.type);
        if (handleIter == mEventHandlers.end())
            return;

        auto handleEvent = handleIter->second;

        mStatus = handleEvent(event);

        if (mStatus == GameState::RUNNING)
        {
            mGameTimer.resume();
        }
        else
        {
            mGameTimer.pause();
        } 

    }
    

}