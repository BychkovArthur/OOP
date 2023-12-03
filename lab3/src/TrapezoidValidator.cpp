#include "../include/TrapezoidValidator.hpp"

#include "../include/Trapezoid.hpp"
#include "../include/functions.hpp"

void TrapezoidValidator::validate(const std::vector<Point>& points) {
    TrapezoidValidator::validateNumberOfVertices(points);
    TrapezoidValidator::validateParallelLines(points);
}

void TrapezoidValidator::validateNumberOfVertices(const std::vector<Point>& points) {
    const size_t numberOfVertices = Trapezoid::getNumberOfVertices();
    if (points.size() != numberOfVertices) {
        throw std::invalid_argument("Invalid number of points");
    }
}

void TrapezoidValidator::validateParallelLines(const std::vector<Point>& points) {
    const size_t numberOfVertices = Trapezoid::getNumberOfVertices();

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

        if (i == 0) {
            if (!equalDoubleValues(k1, k2) || (equalDoubleValues(k1, k2) && equalDoubleValues(b1, b2))) {
                throw std::invalid_argument("The sides are not parallel");
            }
        } else {
            if (equalDoubleValues(k1, k2) || (equalDoubleValues(k1, k2) && equalDoubleValues(b1, b2))) {
                throw std::invalid_argument("The sides are parallel");
            }
        }
    }
}