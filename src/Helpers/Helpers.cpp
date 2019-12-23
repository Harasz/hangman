//
// Created by Jakub Sydor on 16-12-2019.
//

#include "Helpers.h"

char Helpers::toLower(char value) {
    if (value >= 'A' && value <= 'Z') value += 'a' - 'A';
    return value;
}

char *Helpers::toLower(char *value) {
    if (*value >= 'A' && *value <= 'Z') *value += 'a' - 'A';
    return value;
}

bool Helpers::isInArray(const char array[], char toFind) {
    int i{0};
    char character;
    toFind = Helpers::toLower(toFind);
    while (*(array + i)) {
        character = *(array + i);
        character = Helpers::toLower(character);
        if (character == toFind) return true; // Return true if find character in array

        i++;
    }
    return false;
}

bool Helpers::isInArray(const char array[], char toFind, int arrayLength) {
    char character;
    toFind = Helpers::toLower(toFind);

    for (int i = 0; i < arrayLength; ++i) {
        character = *(array + i);
        character = Helpers::toLower(character);
        if (character == toFind) return true; // Return true if find character in array
    }
    return false;
}
