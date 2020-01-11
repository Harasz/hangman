//
// Created by Jakub Sydor on 25-11-2019.
//

#ifndef HANGMAN_HANGMANILLUSTRATION_H
#define HANGMAN_HANGMANILLUSTRATION_H


#include "../Board/Board.h"

class HangmanIllustration {
public:
    typedef unsigned short AttemptIndex;
    explicit HangmanIllustration(AttemptIndex attempt = 0);

    void increaseAttempt();

    char **getIllustration();

    char **getIllustration(AttemptIndex attemptCustom);

    AttemptIndex getAttempt();

    void resetAttempt();
private:
    AttemptIndex attempt{0};
    char ***illustrations;
    static const short illustrationCount{7};

    static char ***loadIllustration();
};


#endif //HANGMAN_HANGMANILLUSTRATION_H
