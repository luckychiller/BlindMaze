// #include <cstdlib>
// #include <cstring>
// #include <ctype.h>
// #include <dos.h>
// #include <iostream>
// #include <queue>
// #include <process.h>
// #include <string>
// #include <time.h>
#include <iostream>
#include <conio.h>
#include <cstdio>
#include <fstream>
#include <windows.h>

#define HEIGHT 23
#define WIDITH 56

using namespace std;

HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
HANDLE console_color = GetStdHandle(STD_OUTPUT_HANDLE);
COORD CursorPosition;

char maze[HEIGHT][WIDITH] =
    {
        "#######################################################",
        "#######################################################",
        "##*#           #         #                       #   ##",
        "## # ######### # ##### # ##### ################# # # ##",
        "## #   # #     # #     #       #   #         # # # # ##",
        "## ### # # ####### ############# ### ##### # # # # # ##",
        "##     # #       # #     #   #       #     #   # # # ##",
        "######## ####### # # ### # # ### ##### ####### # ### ##",
        "##       #       #     #   #   #   #   #   #   #   # ##",
        "## ####### ################### ##### ### ### ##### # ##",
        "##         #   #       #       #     #   #   #     # ##",
        "## ######### # # # ### # ####### ##### ### ### ##### ##",
        "##       #   # # # #   # #   #   #     #     # #   # ##",
        "######## ### # # # # ### # ### # ##### # ##### # # # ##",
        "## #   #     # # # #     # #   # #   #   # #   # #   ##",
        "## # # ####### ### ####### # ### # # # ### # ### ### ##",
        "##   #       #   # #         # #   # #     # #   # # ##",
        "## ####### ##### # # ######### ##### ##### # # ### # ##",
        "## #     # #   # # #         #   #   #   # # #   # # ##",
        "## # ### # # # # # ######### ### # ### # ### ### # # ##",
        "##   #   #   #     #             #     #         #  E##",
        "#######################################################",
        "#######################################################"};

int posX = 2;
int posY = 2;

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

void SaveData()
{
    ofstream MyFile("IntroFile.txt");
    for (int i = 0; i < HEIGHT; i++)
    {
        for (int j = 0; j < WIDITH; j++)
        {
            MyFile << maze[i][j];
        }
        MyFile << '\0';
    }
    MyFile.close();
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

int main()
{
    bool k = true;

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
            //SaveData();
            k = false;
            break;

        default:
            break;
        }
    }
}