#pragma once

#include "SdlInitializer.h"
#include "Renderer.h"
#include "Timer.h"
#include <vector>
#include <algorithm>

namespace SdlWrapper
{
    enum class GameState
    {
        QUIT,
        PAUSED,
        RUNNING
    };

    using EventType = Uint32;
    using EventHandler = std::function<GameState(const SDL_Event& event)>;
    using UpdateHandler = std::function<void(Uint32 gameTime)>;   
    using DrawOperation = std::function<void()>;

    class Game
    {
        public:
        Game(const std::string& title, Uint32 width, Uint32 height, 
             const SDL_Color& background);

        void loadTexture(const std::string& path);

        void addTexture(const std::string& path, const SDL_Point& point);

        void addRect(const SDL_Rect& rect, const SDL_Color& color, FillType filling);

        void addLine(const SDL_Point& from, const SDL_Point& to, 
                     const SDL_Color& color);

        void addEventHandler(EventType event, EventHandler handleEvent);

        void addUpdateHandler(UpdateHandler handleUpdate);

        void loop(Uint32 fps);

        private:

        void invokeEventHandler(const SDL_Event& event);

        SdlInitializer sdlInit;

        Renderer mRenderer;

        SDL_Color mBackground;

        GameState mStatus;

        Timer mFpsTimer;
        Timer mGameTimer;

        std::unordered_map<EventType, EventHandler> mEventHandlers;
        std::vector<UpdateHandler> mUpdateHandlers;      

        std::vector<DrawOperation> mDrawOperations;

    };
}