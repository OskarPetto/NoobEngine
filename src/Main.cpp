#include "../include/Game.h"
#include <iostream>

#include "../include/Renderer.h"
#include "../include/SdlInitializer.h"

std::string name = "Moving Square";
int WINDOW_WIDTH = 640;
int WINDOW_HEIGHT = 480;
SDL_Color bg = {0xc1, 0xf4, 0xca, 255};

int main(int argc, char** argv)
{
    using namespace SdlWrapper;

    Game myGame(name, WINDOW_WIDTH, WINDOW_HEIGHT, bg);

    //myGame.loadTexture("Ln3bk3h.jpg");

    myGame.addEventHandler(SDL_KEYDOWN,
        [] (const SDL_Event& e)  {
                                        if (e.key.keysym.sym == SDLK_RETURN)
                                            return GameState::QUIT;
                                        return GameState::RUNNING;
                                     });

    myGame.addUpdateHandler(
        [&myGame](Uint32 t)  {
                                int posy = (t / 2) % WINDOW_HEIGHT;                                                            
                                myGame.addRect({100, posy, 40, 40}, {0xba, 0xdb, 0xad, 255}, FillType::FILLED);
                                myGame.addLine({0, WINDOW_HEIGHT / 2}, {WINDOW_WIDTH, WINDOW_HEIGHT / 2}, {0, 0, 0, 255});
                                //myGame.addTexture("Ln3bk3h.jpg", {WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2}, 0.3);   
                            });

    myGame.loop(60);

}