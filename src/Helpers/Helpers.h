//
// Created by Jakub Sydor on 16-12-2019.
//

#ifndef HANGMAN_HELPERS_H
#define HANGMAN_HELPERS_H

namespace Helpers {
    char toLower(char value);

    char *toLower(char *value);

    bool isInArray(const char array[], char toFind);

    bool isInArray(const char array[], char toFind, int arrayLength);
}

#endif //HANGMAN_HELPERS_H
