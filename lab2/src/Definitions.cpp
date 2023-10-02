#include "Definitions.h"

std::string OPERATORS[7] = {"+", "-", ">", "<", ">=", "<=", "="};

std::unordered_map<std::string, unsigned int> GET_OPERATOR_ID = 
{
    {"+", OPERETOR_ID::addOperator},
    {"-", OPERETOR_ID::subtractOperator},
    {">", OPERETOR_ID::greaterThanOperator},
    {"<", OPERETOR_ID::lowerTharOperator},
    {">=", OPERETOR_ID::greaterThanEqOperator},
    {"<=", OPERETOR_ID::lowerTharEqOperator},
    {"=", OPERETOR_ID::equalOperator},
};

