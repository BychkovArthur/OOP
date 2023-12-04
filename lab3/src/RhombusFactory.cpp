#include "RhombusFactory.hpp"

#include "Rhombus.hpp"
#include "RhombusValidator.hpp"

Figure* RhombusFactory::createFigure(const std::vector<Point>& points) {
    RhombusValidator validator;

    validator.validate(points);

    return new Rhombus(points);
}