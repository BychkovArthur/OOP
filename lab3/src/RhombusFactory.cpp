#include "../include/RhombusFactory.hpp"

#include "../include/Rhombus.hpp"
#include "../include/RhombusValidator.hpp"

Figure* RhombusFactory::createFigure(const std::vector<Point>& points) {
    RhombusValidator validator;

    validator.validate(points);

    return new Rhombus(points);
}