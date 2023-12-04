#pragma once
#include "Figure.hpp"

class Trapezoid : public Figure {
    friend std::ostream& operator<<(std::ostream&, const Trapezoid&);
    friend std::istream& operator>>(std::istream&, Trapezoid&);

   private:
    static const size_t numberOfVertices = 4;
    std::vector<Point> vertices;

    double height;
    double smallerBaseLength;
    double biggerBaseLength;

    void calcHeight();
    void calcSidesLength();
    void print(std::ostream&) const override;
    void read(std::istream&) override;

   public:
    explicit Trapezoid(const std::vector<Point>&);
    Trapezoid(const Trapezoid&);
    Trapezoid(Trapezoid&&);

    Trapezoid& operator=(const Trapezoid&);
    Trapezoid& operator=(Trapezoid&&);
    bool operator==(const Trapezoid&) const;

    static size_t getNumberOfVertices();
    Point getGeometricCenter() const override;
    operator double() const override;
};