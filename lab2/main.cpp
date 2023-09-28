#include "../include/Four.h"
#include <iostream>
#include <unordered_map>
std::unordered_map<std::string, unsigned int> OPERATORS = 
{
    {"+", 0},
    {"-", 1},
    {">", 2},
    {"<", 3},
    {">=", 4},
    {"<=", 5},
    {"=", 6},
};

inline std::string boolToStr(bool value) {
    return value ? "True" : "False";
}

int main() {
    while (true)
    {
        std::cout << "Enter <number> <number> <operator> ( +, -, >, <, >=, <=, =) or \"q\", for quit" << std::endl;
        std::string num1;
        std::string num2;
        std::string op;
        std::cin >> num1; if (num1 == "q") {break;}
        std::cin >> num2; if (num2 == "q") {break;}
        std::cin >> op; if (op == "q") {break;}
        
        if (OPERATORS.count(op) == 0) {
            throw std::runtime_error("Incorrect operator");
        }

        Four number1(num1);
        Four number2(num2);

        std::cout << "Result: ";

        switch (OPERATORS[op])
        {
            case 0:
                number1.add(number2);
                number1.print();
                break;
            case 1:
                number1.subtract(number2);
                number1.print();
                break;
            case 22:
                std::cout << boolToStr(number1.greaterThan(number2)) << std::endl;
                break;
            case 3:
                std::cout << boolToStr(number1.lowerThan(number2)) << std::endl;
                break;
            case 4:
                std::cout << boolToStr(number1.greaterThanEq(number2)) << std::endl;
                break;
            case 5:
                std::cout << boolToStr(number1.lowerThanEq(number2)) << std::endl;
                break;
            case 6:
                std::cout << boolToStr(number1.equal(number2)) << std::endl;
                break;

        }

        std::cout << std::endl;
    }
    
}