#include "../include/functions.hpp"

#include <cmath>
#include <vector>

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

double getCosine(Point b, Point a, Point c) {
    double lenA = calcLength(b, c);
    double lenB = calcLength(b, a);
    double lenC = calcLength(a, c);

    return (lenB * lenB + lenC * lenC - lenA * lenA) / (2 * lenB * lenC);
}

bool equalDoubleValues(double a, double b) {
    double EPS = 1e-3;
    return std::abs(a - b) < EPS;
}

double getAngleCoefficientY(const Point a, const Point b) { return (a.y - b.y) / (a.x - b.x); }

double getBCoefficientY(const Point a, const Point b) {
    double k = getAngleCoefficientY(a, b);
    return a.y - k * a.x;
}

double getAngleCoefficientX(const Point a, const Point b) { return (a.x - b.x) / (a.y - b.y); }

double getBCoefficientX(const Point a, const Point b) {
    double k = getAngleCoefficientX(a, b);
    return a.x - k * a.y;
}

double calculateSquareOfFigures(const std::vector<Figure*>& figures) {
    double result = 0;
    for (size_t i = 0; i < figures.size(); ++i) {
        result += static_cast<double>(*figures[i]);
    }
    return result;
}