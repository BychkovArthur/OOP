#pragma once

#include <vector>

#include "Factory.hpp"

class RhombusFactory : public Factory {
   public:
    Figure* createFigure(const std::vector<Point>&) override;
};
