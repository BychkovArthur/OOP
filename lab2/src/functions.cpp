inline int min(const int a,const int b) {
    return a < b ? a : b;
}

inline int max(const int a,const int b) {
    return a > b ? a : b;
}

inline unsigned int charToNum(unsigned char character)
{
    // Проверка на отрицательные
    return character - (unsigned char) '0';
}

inline unsigned char numToChar(unsigned int num)
{
    // Проверка на отрицательные
    return (unsigned char) '0' + num;
}