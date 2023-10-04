#include "Four.h"
#include "functions.h"
#include "Definitions.h"
#include <iostream>
#include <unordered_map>

int main() {
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