// july 3 2025

#include <iostream>
#include "SDL3/SDL.h"
#include "SDL3_image/SDL_image.h"
#include "SDL3_ttf/SDL_ttf.h"

#include "headers/globals.h"
#include "headers/Init.h"
#include "headers/Buttons.h"
#include "headers/stateManager.h"
#include "headers/Test.h"

using namespace std;

const int fps = 60;
const int frameDelay = 1000/fps;

Uint32 frameStart;
int frameTime;

int main(int argc, char* args[])
{
    init(); 

    while(true)
    {
        frameStart = SDL_GetTicks();
        
        SDL_RenderClear(renderer);

        update(); 

        SDL_RenderPresent(renderer);
        
        frameTime = SDL_GetTicks() - frameStart;

        if(frameDelay > frameTime)
        {
            SDL_Delay(frameDelay - frameTime);
        }
        
        if(SDL_PollEvent(&event)) // Event checker
        {
            SDL_GetError();

            if(event.type == SDL_EVENT_QUIT || quitPressed)
            {break;}
        }
    }
}