#include "../headers/Init.h"
#include "../headers/globals.h"
#include "../include/SDL3/SDL.h"

#include "SDL3_ttf/SDL_ttf.h" // sdl font

#include <iostream>
using namespace std;

SDL_Window* window = NULL;
SDL_Renderer* renderer = NULL; 



SDL_Event event;

const int screenWidth = 1920;
const int screenHeight = 1080;

void init()
{
    SDL_Init(SDL_INIT_VIDEO);
    window = SDL_CreateWindow("game name pending", screenWidth, screenHeight, SDL_WINDOW_HIGH_PIXEL_DENSITY); 
    renderer = SDL_CreateRenderer(window, NULL);

    TTF_Init(); // font handler
    cout << "Initialization successful.\n";
    cout << ". . .\n";
}

TTF_Font *font = NULL; // make font variable
SDL_Color red = {255, 0, 0};

SDL_FRect msgRect;

void loadFont() {
    font = TTF_OpenFont("assets/fonts/DelaSukoGothicOne-R.ttf", 12);

    SDL_Surface *txt = TTF_RenderText_Solid(font, "test", 4, red);
    SDL_Texture *msg = SDL_CreateTextureFromSurface(renderer, txt);
    
    msgRect.x = 1200;
    msgRect.y = 400;
    msgRect.w = 400;
    msgRect.h = 120;

    SDL_RenderTexture(renderer, msg, NULL, &msgRect);
}