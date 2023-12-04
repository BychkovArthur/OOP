#include "RhombusValidator.hpp"

#include "Rhombus.hpp"
#include "functions.hpp"

void RhombusValidator::validate(const std::vector<Point>& points) {
    RhombusValidator::validateNumberOfVertices(points);
    RhombusValidator::validateParallelLines(points);
    RhombusValidator::validateLengthOfSides(points);
}

void RhombusValidator::validateNumberOfVertices(const std::vector<Point>& points) {
    const size_t numberOfVertices = Rhombus::getNumberOfVertices();
    if (points.size() != numberOfVertices) {
        throw std::invalid_argument("Invalid number of points");
    }
}

void RhombusValidator::validateParallelLines(const std::vector<Point>& points) {
    const size_t numberOfVertices = Rhombus::getNumberOfVertices();

    for (size_t i = 0; i < numberOfVertices / 2; ++i) {
        double k1, k2, b1, b2;
        double (*getAngleCoefficient)(Point, Point);
        double (*getBCoefficient)(Point, Point);

        if (points[i].x == points[i + 1].x) {
            getAngleCoefficient = getAngleCoefficientX;
            getBCoefficient = getBCoefficientX;
        } else {
            getAngleCoefficient = getAngleCoefficientY;
            getBCoefficient = getBCoefficientY;
        }

        k1 = getAngleCoefficient(points[i], points[i + 1]);
        b1 = getBCoefficient(points[i], points[i + 1]);

        k2 = getAngleCoefficient(points[i + 2], points[(i + 3) % numberOfVertices]);
        b2 = getBCoefficient(points[i + 2], points[(i + 3) % numberOfVertices]);

        if (!equalDoubleValues(k1, k2) || (equalDoubleValues(k1, k2) && equalDoubleValues(b1, b2))) {
            throw std::invalid_argument("The sides are not parallel");
        }
    }
}

void RhombusValidator::validateLengthOfSides(const std::vector<Point>& points) {
    const size_t numberOfVertices = Rhombus::getNumberOfVertices();
    double length = -1;
    for (size_t i = 0; i < numberOfVertices; ++i) {
        if (length == -1) {
            length = calcLength(points[i], points[(i + 1) % numberOfVertices]);
        } else {
            double prevLength = length;
            length = calcLength(points[i], points[(i + 1) % numberOfVertices]);
            if (!equalDoubleValues(prevLength, length) || equalDoubleValues(length, 0)) {
                throw std::invalid_argument("Invalid length of sides");
            }
        }
    }
}