//
// Created by Jakub on 28-11-2019.
//

#ifndef HANGMAN_GAMEHANGMAN_H
#define HANGMAN_GAMEHANGMAN_H

#include <string>
#include <vector>
#include "../Words/Words.h"
#include "../Board/Board.h"
#include "../HangmanIllustration/HangmanIllustration.h"

class GameHangman {
public:
    // Constructor
    explicit GameHangman(std::string &wordListPath);

    // Functions
    void startMenu();

private:
    // Vars
    unsigned short attempts{0}; // Value in [0,6]
    Levels level{Levels::Easy};
    Words words;
    HangmanIllustration illustration;

    // Functions
    static void welcomeScreen();

    static char getUserInput(const char *allowedChars);

    static char getUserInput(int from, int to, const char *allowedChars);

    static char **showChosen(const char letters[32], int lettersCount);

    bool checkIfEnd(const char chosenLetters[32], const char wordLetters[]);

    char **showInputPanel(Word *word, char chosenLetter[32], bool end = false, bool winner = false);

    void getLevel();

    void startGame();

    void endGame();

    void resetGame();
};


#endif //HANGMAN_GAMEHANGMAN_H
