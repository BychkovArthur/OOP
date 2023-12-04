#pragma once
#include "../include/Figure.hpp"
#include "../include/Point.hpp"

double max4(double, double, double, double);
double min4(double, double, double, double);
double calcLength(Point, Point);
double getCosine(Point, Point, Point);
bool equalDoubleValues(double, double);

double getAngleCoefficientY(const Point, const Point);
double getBCoefficientY(const Point, const Point);
double getAngleCoefficientX(const Point, const Point);
double getBCoefficientX(const Point, const Point);

double calculateSquareOfFigures(const std::vector<Figure*>&);