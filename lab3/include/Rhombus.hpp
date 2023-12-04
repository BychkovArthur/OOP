#pragma once
#include "Figure.hpp"

class Rhombus : public Figure {
    friend std::ostream& operator<<(std::ostream&, const Rhombus&);
    friend std::istream& operator>>(std::istream&, Rhombus&);

   private:
    static const size_t numberOfVertices = 4;
    std::vector<Point> vertices;

    void print(std::ostream&) const override;
    void read(std::istream&) override;

   public:
    explicit Rhombus(const std::vector<Point>&);
    Rhombus(const Rhombus&);
    Rhombus(Rhombus&&);

    Rhombus& operator=(const Rhombus&);
    Rhombus& operator=(Rhombus&&);
    bool operator==(const Rhombus&) const;

    static size_t getNumberOfVertices();
    Point getGeometricCenter() const override;
    operator double() const override;
};