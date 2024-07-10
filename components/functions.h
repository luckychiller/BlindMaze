#include "constants.h"

void gotoxy(int x, int y)
{
    CursorPosition.X = x;
    CursorPosition.Y = y;
    SetConsoleCursorPosition(console, CursorPosition);
}

void setcursor(bool visible, DWORD size)
{
    if (size == 0)
    {
        size = 20;
    }

    CONSOLE_CURSOR_INFO lpCursor;
    lpCursor.bVisible = visible;
    lpCursor.dwSize = size;
    SetConsoleCursorInfo(console, &lpCursor);
}

void fordelay(int j)
{
    int i, k;
    for (i = 0; i < j; i++)
    {
        k = i;
    }
}

void MoveDown()
{
    if (maze[posY + 1][posX] == ' ')
    {
        maze[posY + 1][posX] = '*';
        maze[posY][posX] = '.';
        posY++;
    }
    else if (maze[posY + 1][posX] == '.')
    {
        maze[posY + 1][posX] = '*';
        maze[posY][posX] = ' ';
        posY++;
    }
}

void MoveUp()
{
    if (maze[posY - 1][posX] == ' ')
    {
        maze[posY - 1][posX] = '*';
        maze[posY][posX] = '.';
        posY--;
    }
    else if (maze[posY - 1][posX] == '.')
    {
        maze[posY - 1][posX] = '*';
        maze[posY][posX] = ' ';
        posY--;
    }
}

void MoveLeft()
{
    if (maze[posY][posX - 1] == ' ')
    {
        maze[posY][posX - 1] = '*';
        maze[posY][posX] = '.';
        posX--;
    }
    else if (maze[posY][posX - 1] == '.')
    {
        maze[posY][posX - 1] = '*';
        maze[posY][posX] = ' ';
        posX--;
    }
}

void MoveRight()
{
    if (maze[posY][posX + 1] == ' ')
    {
        maze[posY][posX + 1] = '*';
        maze[posY][posX] = '.';
        posX++;
    }
    else if (maze[posY][posX + 1] == '.')
    {
        maze[posY][posX + 1] = '*';
        maze[posY][posX] = ' ';
        posX++;
    }
}

void SaveData(char* file_name)
{
    FILE *fp = fopen(file_name, "w");
    if (fp == NULL) {
        perror("Error opening file");
        return;
    }

    for (int i = 0; i < HEIGHT; i++)
    {
        for (int j = 0; j < WIDITH; j++)
        {
            fputc(maze[i][j], fp);
        }
        fputc('\n', fp);
    }
    fclose(fp);
}

void LoadMaze(const char* file_path)
{
    FILE *fp = fopen(file_path, "r");
    if (fp == NULL) {
        perror("Error opening file");
        
    }

    for (int i = 0; i < HEIGHT; i++) {
        if (fgets(maze[i], WIDITH + 1, fp) == NULL) {
            perror("Error reading file");
            fclose(fp);
           
        }
        maze[i][strcspn(maze[i], "\n")] = '\0'; // Remove the newline character, if any
    }

    fclose(fp);
}

void PrintMaze()
{
    for (int i = posY - 4; i < posY + 4; i++)
    {
        for (int j = posX - 4; j < posX + 4; j++)
        {
            if (i >= 0 && i < HEIGHT && j >= 0 && j < WIDITH)
            {
                if (i == posY - 4 || i == posY + 3 || j == posX - 4 || j == posX + 3)
                {
                    gotoxy(j, i);
                    printf(" ");
                }
                else
                {
                    switch (maze[i][j]) 
                    {
                    case '#':
                        gotoxy(j, i);
                        printf("%c", 178);
                        break;

                    case ' ':
                        gotoxy(j, i);
                        printf(" ");
                        break;

                    case '.':
                        gotoxy(j, i);
                        printf("%c", 176);
                        break;

                    case '*':
                        gotoxy(j, i);
                        printf("%c", 254);
                        break;

                    default:
                        break;
                    }
                }
            }
        }
    }
}

void IntroVideo()
{
    printf("Make sure the app is in full screen mode.!!!\n\n\n\n");
    system("pause");
    system("cls");
}

void Play()
{
    int k = 1;
    
    LoadMaze("../others/intro_vid_maze.txt");

    system("cls");

    while (k)
    {
        PrintMaze();
        char bit = getch();
        switch (bit)
        {
        case 'w':
            MoveUp();
            break;

        case 's':
            MoveDown();
            break;

        case 'a':
            MoveLeft();
            break;

        case 'd':
            MoveRight();
            break;

        case 'p':
            SaveData("test.txt");
            k = 0;
            break;

        default:
            break;
        }
    }
}

void Account()
{
    return;
}

void CredentialCheck()
{
return;
}

int Exit()
{
   return 0; 
}

void HighScores()
{
    return;
}

void HowToPlay()
{
    return;
}

void Levels()
{
    return;
}

int Menu()
{
    return 1;
}

















