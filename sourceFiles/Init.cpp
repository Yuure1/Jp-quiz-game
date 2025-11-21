#include "../headers/Init.h"
#include "../headers/globals.h"
#include "../include/SDL3/SDL.h"

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

/* TTF_Font *font = NULL; // make font variable
SDL_Color black = {0, 0, 255};

SDL_FRect msgRect;

void displayText(string text, int size, int x, int y, string fontPath) {
    font = TTF_OpenFont(fontPath.c_str(), size); // .c_str to convert string to const char

    SDL_Surface *txt = TTF_RenderText_Solid(font, text.c_str(), text.length(), black);
    SDL_Texture *msg = SDL_CreateTextureFromSurface(renderer, txt);
    SDL_DestroySurface(txt);
    
    msgRect.x = x;
    msgRect.y = y;
    msgRect.w = size * 1;
    msgRect.h = size * 1;

    SDL_RenderTexture(renderer, msg, NULL, &msgRect);
} */