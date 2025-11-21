#include "../headers/Background.h"
#include "../headers/globals.h"
#include <iostream>
using namespace std;

Background::Background(string path)
{
    SDL_Surface *surface = IMG_Load(path.c_str());            
    texture = SDL_CreateTextureFromSurface(renderer, surface); 
    SDL_DestroySurface(surface);

    SDL_RenderTexture(renderer, texture, NULL, NULL);
}

Background::~Background()
{
    SDL_DestroyTexture(texture);
}