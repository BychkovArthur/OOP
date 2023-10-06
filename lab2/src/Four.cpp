#include "Four.h"
#include "functions.h"
#include <iostream>
#include <algorithm>

Four::Four() { 
    number.pushBack((unsigned char) '0'); 
}

Four::Four(const size_t& n, unsigned char character = 0)
{
    if (!correctCharacter(character)) {
        throw std::invalid_argument("Incorrect character: " + character);
    }

    for (size_t i = 0; i < n; ++i) {
        number.pushBack(character);
    }
}

Four::Four(const std::initializer_list<unsigned char>& initLst)
{
    isCorrectCharacters(initLst);

    for (const unsigned char* ptr = initLst.end() - 1; initLst.begin() <= ptr; --ptr) {
        number.pushBack(*ptr);
    }
}

Four::Four(const std::string& other)
{
    isCorrectCharacters(other);

    for (int i = other.size() - 1; 0 <= i; --i) {
        number.pushBack(other[i]);
    }
}

Four::Four(const Four& other) : number(other.number) { }

Four::Four(Four&& moved) : number(std::move(moved.number)) { }

Four::~Four() noexcept { }



void Four::add(const Four& other)
{
    const size_t numberLen = number.getSize();
    const size_t otherNumberLen = other.number.getSize();
    int remainder = 0;

    for (size_t i = 0; i < std::max(numberLen, otherNumberLen); ++i) {
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

void Four::subtract(const Four& other)
{
    if (this->lowerThan(other)) {
        throw std::invalid_argument("The first number must be greater than or equal to the second");
    }

    const size_t numberLen = number.getSize();
    const size_t otherNumberLen = other.number.getSize();

    int remainder = 0;

    for (size_t i = 0; i < std::max(numberLen, otherNumberLen); ++i) {
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



bool Four::lowerThan(const Four& other)
{
    const size_t numberLen = number.getSize();
    const size_t otherNumberLen = other.number.getSize();

    if (numberLen != otherNumberLen) {
        return numberLen < otherNumberLen;
    }

    for (int i = numberLen - 1; 0 <= i; --i) {
        if (number[i] != other.number[i]) {
            return number[i] < other.number[i];
        }
    }
    return false;
}

bool Four::greaterThan(const Four& other)
{
    const size_t numberLen = number.getSize();
    const size_t otherNumberLen = other.number.getSize();

    if (numberLen != otherNumberLen) {
        return numberLen > otherNumberLen;
    }

    for (int i = numberLen - 1; 0 <= i; --i) {
        if (number[i] != other.number[i]) {
            return number[i] > other.number[i];
        }
    }
    return false;
}

bool Four::lowerThanEq(const Four& other)
{
    return !(this->greaterThan(other));
}

bool Four::greaterThanEq(const Four& other) {
    return !(this->lowerThan(other));
}

bool Four::equal(const Four& other)
{
    const size_t numberLen = number.getSize();
    const size_t otherNumberLen = other.number.getSize();

    if (otherNumberLen != numberLen) {
        return false;
    }

    for (size_t i = 0; i < numberLen; ++i) {
        if (number[i] != other.number[i]) {
            return false;
        }
    }

    return true;
}



void Four::print()
{
    for (int i = number.getSize() - 1; 0 <= i; --i) {
        std::cout << number[i];
    }
    std::cout << std::endl;
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


void Four::isCorrectCharacters(const std::initializer_list<unsigned char>& initLst) {
    for(unsigned char character : initLst) {
        if (!correctCharacter(character)) {
            throw std::invalid_argument("Incorrect character: " + std::string(1, character));
        }
    }
}

void Four::isCorrectCharacters(const std::string& other) {
    for(unsigned char character : other) {
        if (!correctCharacter(character)) {
            throw std::invalid_argument("Incorrect character: " + std::string(1, character));
        }
    }
}


Four& Four::operator=(const Four& copy)
{
    if (&copy != this) {
        number = copy.number;
    }
    return *this;
}

Four& Four::operator=(Four&& moved)
{
    if (&moved != this) {
        number = std::move(moved.number);
    }
    return *this;
}
