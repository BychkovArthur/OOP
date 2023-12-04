#include "../include/Trapezoid.hpp"

#include <math.h>

#include <vector>

#include "../include/functions.hpp"

Trapezoid::Trapezoid(const std::vector<Point>& points) {
    for (size_t i = 0; i < Trapezoid::getNumberOfVertices(); ++i) {
        vertices[i] = points[i];
    }

    calcHeight();
    calcSidesLength();
}

void Trapezoid::calcHeight() {
    double sideLength1 = calcLength(vertices[1], vertices[2]);
    double sideLength2 = calcLength(vertices[3], vertices[0]);

    height =
        std::sqrt(std::pow(sideLength1, 2) - std::pow((std::pow(smallerBaseLength - biggerBaseLength, 2) +
                                                       std::pow(sideLength1, 2) - std::pow(sideLength2, 2)) /
                                                          (2 * (smallerBaseLength - biggerBaseLength)),
                                                      2));
}

void Trapezoid::calcSidesLength() {
    smallerBaseLength = calcLength(vertices[0], vertices[1]);
    biggerBaseLength = calcLength(vertices[2], vertices[3]);
}

size_t Trapezoid::getNumberOfVertices() { return numberOfVertices; }

Point Trapezoid::getGeometricCenter() const {
    Point geometricCenter;
    geometricCenter.x = (vertices[0].x + vertices[1].x) / 2;
    geometricCenter.y = (vertices[0].y + vertices[1].y) / 2;
    geometricCenter.y += (height / 3.0) * ((2 * biggerBaseLength) + smallerBaseLength) /
                         (biggerBaseLength + smallerBaseLength);

    return geometricCenter;
}

Trapezoid::operator double() const {
    double smallerBaseLength = calcLength(vertices[0], vertices[1]);
    double biggerBaseLength = calcLength(vertices[2], vertices[3]);
    return (smallerBaseLength + biggerBaseLength) * height / 2;
}

std::ostream& operator<<(std::ostream& os, const Trapezoid& trapezoid) {
    os << "Trapezoid: ";
    for (size_t i = 0; i < trapezoid.numberOfVertices; ++i) {
        os << "(" << trapezoid.vertices[i] << ") ";
    }
    return os;
}
std::istream& operator>>(std::istream& is, Trapezoid& trapezoid) {
    for (size_t i = 0; i < trapezoid.numberOfVertices; ++i) {
        is >> trapezoid.vertices[i];
    }
    return is;
}

void Trapezoid::print(std::ostream& os) const {
    os << "Trapezoid: ";
    for (size_t i = 0; i < numberOfVertices; ++i) {
        os << "(" << vertices[i] << ") ";
    }
}

void Trapezoid::read(std::istream& is) {
    for (size_t i = 0; i < numberOfVertices; ++i) {
        is >> vertices[i];
    }
}