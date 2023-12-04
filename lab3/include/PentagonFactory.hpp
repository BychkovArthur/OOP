#pragma once

#include <vector>

#include "Factory.hpp"

class PentagonFactory : public Factory {
   public:
    Figure* createFigure(const std::vector<Point>&) override;
};
