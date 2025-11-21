#pragma once
#include "globals.h"
#include <iostream>
using namespace std;

class Button
{
private:
    SDL_Texture *texture;
public:

    Button(int x, int y, string path); // default constructor
    Button(int x, int y, string path, string placeholder); 

    Button(int x, int y, string path, int s);
    Button(int x, int y, string path, int s, string type);
    Button(int x, int y, string path, int s, string type, int length);
    
    ~Button();
};



void checkPos();