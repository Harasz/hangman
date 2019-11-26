//
// Created by Jakub Sydor on 25-11-2019.
//

#ifndef HANGMAN_HANGMANILLUSTRATION_H
#define HANGMAN_HANGMANILLUSTRATION_H


#include "../Board/Board.h"

class HangmanIllustration {
    private:
        short attempt{ 0 };
        static const short illustrationCount{ 7 };
        char*** loadIllustration();
        char*** illustrations;
    public:
        explicit HangmanIllustration(short attempt = 0);
        void increaseAttempt();
        char** getIllustration();
//        char** getIllustration(short attempt);
};


#endif //HANGMAN_HANGMANILLUSTRATION_H
