#include "../include/PentagonFactory.hpp"

#include "../include/Pentagon.hpp"
#include "../include/PentagonValidator.hpp"

Figure* PentagonFactory::createFigure(const std::vector<Point>& points) {
    PentagonValidator validator;

    validator.validate(points);

    return new Pentagon(points);
}