#include "../include/Point.hpp"

#include <iostream>

Point::Point() : x(0.0), y(0.0) {}
Point::Point(int x, int y) : x(x), y(y) {}
Point::Point(double x, double y) : x(x), y(y) {}

std::ostream& operator<<(std::ostream& os, const Point& point) {
    os << point.x << " " << point.y;
    return os;
}

std::istream& operator>>(std::istream& is, Point& point) {
    is >> point.x >> point.y;
    return is;
}