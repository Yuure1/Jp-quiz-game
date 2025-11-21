#pragma once
#include "globals.h"
#include <iostream>
using namespace std;

class Background
{
private:
    SDL_Texture *texture;
public:
    Background(string path); // constructor
    ~Background();           // destructor
};