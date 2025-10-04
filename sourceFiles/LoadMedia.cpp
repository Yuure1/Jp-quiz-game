#include "../headers/LoadMedia.h"
#include "../headers/globals.h"
#include "SDL3_ttf/SDL_ttf.h"

#include <iostream>
using namespace std;

TTF_Font *font;

SDL_Texture *loadTexture(string file)
{
    SDL_Texture *x = NULL;
    SDL_Surface *y = IMG_Load(file.c_str());
    x = SDL_CreateTextureFromSurface(renderer, y);
    SDL_DestroySurface(y);
    return x;
}

void loadFont() {
    
}