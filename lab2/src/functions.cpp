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

void runApplication()
{
    while (true)
    {
        printStartInfo();
        std::string num1;
        std::string num2;
        std::string op;

        std::cin >> num1;
        if (num1 == "q") {
            break;
        }
        std::cin >> num2;
        if (num2 == "q") {
            break;
        }
        std::cin >> op; 
        if (op == "q") {
            break;
        }

        if (GET_OPERATOR_ID.count(op) == 0) {
            throw std::invalid_argument("Incorrect operator");
        }

        Four number1(num1);
        Four number2(num2);

        printResultOfAction(op, number1, number2);

        std::cout << std::endl;
    }
}
