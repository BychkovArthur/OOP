#include "PentagonFactory.hpp"

#include "Pentagon.hpp"
#include "PentagonValidator.hpp"

Figure* PentagonFactory::createFigure(const std::vector<Point>& points) {
    PentagonValidator validator;

    validator.validate(points);

    return new Pentagon(points);
}