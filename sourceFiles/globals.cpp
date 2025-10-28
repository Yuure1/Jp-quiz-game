#include "../headers/globals.h"

State state = mainMenu; // define initial state
bool quitPressed = false;
bool itemAnswered = true;
string quizType;
bool generated;
int mistakes = 0;
bool wronged; // initially false if u dont specify state

string score;