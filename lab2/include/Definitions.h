#pragma once

#include <unordered_map>
#include <string>

#define OPERATORS_COUNT 7

enum OPERETOR_ID {
    addOperator,
    subtractOperator,
    greaterThanOperator,
    lowerTharOperator,
    greaterThanEqOperator,
    lowerTharEqOperator,
    equalOperator,
};

extern std::string OPERATORS[OPERATORS_COUNT];

extern std::unordered_map<std::string, unsigned int> GET_OPERATOR_ID;
