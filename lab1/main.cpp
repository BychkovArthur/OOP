#include "lab1.hpp"
#include <iostream>

int main() {
    std::string str;

    std::cout << "Введите строку, состоящую только из английских гласных букв и/или пробелов:" << std::endl;
    std::getline(std::cin, str);

    int numberOfVowels = getNumberOfVowels(str);

    std::cout << "Количество гласных в данной строке равно " << numberOfVowels << std::endl;

    return 0;
}