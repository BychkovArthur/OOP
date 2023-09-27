#include "../include/Four.h"
#include <iostream>
#include <math.h>

// TODO
// - virtual destructor
// - rvalue copy constructor
// - rewrite on own dynamic array
// - Проверка на число из верного множества (иначе, ошибка)
// - Возможно, последние два конструктора можно сделать без копирования. move - семантика



Four::Four()
{
    std::cout << "Default constructor" << std::endl;
    number.push_back((unsigned char) '0');
}


Four::Four(const size_t& n, unsigned char character = 0)
{
    std::cout << "Repeating character constructor" << std::endl;

    // Проверка на нужное число

    for (int i = 0; i < n; ++i) {
        number.push_back(character);
    }
}


Four::Four(const std::initializer_list<unsigned char>& initLst)
{
    std::cout << "Initializer_List constructor" << std::endl;

    // Проверка на нужное число

    for (const unsigned char* ptr = initLst.end() - 1; initLst.begin() <= ptr; --ptr) {
        number.push_back(*ptr);
    }
}


Four::Four(const std::string& other)
{ // mb without copy
    

    // Проверка на нужное число

    std::cout << "String constructor" << std::endl;

    for (int i =  other.size() - 1; 0 <= i; --i) {
        number.push_back(other[i]);
    }
}


Four::Four(const Four& other)
{ // mb without copy
    for (const unsigned char character : other.number) {
        number.push_back(character);
    }
    std::cout << "Copy constructor" << std::endl;
}


void Four::printNubmer()
{
    for (unsigned char& character : number) {
        std::cout << character << " ";
    }
    std::cout << std::endl;
}



unsigned int Four::charToNum(unsigned char character)
{
    // Проверка на отрицательные
    return character - (unsigned char) '0';
}

unsigned char Four::numToChar(unsigned int num)
{
    // Проверка на отрицательные
    return (unsigned char) '0' + num;
}


void Four::add(const Four& other)
{
    const int numberLen = number.size();
    const int otherNumberLen = other.number.size();

    int remainder = 0;

    for (int i = 0; i < max(numberLen, otherNumberLen); ++i) {
        unsigned int num = i < numberLen ? charToNum(number[i]) : 0;
        unsigned int otherNum = i < otherNumberLen ? charToNum(other.number[i]) : 0;
        unsigned int sum =  num + otherNum + remainder;

        unsigned char character = numToChar(sum % MAX_VALUE);
        if (i < numberLen) {
            number[i] = character;
        } else {
            number.push_back(character);
        }

        remainder = sum / MAX_VALUE;
    }

    if (remainder) {
        number.push_back(numToChar(remainder));
    }
}

bool Four::lowerThan(const Four& other)
{
    const int numberLen = number.size();
    const int otherNumberLen = other.number.size();

    if (otherNumberLen > numberLen) {
        return true;
    } else if (otherNumberLen < numberLen) {
        return false;
    }

    for (int i = 0; i < numberLen; ++i) {
        if (other.number[i] > number[i]) {
            return true;
        }
    }
    return false;
}

bool Four::lowerThanEq(const Four& other)
{
    return !(greaterThan(other));
}

bool Four::greaterThan(const Four& other)
{
    const int numberLen = number.size();
    const int otherNumberLen = other.number.size();

    if (otherNumberLen > numberLen) {
        return false;
    } else if (otherNumberLen < numberLen) {
        return true;
    }

    for (int i = 0; i < numberLen; ++i) {
        if (other.number[i] < number[i]) {
            return true;
        }
    }
    return false;
}

bool Four::greaterThanEq(const Four& other) {
    return !(this->lowerThan(other));
}

void Four::subtract(const Four& other)
{
    if (this->lowerThan(other)) {
        std::cout << "ERROR" << std::endl;
        return;
    }
}

int Four::min(const int a,const int b) {
    return a < b ? a : b;
}

int Four::max(const int a,const int b) {
    return a > b ? a : b;
}

int main() {
    // Four val = Four();

    Four val2  = Four("33333333332");
    Four val3 {"33333333333"};
    // Four val4{val3};

    // val.printNubmer();
    // val2.printNubmer();
    // val3.printNubmer();
    // val4.printNubmer();

    std::cout << val3.lowerThanEq(val2) << std::endl;
}