#include "../headers/Buttons.h"          // Corresponding header file
#include "../headers/stateManager.h"     // Globals
#include "../headers/Test.h"
#include "../headers/globals.h"
#include <utility>

SDL_FPoint cursorPos;

void checkAnswer(string path) {
    if(path.substr(14) == (answer + ".png"))
    {
        itemAnswered = true;
    }
    else if (!wronged)
    {
        mistakes ++;
        cout << "u have: " << mistakes << " mistakes." << endl;
        wronged = true;
    }
}

void setType(string type) {
    quizType = type; // use s parameter as state value
    cout << "quiz type is now: " << quizType << endl;
}

void setLength(int length) {
    itemNo = length;
    cout << "number of items chosen are: " << itemNo << endl;
}

void switchState(int s) {
    state = State(s); // use s parameter as state value
    cout << "state is now: " << state << endl;
}

void checkPos()
{
    float x, y;
    SDL_GetMouseState(&x, &y);
    cursorPos.x = x;
    cursorPos.y = y;
}

SDL_FRect rect;

template<typename F, typename... A> void detectClick(F func, A ...args) {
    if(SDL_PointInRectFloat(&cursorPos, &rect) && (event.type == SDL_EVENT_MOUSE_BUTTON_DOWN)
        && (event.button.button == SDL_BUTTON_LEFT)) {
        func(args ...); // expand parameter pack
    }
}

Button::Button(int x, int y, string path) // default constructor
{
    SDL_Surface *surface = IMG_Load(path.c_str());             // take string and turn it into img path
    texture = SDL_CreateTextureFromSurface(renderer, surface); // create texture from surface //
    SDL_DestroySurface(surface);                               // deallocate surface

    float w, h;
    SDL_GetTextureSize(texture, &w, &h);

    rect.x = x;
    rect.y = y;
    rect.w = w;
    rect.h = h;

    SDL_RenderTexture(renderer, texture, NULL, &rect);

    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255); // draw rect outline
    SDL_RenderRect(renderer, &rect);                  // draw hitbox
    SDL_DestroyTexture(texture);
}

Button::Button(int x, int y, string path, int s) : Button(x,y,path) { // state switcher buttons
    detectClick(switchState, s);
}

Button::Button(int x, int y, string path, int s, string type) : Button(x,y,path,s) {
    detectClick(setType, type);
}

Button::Button(int x, int y, string path, int s, string type, int length) : Button(x,y,path,s) {
    detectClick(setLength, length);
}

Button::Button(int x, int y, string path, string placeholder) : Button(x,y,path) {
    detectClick(checkAnswer, path);
}

Button::~Button(){}