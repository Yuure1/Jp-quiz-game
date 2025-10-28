#include "../headers/Test.h"
#include "../headers/stateManager.h"
#include "../headers/globals.h"
#include "../headers/Buttons.h"

#include <ctime>
#include <vector>
#include <algorithm>
#include <random>

#include <fstream>

ifstream file;
ofstream list;
vector<string> kana; 
string ln;

int itemNo = 0;

random_device rd;
mt19937 g(rd());

void shuffler()
{
    if(!generated)
    {
        file.open("kana.txt"); // open txt file
        while(!file.eof()) // while the end of file isn't reached yet
        {
            getline(file, ln); // get each line from file and store them in ln variable
            kana.push_back(ln); // store each ln in vector
        }
        file.close(); // close txt file

        shuffle(kana.begin(), kana.end(), g);
        generated = true;
        cout << "generated new items" << endl;
    }
}

int timeLooped = 0;
vector<string> items;
string answer;

void itemGenv2()
{
    if(itemAnswered) { // clears items if answered correctly
        wronged = false;
        items.clear();
    }
    
    if((timeLooped<itemNo) && (itemAnswered))
    {
        vector<string> wrongAnswers = kana; // make a copy of kana vector
        
        answer = kana[timeLooped]; // answer is from kana vector depending on how many times looped
        items.push_back(answer); // store answer in items vector

        wrongAnswers.erase(wrongAnswers.begin()+(timeLooped)); // remove correct answer from wrong answers vector

        shuffle(wrongAnswers.begin(), wrongAnswers.end(), g); // shuffle wrong answers

        for(auto i=0; i<3; i++)
        {
            items.push_back(wrongAnswers[i]); // take 3 items from wrong answers and add them to items vector
        }

        shuffle(items.begin(), items.end(), g); // now that correct answer & 3 wrong answers are in item vector, shuffle it

        cout << timeLooped << " " << answer << endl;

        timeLooped++;
        itemAnswered = false; // set answered to false to generate only one item at a time
    }

    Button item(710, 190, ("assets/" + (quizType) + "/" + (answer) + ".png"));
    Button a(610, 740, ("assets/romaji/" + (items[0]) + ".png"), "dummy");
    Button b(1010, 740, ("assets/romaji/" + (items[1]) + ".png"), "dummy");
    Button c(610, 890, ("assets/romaji/" + (items[2]) + ".png"), "dummy");
    Button d(1010, 890, ("assets/romaji/" + (items[3]) + ".png"), "dummy"); 
}



void resetQuiz() {
    if ((timeLooped == itemNo) && (itemAnswered)) {
        cout << "quiz reset." << endl;

        int s = itemNo - mistakes;

        score = to_string(s) + "/" + to_string(itemNo);

        

        

        /*cout << "your score is: " << score << endl;
        cout << "your string says: " << a << endl;*/
        
        mistakes = 0;
        kana.clear();
        itemNo = 0;
        timeLooped = 0;
        state = State(6);
    }
}