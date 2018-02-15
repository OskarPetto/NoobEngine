#include "../include/Game.h"
#include <iostream>

#include "../include/Renderer.h"
#include "../include/SdlInitializer.h"
#include "../Sprites.h"

std::string name = "Moving Cat";
int WINDOW_WIDTH = 1000;
int WINDOW_HEIGHT = 800;
SDL_Color bg = {0xc1, 0xf4, 0xca, 255};

void handleUpdate(SdlWrapper::Game& game)
{
    Uint32 t = game.getTime();
    int posy = (t / 2) % WINDOW_HEIGHT; 
                                                                                         
    game.addRect({100, posy, 40, 40}, {0xba, 0xdb, 0xad, 255}, SdlWrapper::FillType::FILLED);
    game.addLine({0, WINDOW_HEIGHT / 2}, {WINDOW_WIDTH, WINDOW_HEIGHT / 2}, {0, 0, 0, 255});
    
    int posx = (t / 6) % WINDOW_WIDTH;
    
    game.addAnimation("runningcat.png", "running", {posx, WINDOW_HEIGHT / 2}, 1.0, 
                      0, SDL_FLIP_VERTICAL);  

    game.addAnimation("runningcat.png", "alsoRunning", {WINDOW_WIDTH-posx, WINDOW_HEIGHT / 3 - 50}, 1.0, 
                      0, SDL_FLIP_HORIZONTAL);  
}

SdlWrapper::GameState handleEvent(const SDL_Event& e)
{
    if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_RETURN)
        return SdlWrapper::GameState::QUIT;
    return SdlWrapper::GameState::RUNNING;
}

int main(int argc, char** argv)
{
    SdlWrapper::Game myGame(name, WINDOW_WIDTH, WINDOW_HEIGHT, bg, handleUpdate);

    myGame.loadTexture("runningcat.png", SDL_FALSE, {255, 255, 255, 255});    
    myGame.loadAnimation("running", 5, Sprites::runningCat());
    myGame.loadAnimation("alsoRunning", 5, Sprites::runningCat());

    myGame.addEventHandler(handleEvent);

    myGame.loop(60);

}