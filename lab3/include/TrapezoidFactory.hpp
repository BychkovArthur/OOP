#pragma once

#include <vector>

#include "Factory.hpp"

class TrapezoidFactory : public Factory {
   public:
    Figure* createFigure(const std::vector<Point>&) override;
};
