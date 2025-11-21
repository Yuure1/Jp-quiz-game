#include "../headers/globals.h"

TTF_Font *font = NULL;
SDL_FRect textRect;

SDL_Color black = {0,0,0};

Text::Text(string msg, string fontPath, int fontSize, int x, int y) {
    font = TTF_OpenFont(fontPath.c_str(), fontSize);

    SDL_Surface *s = TTF_RenderText_Solid(font, msg.c_str(), msg.length(), black);
    t = SDL_CreateTextureFromSurface(renderer, s);
    SDL_DestroySurface(s);

    float w, h;
    SDL_GetTextureSize(t, &w, &h);

    textRect.x = x;
    textRect.y = y;
    textRect.w = w;
    textRect.h = h;

    SDL_RenderTexture(renderer, t, NULL, &textRect);
    SDL_DestroyTexture(t); 
    TTF_CloseFont(font);
}

Text::~Text(){}