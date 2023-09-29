#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <string>

inline int min(const int a,const int b) {
    return a < b ? a : b;
}

inline int max(const int a,const int b) {
    return a > b ? a : b;
}

inline unsigned int charToNum(unsigned char character)
{
    return character - (unsigned char) '0';
}

inline unsigned char numToChar(unsigned int num)
{
    return (unsigned char) '0' + num;
}

inline std::string boolToStr(bool value) {
    return value ? "True" : "False";
}

#endif // FUNCTIONS_H