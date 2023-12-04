#pragma once

#include <vector>

#include "Figure.hpp"

enum class OperationType {
    CREATE_PENTAGON,
    CREATE_TRAPEZOID,
    CREATE_RHOMBUS,
    QUIT,
    CALCULATE_TOTAL_SQUARE,
    PRINT_INFO_ABOUT_FIGURES,
    DELETE_FIGURE,
    ADD_FIGURE,
};

enum class MenuType {
    GENERAL,
    FIGURE_SELECTOR,
};

void menu();
void addFigure(std::vector<Figure*>&);
OperationType getOperationType(MenuType);
OperationType getOperationTypeByChar(int);
bool isValidCharacterInMenu(int);
void printMenu();
void printFigureSelector();