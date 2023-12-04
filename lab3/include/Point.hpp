#pragma once
#include <iostream>

struct Point {
    double x, y;
    Point();
    Point(int x, int y);
    Point(double x, double y);
    Point(const Point&);
    Point(Point&&);

    bool operator==(const Point&) const;
    Point& operator=(const Point&);
    Point& operator=(Point&&);
};

std::ostream& operator<<(std::ostream& os, const Point& point);

std::istream& operator>>(std::istream& is, Point& point);