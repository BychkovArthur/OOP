#pragma once
#include "Figure.hpp"

class Rhombus : public Figure {
    friend std::ostream& operator<<(std::ostream&, const Rhombus&);
    friend std::istream& operator>>(std::istream&, Rhombus&);

   private:
    static const size_t numberOfVertices = 4;

    Point vertices[numberOfVertices];

    void print(std::ostream&) const override;
    void read(std::istream&) override;

   public:
    explicit Rhombus(const std::vector<Point>&);

    static size_t getNumberOfVertices();
    Point getGeometricCenter() const override;
    operator double() const override;
};