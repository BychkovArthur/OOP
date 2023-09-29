#ifndef FUNCTIONS_H
#define FUNCTIONS_H

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

#endif // FUNCTIONS_H