#include "../include/PentagonValidator.hpp"

#include "../include/Pentagon.hpp"
#include "../include/functions.hpp"

bool PentagonValidator::isValid(std::vector<Point> points) {
    const size_t numberOfVertices = Pentagon::getNumberOfVertices();
    if (points.size() != numberOfVertices) {
        throw std::invalid_argument("Invalid number of points");
    }

    double length = -1;
    std::vector<double> sides;
    for (size_t i = 0; i < numberOfVertices; ++i) {
        if (length == -1) {
            length = calcLength(points[i], points[(i + 1) % numberOfVertices]);
        } else {
            double prevLength = length;
            length = calcLength(points[i], points[(i + 1) % numberOfVertices]);
            if (!equalDoubleValues(prevLength, length)) {
                throw std::invalid_argument("The points do not form a pentagon");
            }
        }
        sides.push_back(length);
    }

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
                throw std::invalid_argument("The points do not form a pentagon");
            }
        }
    }

    return true;
}