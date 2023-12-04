#include "../include/Pentagon.hpp"
#include "../include/PentagonFactory.hpp"
#include "../include/PentagonValidator.hpp"
#include "../include/Rhombus.hpp"
#include "../include/RhombusFactory.hpp"
#include "../include/RhombusValidator.hpp"
#include "../include/Trapezoid.hpp"
#include "../include/TrapezoidFactory.hpp"
#include "../include/TrapezoidValidator.hpp"
#include "../include/OperationType.hpp"
#include "../include/functions.hpp"

void printFigureSelector() {
    std::cout << ">>> Select figure: " << std::endl;
    std::cout << "> (T/t) - Create trapezoid" << std::endl;
    std::cout << "> (P/p) - Create pentagon" << std::endl;
    std::cout << "> (R/r) - Create rhombus" << std::endl;
}

void printMenu() {
    std::cout << ">>> Select action: " << std::endl;
    std::cout << "> (A/a) - Add new figure into vector" << std::endl;
    std::cout << "> (S/s) - Calculate total square" << std::endl;
    std::cout << "> (D/d) - Delete figure by index" << std::endl;
    std::cout << "> (F/f) - Print all info about figures (geometrical center, square, points)" << std::endl;
    std::cout << "> (Q/q) - Quit" << std::endl;
}


bool isValidCharacterInMenu(int character) {
    return character == 'a' || character == 's' || character == 'd' || character == 'f' || character == 'i';
}

bool isValidCharacterFigureSelector(int character) {
    return character == 't' || character == 'p' || character == 'r';
}

OperationType getOperationTypeByChar(int character) {
    OperationType result;
    switch (character)
    {
    case 'q':
        result = OperationType::QUIT;
        break;
    case 't':
        result = OperationType::CREATE_TRAPEZOID;
        break;
    case 'p':
        result = OperationType::CREATE_PENTAGON;
        break;
    case 'r':
        result = OperationType::CREATE_RHOMBUS;
        break;
    case 's':
        result = OperationType::CALCULATE_TOTAL_SQUARE;
        break;
    case 'f':
        result = OperationType::PRINT_INFO_ABOUT_FIGURES;
        break;
    case 'd':
        result = OperationType::DELETE_FIGURE;
        break;
    case 'a':
        result = OperationType::ADD_FIGURE;
        break;
    }
    return result;
}

OperationType getOperationType(MenuType type) {
    std::cout << "> ";

    int char1, char2;
    bool (*validator)(int);

    char1 = getchar();
    char2 = getchar();

    if (type == MenuType::GENERAL) {
        validator = isValidCharacterInMenu;
    } else if (type == MenuType::FIGURE_SELECTOR) {
        validator = isValidCharacterFigureSelector;
    }

    if (!validator(tolower(char1)) || char2 != '\n') {
        throw std::invalid_argument("Invalid operation type");
    }
    return getOperationTypeByChar(char1);
}

void menu() {
    RhombusFactory rhombusFactory;
    PentagonFactory pentagonFactory;
    TrapezoidFactory trapezoidFactory;

    std::vector<Figure*> figures;

    while (true) {
        printMenu();
        OperationType type = getOperationType(MenuType::GENERAL);

        switch (type)
        {
        case OperationType::CREATE_PENTAGON:
            figures.push_back(pentagonFactory.createFigure());
            break;
        case OperationType::CREATE_TRAPEZOID:
            figures.push_back(trapezoidFactory.createFigure());
            break;
        case OperationType::CREATE_RHOMBUS:
            figures.push_back(rhombusFactory.createFigure());
            break;
        case OperationType::CALCULATE_TOTAL_SQUARE:
            std::cout << "Total square: " << calculateSquareOfFigures(figures) << std::endl;
            break;
        case OperationType::PRINT_INFO_ABOUT_FIGURES:
            for (size_t i = 0; i < figures.size(); ++i) {
                std::cout << *figures[i] << std::endl;
                std::cout << "Geometric center: " << figures[i]->getGeometricCenter() << std::endl;
                std::cout << "Square: " << static_cast<double>(*figures[i]) << std::endl;
            }
            break;
        case OperationType::DELETE_FIGURE:
            size_t index;
            std::cout << ">>> Input index: " << std::endl;
            std::cout << "> ";
            std::cin >> index;
            figures.at(index);
            figures.erase(figures.begin() + index);
            break;
        case OperationType::ADD_FIGURE:
            return;
        case OperationType::QUIT:
            return;
        }
        
    }
    
}


int main() {
    menu();
    return 0;
}