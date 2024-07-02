#include <stdio.h>
#include "pages/IntroVideo.h"
#include "utils/Credentials.h"
#include "pages/Menu.h"
#include "pages/Play.h"
#include "pages/Levels.h"
#include "pages/HighScores.h"
#include "pages/HowToPlay.h"
#include "pages/Account.h"
#include "pages/Exit.h"

int main()
{
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