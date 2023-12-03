#pragma once
#include "Figure.hpp"

class Rhombus : public Figure
{
    friend std::ostream& operator<<(std::ostream&, const Rhombus&);
    friend std::istream& operator>>(std::istream&, Rhombus&);
private:
    static const unsigned int numberOfVertices = 4;

    Point vertices[numberOfVertices];

    void print(std::ostream&) const override;
    void read(std::istream&) override;
public:
    Rhombus(Point, Point, Point, Point);
    Rhombus(Point[numberOfVertices]);

    Point getGeometricCenter() const override;
    operator double() const override;
}; 