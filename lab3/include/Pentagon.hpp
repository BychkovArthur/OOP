#pragma once
#include "Figure.hpp"

class Pentagon : public Figure {
    friend std::ostream& operator<<(std::ostream&, const Pentagon&);
    friend std::istream& operator>>(std::istream&, Pentagon&);

   private:
    static const size_t numberOfVertices = 5;
    Point vertices[numberOfVertices];

    void print(std::ostream&) const override;
    void read(std::istream&) override;

   public:
    explicit Pentagon(const std::vector<Point>&);

    static size_t getNumberOfVertices();
    Point getGeometricCenter() const override;
    operator double() const override;

    Pentagon& operator=(const Pentagon&);
    Pentagon& operator=(Pentagon&&);
    bool operator==(const Pentagon&);
};