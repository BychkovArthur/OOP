#include "Trapezoid.hpp"

#include <math.h>

#include <vector>

#include "functions.hpp"

Trapezoid::Trapezoid(const std::vector<Point>& points) : vertices(points) {
    calcHeight();
    calcSidesLength();
}

Trapezoid::Trapezoid(const Trapezoid& copy) : vertices(copy.vertices) {
    calcHeight();
    calcSidesLength();
}

Trapezoid::Trapezoid(Trapezoid&& moved) : vertices(std::move(moved.vertices)) {
    calcHeight();
    calcSidesLength();
}

Trapezoid& Trapezoid::operator=(const Trapezoid& copy) {
    if (this == &copy) {
        return *this;
    }

    vertices = copy.vertices;
    height = copy.height;
    smallerBaseLength = copy.smallerBaseLength;
    biggerBaseLength = copy.biggerBaseLength;
    return *this;
}

Trapezoid& Trapezoid::operator=(Trapezoid&& moved) {
    if (this == &moved) {
        return *this;
    }

    vertices = std::move(moved.vertices);
    height = moved.height;
    smallerBaseLength = moved.smallerBaseLength;
    biggerBaseLength = moved.biggerBaseLength;

    moved.height = 0;
    moved.biggerBaseLength = 0;
    moved.smallerBaseLength = 0;
    return *this;
}

bool Trapezoid::operator==(const Trapezoid& other) const { return vertices == other.vertices; }

void Trapezoid::calcHeight() {
    if (vertices[0].x == vertices[1].x) {
        height = std::abs(vertices[0].x - vertices[3].x);
    } else {
        height = std::abs(vertices[0].y - vertices[3].y);
    }
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

Trapezoid::operator double() const { return (smallerBaseLength + biggerBaseLength) * height / 2; }

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