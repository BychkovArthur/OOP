#include "lab1.hpp"

bool isLowerCaseVowel(char letter) {
    return letter == 'a' || letter == 'e' || letter == 'u' || letter == 'o' || letter == 'i';
}

int getNumberOfVowels(std::string str) {
    int count = 0;
    for (char letter : str) {
        if (isLowerCaseVowel(letter)) {
            ++ count;
        }
    }
    return count;
}
