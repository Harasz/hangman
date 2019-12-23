#define _WIN32_WINNT 0x0500

#include<windows.h>
#include <string>
#include "GameLogic/GameHangman.h"

int main(int argc, char *argv[]) {
    std::setlocale(LC_ALL, "pl_PL"); // Set locale to pl_PL
    system("cls"); // Clear Console

    // Set console width and height to 515 and 380
    HANDLE hOut;
    CONSOLE_SCREEN_BUFFER_INFO SBInfo;
    HWND console = GetConsoleWindow();
    RECT ConsoleRect;
    COORD NewSBSize;
    GetWindowRect(console, &ConsoleRect);
    MoveWindow(console, ConsoleRect.left, ConsoleRect.top, 515, 380, TRUE);

    hOut = GetStdHandle(STD_OUTPUT_HANDLE);

    GetConsoleScreenBufferInfo(hOut, &SBInfo);
    NewSBSize.X = SBInfo.dwSize.X - 2;
    NewSBSize.Y = SBInfo.dwSize.Y;

    SetConsoleScreenBufferSize(hOut, NewSBSize);

    // Disable console resize
    SetWindowLong(console, GWL_STYLE, GetWindowLong(console, GWL_STYLE) & ~WS_MAXIMIZEBOX & ~WS_SIZEBOX);

    // Hide console cursor
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(console, &cursorInfo);
    cursorInfo.dwSize = 100;
    cursorInfo.bVisible = FALSE; // set the cursor visibility
    SetConsoleCursorInfo(console, &cursorInfo);

    // Set console title
    SetConsoleTitle("Hangman Game By Jakub Sydor");

    // Check if *argv[] has path to word list, else set path to "words.txt"
    std::string pathToWordList = argc == 2 ? argv[1] : "words.txt";

    // Init game class and start game
    GameHangman game(pathToWordList);
    game.startMenu();

    return 0;
}