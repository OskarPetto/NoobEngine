#pragma once

#include "SdlInitializer.h"
#include "Renderer.h"
#include "Timer.h"
#include <algorithm>

namespace SdlWrapper
{
    class Game;

    enum class GameState
    {
        QUIT,
        PAUSED,
        RUNNING
    };

    using EventType = Uint32;
    using EventHandler = std::function<GameState(const SDL_Event& event)>;
    using UpdateHandler = std::function<void(Game& game)>;   
    using DrawOperation = std::function<void()>;

    class Game
    {
        public:
        Game(const std::string& title, Uint32 width, Uint32 height, 
             const SDL_Color& background, UpdateHandler handleUpdate);

        void loadTexture(const std::string& path, SDL_bool enableColorKey, 
                         const SDL_Color& colorKey);

        void loadAnimation(const std::string& path, const int framesPerRect, 
                           const std::vector<SDL_Rect>& rects);

        void addAnimation(const std::string& path, const std::string& name,
                          const SDL_Point& position, double scale, 
                          int angle, const SDL_RendererFlip flip);

        void addTexture(const std::string& path, const SDL_Rect& src,
                        const SDL_Point& position, double scale, 
                        int angle, const SDL_RendererFlip flip);

        void addRect(const SDL_Rect& rect, const SDL_Color& color, FillType filling);

        void addLine(const SDL_Point& from, const SDL_Point& to, 
                     const SDL_Color& color);

        void addPoint(const SDL_Point& point, const SDL_Color& color);

        void addEventHandler(EventHandler handleEvent);

        void loop(Uint32 fps);

        Uint32 getTime();

        private:

        SdlInitializer sdlInit;

        Renderer mRenderer;

        SDL_Color mBackground;

        GameState mStatus;

        Timer mFpsTimer;
        Timer mGameTimer;

        UpdateHandler mUpdateHandler;              

        std::vector<EventHandler> mEventHandlers;

        std::vector<DrawOperation> mDrawOperations;

    };
}