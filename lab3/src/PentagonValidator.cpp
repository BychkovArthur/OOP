#include "../include/PentagonValidator.hpp"

#include "../include/Pentagon.hpp"
#include "../include/functions.hpp"

void PentagonValidator::validate(const std::vector<Point>& points) {
    PentagonValidator::validateNumberOfVertices(points);
    PentagonValidator::validateLengthOfSides(points);
    PentagonValidator::validateAngles(points);
}

void PentagonValidator::validateNumberOfVertices(const std::vector<Point>& points) {
    const size_t numberOfVertices = Pentagon::getNumberOfVertices();
    if (points.size() != numberOfVertices) {
        throw std::invalid_argument("Invalid number of points");
    }
}

void PentagonValidator::validateLengthOfSides(const std::vector<Point>& points) {
    const size_t numberOfVertices = Pentagon::getNumberOfVertices();
    double length = -1;
    for (size_t i = 0; i < numberOfVertices; ++i) {
        if (length == -1) {
            length = calcLength(points[i], points[(i + 1) % numberOfVertices]);
        } else {
            double prevLength = length;
            length = calcLength(points[i], points[(i + 1) % numberOfVertices]);
            if (!equalDoubleValues(prevLength, length) || equalDoubleValues(length, 0)) {
                throw std::invalid_argument("Invalid angels between sides");
            }
        }
    }
}

void PentagonValidator::validateAngles(const std::vector<Point>& points) {
    const size_t numberOfVertices = Pentagon::getNumberOfVertices();
    double cosine = -2;
    for (size_t i = 0; i < numberOfVertices; ++i) {
        if (cosine == -2) {
            cosine = getCosine(points[(i + numberOfVertices - 1) % numberOfVertices], points[i],
                               points[(i + 1) % numberOfVertices]);

        } else {
            double prevCosine = cosine;

            cosine = getCosine(points[(i + numberOfVertices - 1) % numberOfVertices], points[i],
                               points[(i + 1) % numberOfVertices]);

            if (!equalDoubleValues(prevCosine, cosine)) {
                throw std::invalid_argument("Invalid length of sides");
            }
        }
    }
}