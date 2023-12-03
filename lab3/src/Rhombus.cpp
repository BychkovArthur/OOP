#include "../include/Rhombus.hpp"
#include "../include/Definitions.hpp"
#include "../include/functions.hpp"

Rhombus::Rhombus(Point first, Point second, Point third, Point fourth)
{
    vertices[0] = first;
    vertices[1] = second;
    vertices[2] = third;
    vertices[3] = fourth;
}

Rhombus::Rhombus(Point _vertices[numberOfVertices]) : 
    Rhombus(_vertices[0], _vertices[1], _vertices[2], _vertices[3]) {}

Point Rhombus::getGeometricCenter() const
{
    Point geometricCenter;

    double maxX = max4(vertices[0].x, vertices[1].x, vertices[2].x, vertices[3].x);
    double maxY = max4(vertices[0].y, vertices[1].y, vertices[2].y, vertices[3].y);
    double minX = min4(vertices[0].x, vertices[1].x, vertices[2].x, vertices[3].x);
    double minY = min4(vertices[0].y, vertices[1].y, vertices[2].y, vertices[3].y);

    geometricCenter.x = (maxX + minX) / 2;
    geometricCenter.y = (maxY + minY) / 2;

    return geometricCenter;
}

Rhombus::operator double() const
{
    double diagLength1 = calcLength(vertices[0], vertices[2]);
    double diagLength2 = calcLength(vertices[1], vertices[3]);

    return diagLength1 * diagLength2 / 2;
}

std::ostream& operator<<(std::ostream& os, const Rhombus& trapezoid)
{
    os << "Rhombus: ";
    for (size_t i = 0; i < trapezoid.numberOfVertices; ++i) {
        os << "(" << trapezoid.vertices[i] << ") " ;
    }
    return os;
}
std::istream& operator>>(std::istream& is, Rhombus& trapezoid)
{
    for (size_t i = 0; i < trapezoid.numberOfVertices; ++i) {
        is >> trapezoid.vertices[i];
    }
    return is;
}

void Rhombus::print(std::ostream& os) const {
    os << "Rhombus: ";
    for (size_t i = 0; i < numberOfVertices; ++i) {
        os << "(" << vertices[i] << ") " ;
    }
}

void Rhombus::read(std::istream& is) {
    for (size_t i = 0; i < numberOfVertices; ++i) {
        is >> vertices[i];
    }
}