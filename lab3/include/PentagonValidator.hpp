#pragma once

#include "FigureValidator.hpp"

class PentagonValidator : public FigureValidator {
    static void validateNumberOfVertices(const std::vector<Point>&);
    static void validateLengthOfSides(const std::vector<Point>&);
    static void validateAngles(const std::vector<Point>&);

   public:
    void validate(const std::vector<Point>&) override;
};
