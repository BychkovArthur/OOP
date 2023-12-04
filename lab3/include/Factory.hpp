#pragma once

#include <vector>

#include "Figure.hpp"
#include "Point.hpp"

class Factory {
   public:
    virtual Figure* createFigure(const std::vector<Point>&) = 0;
};
