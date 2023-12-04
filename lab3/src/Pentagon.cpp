#include "../include/Pentagon.hpp"

#include <math.h>

#include <vector>

#include "../include/functions.hpp"

Pentagon::Pentagon(const std::vector<Point>& points) {
    for (size_t i = 0; i < Pentagon::getNumberOfVertices(); ++i) {
        vertices[i] = points[i];
    }
}

size_t Pentagon::getNumberOfVertices() { return numberOfVertices; }

Point Pentagon::getGeometricCenter() const {
    Point geometricCenter;

    double sumX = 0;
    double sumY = 0;

    for (size_t i = 0; i < numberOfVertices; ++i) {
        sumX += vertices[i].x;
        sumY += vertices[i].y;
    }
    geometricCenter.x = sumX / numberOfVertices;
    geometricCenter.y = sumY / numberOfVertices;

    return geometricCenter;
}

Pentagon::operator double() const {
    double sideLength = calcLength(vertices[0], vertices[1]);

    return (5 * std::pow(sideLength, 2) / (4 * tan(M_PI / 5)));
}

std::ostream& operator<<(std::ostream& os, const Pentagon& pentagon) {
    os << "Pentagon: ";
    for (size_t i = 0; i < pentagon.numberOfVertices; ++i) {
        os << "(" << pentagon.vertices[i] << ") ";
    }
    return os;
}
std::istream& operator>>(std::istream& is, Pentagon& pentagon) {
    for (size_t i = 0; i < pentagon.numberOfVertices; ++i) {
        is >> pentagon.vertices[i];
    }
    return is;
}

void Pentagon::print(std::ostream& os) const {
    os << "Pentagon: ";
    for (size_t i = 0; i < numberOfVertices; ++i) {
        os << "(" << vertices[i] << ") ";
    }
}

void Pentagon::read(std::istream& is) {
    for (size_t i = 0; i < numberOfVertices; ++i) {
        is >> vertices[i];
    }
}