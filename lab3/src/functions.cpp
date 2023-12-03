#include "../include/functions.hpp"

#include <math.h>

double max4(double a, double b, double c, double d) {
    a = std::max(a, b);
    c = std::max(c, d);
    a = std::max(a, c);
    return a;
}

double min4(double a, double b, double c, double d) {
    a = std::min(a, b);
    c = std::min(c, d);
    a = std::min(a, c);
    return a;
}

double calcLength(Point a, Point b) { return std::sqrt(std::pow(a.x - b.x, 2) + std::pow(a.y - b.y, 2)); }