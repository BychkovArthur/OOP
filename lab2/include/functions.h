#pragma once

#include "Four.h"
#include <string>

inline unsigned int charToNum(unsigned char character)
{
    return character - (unsigned char) '0';
}

inline unsigned char numToChar(unsigned int num)
{
    return (unsigned char) '0' + num;
}

void printStartInfo();

void printResultOfAction(std::string&, Four&, Four&);

void runApplication();
