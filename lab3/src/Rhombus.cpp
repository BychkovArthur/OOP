#include "../include/Rhombus.hpp"

#include <vector>

#include "../include/functions.hpp"

Rhombus::Rhombus(const std::vector<Point>& points) {
    for (size_t i = 0; i < Rhombus::getNumberOfVertices(); ++i) {
        vertices[i] = points[i];
    }
}

Point Rhombus::getGeometricCenter() const {
    Point geometricCenter;

    double maxX = max4(vertices[0].x, vertices[1].x, vertices[2].x, vertices[3].x);
    double maxY = max4(vertices[0].y, vertices[1].y, vertices[2].y, vertices[3].y);
    double minX = min4(vertices[0].x, vertices[1].x, vertices[2].x, vertices[3].x);
    double minY = min4(vertices[0].y, vertices[1].y, vertices[2].y, vertices[3].y);

    geometricCenter.x = (maxX + minX) / 2;
    geometricCenter.y = (maxY + minY) / 2;

    return geometricCenter;
}

Rhombus::operator double() const {
    double diagLength1 = calcLength(vertices[0], vertices[2]);
    double diagLength2 = calcLength(vertices[1], vertices[3]);

    return diagLength1 * diagLength2 / 2;
}

std::ostream& operator<<(std::ostream& os, const Rhombus& trapezoid) {
    os << "Rhombus: ";
    for (size_t i = 0; i < trapezoid.numberOfVertices; ++i) {
        os << "(" << trapezoid.vertices[i] << ") ";
    }
    return os;
}
std::istream& operator>>(std::istream& is, Rhombus& trapezoid) {
    for (size_t i = 0; i < trapezoid.numberOfVertices; ++i) {
        is >> trapezoid.vertices[i];
    }
    return is;
}

void Rhombus::print(std::ostream& os) const {
    os << "Rhombus: ";
    for (size_t i = 0; i < numberOfVertices; ++i) {
        os << "(" << vertices[i] << ") ";
    }
}

void Rhombus::read(std::istream& is) {
    for (size_t i = 0; i < numberOfVertices; ++i) {
        is >> vertices[i];
    }
}

size_t Rhombus::getNumberOfVertices() { return numberOfVertices; }