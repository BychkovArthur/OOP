#pragma once
#include "Figure.hpp"

class Trapezoid : public Figure {
    friend std::ostream& operator<<(std::ostream&, const Trapezoid&);
    friend std::istream& operator>>(std::istream&, Trapezoid&);

   private:
    static const unsigned int numberOfVertices = 4;

    double height;
    double smallerBaseLength;
    double biggerBaseLength;

    Point vertices[numberOfVertices];

    void calcHeight();
    void calcSidesLength();
    void print(std::ostream&) const override;
    void read(std::istream&) override;

   public:
    explicit Trapezoid(Point[numberOfVertices]);
    Trapezoid(Point, Point, Point, Point);

    Point getGeometricCenter() const override;

    operator double() const override;
};