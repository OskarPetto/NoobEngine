#include <SDL2/SDL.h>

namespace Sprites
{
    std::vector<SDL_Rect> runningCatV(8);
    const std::vector<SDL_Rect>& runningCat()
    {
        runningCatV[0].x = 4;
        runningCatV[0].y = 58;
        runningCatV[0].w = 491;
        runningCatV[0].h = 198;

        runningCatV[1].x = 561;
        runningCatV[1].y = 69;
        runningCatV[1].w = 408;
        runningCatV[1].h = 184;

        runningCatV[2].x = 53;
        runningCatV[2].y = 328;
        runningCatV[2].w = 403;
        runningCatV[2].h = 184;

        runningCatV[3].x = 586;
        runningCatV[3].y = 316;
        runningCatV[3].w = 381;
        runningCatV[3].h = 162;

        runningCatV[4].x = 66;
        runningCatV[4].y = 574;
        runningCatV[4].w = 390;
        runningCatV[4].h = 174;

        runningCatV[5].x = 567;
        runningCatV[5].y = 590;
        runningCatV[5].w = 400;
        runningCatV[5].h = 178;

        runningCatV[6].x = 16;
        runningCatV[6].y = 833;
        runningCatV[6].w = 439;
        runningCatV[6].h = 186;

        runningCatV[7].x = 515;
        runningCatV[7].y = 819;
        runningCatV[7].w = 477;
        runningCatV[7].h = 201;

        return runningCatV;
    }
    
    
}