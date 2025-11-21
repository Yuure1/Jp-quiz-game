#include "../headers/globals.h" 
#include "../headers/Buttons.h"

bool placeholder = false;

void fillScreen()
{
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderFillRect(renderer, NULL);
}

/*  ⣇⣿⠘⣿⣿⣿⡿⡿⣟⣟⢟⢟⢝⠵⡝⣿⡿⢂⣼⣿⣷⣌⠩⡫⡻⣝⠹⢿⣿⣷
    ⡆⣿⣆⠱⣝⡵⣝⢅⠙⣿⢕⢕⢕⢕⢝⣥⢒⠅⣿⣿⣿⡿⣳⣌⠪⡪⣡⢑⢝⣇
    ⡆⣿⣿⣦⠹⣳⣳⣕⢅⠈⢗⢕⢕⢕⢕⢕⢈⢆⠟⠋⠉⠁⠉⠉⠁⠈⠼⢐⢕⢽
    ⡗⢰⣶⣶⣦⣝⢝⢕⢕⠅⡆⢕⢕⢕⢕⢕⣴⠏⣠⡶⠛⡉⡉⡛⢶⣦⡀⠐⣕⢕
    ⡝⡄⢻⢟⣿⣿⣷⣕⣕⣅⣿⣔⣕⣵⣵⣿⣿⢠⣿⢠⣮⡈⣌⠨⠅⠹⣷⡀⢱⢕
    ⡝⡵⠟⠈⢀⣀⣀⡀⠉⢿⣿⣿⣿⣿⣿⣿⣿⣼⣿⢈⡋⠴⢿⡟⣡⡇⣿⡇⡀⢕
    ⡝⠁⣠⣾⠟⡉⡉⡉⠻⣦⣻⣿⣿⣿⣿⣿⣿⣿⣿⣧⠸⣿⣦⣥⣿⡇⡿⣰⢗⢄
    ⠁⢰⣿⡏⣴⣌⠈⣌⠡⠈⢻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣬⣉⣉⣁⣄⢖⢕⢕⢕
    ⡀⢻⣿⡇⢙⠁⠴⢿⡟⣡⡆⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⣵⣵⣿
    ⡻⣄⣻⣿⣌⠘⢿⣷⣥⣿⠇⣿⣿⣿⣿⣿⣿⠛⠻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿
    ⣷⢄⠻⣿⣟⠿⠦⠍⠉⣡⣾⣿⣿⣿⣿⣿⣿⢸⣿⣦⠙⣿⣿⣿⣿⣿⣿⣿⣿⠟
    ⡕⡑⣑⣈⣻⢗⢟⢞⢝⣻⣿⣿⣿⣿⣿⣿⣿⠸⣿⠿⠃⣿⣿⣿⣿⣿⣿⡿⠁⣠
    ⡝⡵⡈⢟⢕⢕⢕⢕⣵⣿⣿⣿⣿⣿⣿⣿⣿⣿⣶⣶⣿⣿⣿⣿⣿⠿⠋⣀⣈⠙
    ⡝⡵⡕⡀⠑⠳⠿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠿⠛⢉⡠⡲⡫⡪⡪⡣   */

void update()
{    
    checkPos();
    
    switch(state)
    {
        case mainMenu:
        {
            Background mainMenuBg("assets/mainMenu.png");

            Button play      (100, 550, "assets/play.png", 3);   
            Button settings  (100, 680, "assets/settingsBtn.png", 1);  
            Button quit      (100, 810, "assets/quitBtn.png", 2); 

            placeholder = false; // placeholder, as the name suggests lol

            generated = false;
            
            break;
        }
        case settings:
        {
            Background settingsBg("assets/settings.png");

            Button back   (100, 900, "assets/backBtn.png", 0);
            
            break;
        }
        case quit:
        {
            quitPressed = true;
            break;
        }
        case choice:
        {
            Background choiceBg("assets/choice.png");
            Button hira   (350, 200, "assets/hira.png", 4, "hira");
            Button kata   (1070, 200, "assets/kata.png", 4, "kata");

            Button back   (100, 900, "assets/backBtn.png", 0);
            break;
        }
        case choice1:
        {
            Background choice1Bg("assets/choice1.png");

            Button length0    (200, 225, "assets/length0.png", 5, (quizType), (S));
            Button length1    (200, 465, "assets/length1.png", 5, (quizType), (M));
            Button length2    (200, 705, "assets/length2.png", 5, (quizType), (L)); 
            Button back    (1420, 900, "assets/backBtn.png", 3);
            break;
        }
        case quiz:
        {
            Background quizBg("assets/quizBg.png");
            resetQuiz();
            shuffler();
            itemGenv2();
            break;
        }
        case scoreScreen:

        {
            Background choice1Bg("assets/choice1.png");

            Text myobj(score, "assets/fonts/DelaSukoGothicOne-R.ttf", 90, 700, 700);

            //cout << score << endl; // display score in this state
            
            Button back   (100, 900, "assets/backBtn.png", 0);
            break;
        }
    }
}