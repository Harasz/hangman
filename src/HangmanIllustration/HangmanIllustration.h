//
// Created by Jakub Sydor on 25-11-2019.
//

#ifndef HANGMAN_HANGMANILLUSTRATION_H
#define HANGMAN_HANGMANILLUSTRATION_H


#include "../Board/Board.h"

class HangmanIllustration {
private:
    unsigned short attempt{0};
    char ***illustrations;
    static const short illustrationCount{7};

    static char ***loadIllustration();

public:
    explicit HangmanIllustration(unsigned short attempt = 0);

    void increaseAttempt();

    char **getIllustration();

    char **getIllustration(unsigned short attemptCustom);

    unsigned short getAttempt();

    void resetAttempt();
};


#endif //HANGMAN_HANGMANILLUSTRATION_H
