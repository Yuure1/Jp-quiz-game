#pragma once
#include "../include/SDL3/SDL.h"
#include "SDL3_image/SDL_image.h"
#include <iostream>
using namespace std;

#include "Background.h"
#include "Buttons.h"
#include "Init.h"
#include "LoadMedia.h"
#include "stateManager.h"
#include "Test.h"

enum State // states for screen manager
{
    mainMenu,  // 0
    settings,  // 1
    quit,      // 2
    choice,    // 3
    choice1,   // 4
    quiz,      // 5
    scoreScreen        // 6  
}; 

extern State state;
extern bool quitPressed;

extern const int screenWidth;
extern const int screenHeight;
const int S = 1;
const int M = 23;
const int L = 46;

extern SDL_Window* window;
extern SDL_Renderer* renderer;

extern SDL_Event event;

extern bool itemAnswered;
extern string answer;
extern int timeLooped;
extern string quizType;
extern bool generated;
extern int mistakes;
extern bool wronged;
extern bool shown;