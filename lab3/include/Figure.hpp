#pragma once
#include <iostream>

#include "Point.hpp"
class Figure {
    friend std::ostream& operator<<(std::ostream&, const Figure&);
    friend std::istream& operator>>(std::istream&, Figure&);

   public:
    Figure() = default;

    virtual Point getGeometricCenter() const = 0;
    virtual operator double() const = 0;

    virtual void print(std::ostream&) const = 0;
    virtual void read(std::istream&) = 0;

    ~Figure() = default;
};
