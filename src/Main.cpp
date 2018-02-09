#include "../include/Game.h"
#include <iostream>

int main(int argc, char** argv)
{
    using namespace SdlWrapper;

    Game myGame("hallo", 640, 480, {255, 255, 255, 255});

    myGame.addEventHandler(SDL_KEYDOWN, 
        [](const SDL_Event& e) {
                                    if(e.key.keysym.sym == SDLK_UP)
                                    {
                                        std::cout << "up\n"; 
                                    }
                                    return GameState::RUNNING;
                                });

    myGame.addUpdateHandler(
        [&myGame](Uint32 t)  {
                                myGame.addRect({100, 100, 40, 40}, {0, 0, 0, 255}, FillType::FILLED);
                                std::cout << "time: " << t << '\n';
                            });

    myGame.loop(1);


}