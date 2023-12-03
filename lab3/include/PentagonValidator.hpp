#pragma once

#include "FigureValidator.hpp"

class PentagonValidator : public FigureValidator {
   public:
    bool isValid(std::vector<Point>) override;
};
