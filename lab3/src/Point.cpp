#include "Point.hpp"

#include <iostream>

#include "functions.hpp"

Point::Point() : x(0.0), y(0.0) {}
Point::Point(int x, int y) : x(x), y(y) {}
Point::Point(double x, double y) : x(x), y(y) {}
Point::Point(const Point& copy) : x(copy.x), y(copy.y) {}
Point::Point(Point&& moved) : x(moved.x), y(moved.y) {
    moved.x = 0;
    moved.y = 0;
}

bool Point::operator==(const Point& point) const { return equalDoubleValues(x, point.x) && equalDoubleValues(y, point.y); }

Point& Point::operator=(const Point& copy) {
    if (this == &copy) {
        return *this;
    }

    x = copy.x;
    y = copy.y;
    return *this;
}

Point& Point::operator=(Point&& moved) {
    if (this == &moved) {
        return *this;
    }

    x = moved.x;
    y = moved.y;
    moved.x = 0;
    moved.y = 0;
    return *this;
}

std::ostream& operator<<(std::ostream& os, const Point& point) {
    os << point.x << " " << point.y;
    return os;
}

std::istream& operator>>(std::istream& is, Point& point) {
    is >> point.x >> point.y;
    return is;
}