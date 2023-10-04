#include "functions.h"
#include "Definitions.h"
#include "Four.h"
#include <iostream>

void printStartInfo() {
    std::cout << "Enter <number> <number> <operator> ( ";
    for (size_t i = 0; i < OPERATORS_COUNT - 1; ++i) {
        std::cout << OPERATORS[i] << ", ";
    }
    std::cout << OPERATORS[OPERATORS_COUNT - 1];
    std::cout << " ) or \"q\", for quit" << std::endl;
}

void printResultOfAction(std::string& op, Four& number1, Four& number2) {
        std::cout << "Result: ";

        switch (GET_OPERATOR_ID[op])
        {
            case OPERETOR_ID::addOperator:
                number1.add(number2);
                number1.print();
                break;
            case OPERETOR_ID::subtractOperator:
                number1.subtract(number2);
                number1.print();
                break;
            case OPERETOR_ID::greaterThanOperator:
                std::cout << std::boolalpha << number1.greaterThan(number2) << std::endl;
                break;
            case OPERETOR_ID::lowerTharOperator:
                std::cout << std::boolalpha << number1.lowerThan(number2) << std::endl;
                break;
            case OPERETOR_ID::greaterThanEqOperator:
                std::cout << std::boolalpha << number1.greaterThanEq(number2) << std::endl;
                break;
            case OPERETOR_ID::lowerTharEqOperator:
                std::cout << std::boolalpha << number1.lowerThanEq(number2) << std::endl;
                break;
            case OPERETOR_ID::equalOperator:
                std::cout << std::boolalpha << number1.equal(number2) << std::endl;
                break;
        }
}
