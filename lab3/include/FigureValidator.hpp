#pragma once

#include <vector>

#include "Point.hpp"

class FigureValidator {
   public:
    virtual void validate(const std::vector<Point>&) = 0;
};
