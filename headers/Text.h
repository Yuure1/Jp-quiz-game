#pragma once
#include "globals.h"

class Text {
private:
    SDL_Texture *t;
public: 
    Text(string msg, string fontPath, int fontSize, int x, int y);

    ~Text(); // destructor
}; // end of class