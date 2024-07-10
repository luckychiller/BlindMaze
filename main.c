#include <stdio.h>
#include "components/functions.h"
int main()
{
    console = GetStdHandle(STD_OUTPUT_HANDLE);
    console_color = GetStdHandle(STD_OUTPUT_HANDLE);
    int GamePlay = 1;
    IntroVideo();
    CredentialCheck();
    while (GamePlay)
    {
        int option = Menu();
        switch (option)
        {
        case 1:
            Play();
            break;

        case 2:
            Levels();
            break;

        case 3:
            HighScores();
            break;

        case 4:
            HowToPlay();
            break;

        case 5:
            Account();
            break;

        case 6:
            GamePlay = Exit(GamePlay);
            break;

        default:
            break;
        }
    }
    return 0;
}