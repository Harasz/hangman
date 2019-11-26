#include "Board/Board.h"
#include "HangmanIllustration/HangmanIllustration.h"

int main() {
    std::setlocale(LC_ALL, "pl_PL");
    HangmanIllustration il(0);

    char** welcome = new char*[10];
    for (int i = 0; i < 10; ++i) {
        welcome[i] = new char[40]{};
    }
    char** welcome1 = new char*[10];
    for (int i = 0; i < 10; ++i) {
        welcome1[i] = new char[20]{};
    }
    char** welcome2 = new char*[10];
    for (int i = 0; i < 10; ++i) {
        welcome2[i] = new char[60]{};
    }
    il.increaseAttempt();
    il.increaseAttempt();
    il.increaseAttempt();
    il.increaseAttempt();
    il.increaseAttempt();
    il.increaseAttempt();


    Board::show(il.getIllustration(), welcome1, welcome2);

    std::system("pause");
    return 0;
}