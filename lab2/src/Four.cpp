#include "../include/Four.h"
#include <iostream>

// TODO
// - rvalue copy constructor
// - Возможно, последние два конструктора можно сделать без копирования. move - семантика
// - удалить вывод названия конструктора
// - мб в функции вывести inline
// - при билде варнинги

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





















Four::Four()
{
    ++count;
    id = count;
    std::cout << "Default constructor " << id << std::endl;
    number.pushBack((unsigned char) '0');
}


Four::Four(const size_t& n, unsigned char character = 0)
{
    ++count;
    id = count;
    std::cout << "Repeating character constructor " << id << std::endl;

    if (!correctCharacter(character)) {
        std::string errorMessage = "Incorrect character: ";
        errorMessage += character;
        throw std::runtime_error(errorMessage);
    }

    for (int i = 0; i < n; ++i) {
        number.pushBack(character);
    }
}


Four::Four(const std::initializer_list<unsigned char>& initLst)
{
    ++count;
    id = count;
    std::cout << "Initializer_List constructor " << id <<  std::endl;

    for(unsigned char character : initLst) {
        if (!correctCharacter(character)) {
            std::string errorMessage = "Incorrect character: ";
            errorMessage += character;
            throw std::runtime_error(errorMessage);
        }
    }

    for (const unsigned char* ptr = initLst.end() - 1; initLst.begin() <= ptr; --ptr) {
        number.pushBack(*ptr);
    }
}


Four::Four(const std::string& other)
{ // Может быть, изминить инициализацию

    ++count;
    id = count;
    for(unsigned char character : other) {
        if (!correctCharacter(character)) {
            std::string errorMessage = "Incorrect character: ";
            errorMessage += character;
            throw std::runtime_error(errorMessage);
        }
    }

    std::cout << "String constructor " << id << std::endl;

    for (int i =  other.size() - 1; 0 <= i; --i) {
        number.pushBack(other[i]);
    }
}


Four::Four(const Four& other)
{
    ++count;
    id = count;

    number = other.number;

    std::cout << "Copy constructor " << id <<  std::endl;
}

Four::Four(Four&& moved)
{
    ++count;
    id = count;

    number = std::move(moved.number); // Мб переинициализировать moved.number

    std::cout << "Move copy constructor " << id << std::endl;
    
}

Four& Four::operator=(const Four& copy)
{
    std::cout << "Вызов copy " << id << " = " << copy.id << std::endl;

    if (&copy != this) {
        number = copy.number;
    }

    return *this;
}

Four& Four::operator=(Four&& moved)
{
    std::cout << "Вызов moved " << id << " = " << moved.id << std::endl;
    if (&moved != this) {
        number = std::move(moved.number); // Мб переинициализировать moved.number
    }
    return *this;
}

Four::~Four() noexcept { std::cout << "DELETED: " << id << std::endl; --count;  }


void Four::print()
{
    for (int i = number.getSize() - 1; 0 <= i; --i) {
        std::cout << number[i];
    }
    std::cout << std::endl;
}


void Four::add(const Four& other)
{
    const int numberLen = number.getSize();
    const int otherNumberLen = other.number.getSize();

    int remainder = 0;

    for (int i = 0; i < max(numberLen, otherNumberLen); ++i) {
        unsigned int num = i < numberLen ? charToNum(number[i]) : 0;
        unsigned int otherNum = i < otherNumberLen ? charToNum(other.number[i]) : 0;
        unsigned int sum =  num + otherNum + remainder;

        unsigned char character = numToChar(sum % MAX_VALUE);
        if (i < numberLen) {
            number[i] = character;
        } else {
            number.pushBack(character);
        }

        remainder = sum / MAX_VALUE;
    }

    if (remainder) {
        number.pushBack(numToChar(remainder));
    }
}

bool Four::lowerThan(const Four& other)
{
    const int numberLen = number.getSize();
    const int otherNumberLen = other.number.getSize();

    if (otherNumberLen > numberLen) {
        return true;
    } else if (otherNumberLen < numberLen) {
        return false;
    }

    for (int i = numberLen - 1; 0 <= i; --i) {
        if (number[i] < other.number[i]) {
            return true;
        } else if (number[i] > other.number[i]) {
            return false;
        }
    }
    return false;
}

bool Four::lowerThanEq(const Four& other)
{
    return !(this->greaterThan(other));
}

bool Four::greaterThan(const Four& other)
{
    const int numberLen = number.getSize();
    const int otherNumberLen = other.number.getSize();

    if (otherNumberLen > numberLen) {
        return false;
    } else if (otherNumberLen < numberLen) {
        return true;
    }

    for (int i = numberLen - 1; 0 <= i; --i) {
        if (number[i] < other.number[i]) {
            return false;
        } else if (number[i] > other.number[i]) {
            return true;
        }
    }
    return false;
}

bool Four::greaterThanEq(const Four& other) {
    return !(this->lowerThan(other));
}

bool Four::equal(const Four& other)
{
    const int numberLen = number.getSize();
    const int otherNumberLen = other.number.getSize();

    if (otherNumberLen != numberLen) {
        return false;
    }

    for (int i = 0; i < numberLen; ++i) {
        if (number[i] != other.number[i]) {
            return false;
        }
    }

    return true;
}


void Four::subtract(const Four& other)
{
    if (this->lowerThan(other)) {
        throw std::runtime_error("The first number must be greater than or equal to the second");
    }

    const int numberLen = number.getSize();
    const int otherNumberLen = other.number.getSize();

    int remainder = 0;

    for (int i = 0; i < max(numberLen, otherNumberLen); ++i) {
        int num = i < numberLen ? charToNum(number[i]) : 0;
        int otherNum = i < otherNumberLen ? charToNum(other.number[i]) : 0;
        unsigned int difference;

        if (num - remainder < otherNum) { // Надо занимать разряд
            difference = MAX_VALUE + num - otherNum - remainder;
            remainder = 1;
        } else {
            difference = num - otherNum - remainder;
            remainder = 0;
        }
        number[i] = numToChar(difference);
    }

    // Стираем незначащие нули
    int i = numberLen - 1;
    while (i > 0 && number[i] == '0') {
        number.popBack();
        --i;
    }
}

bool Four::correctCharacter(const unsigned char character)
{
    for (const unsigned char correctCharacter : correctCharacters) {
        if (character == correctCharacter) {
            return true;
        }
    }
    return false;
}
