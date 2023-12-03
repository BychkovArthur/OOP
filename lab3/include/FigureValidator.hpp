#pragma once

#include <vector>

#include "Point.hpp"

class FigureValidator {
   public:
    virtual bool isValid(std::vector<Point>) = 0;
};
