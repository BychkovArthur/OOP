#include "../include/TrapezoidFactory.hpp"

#include "../include/Trapezoid.hpp"
#include "../include/TrapezoidValidator.hpp"

Figure* TrapezoidFactory::createFigure(const std::vector<Point>& points) {
    TrapezoidValidator validator;

    validator.validate(points);

    return new Trapezoid(points);
}