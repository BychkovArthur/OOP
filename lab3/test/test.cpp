#include <gtest/gtest.h>
#include <tuple>
#include <vector>
#include <cmath>

#include "Point.hpp"
#include "Trapezoid.hpp"
#include "Pentagon.hpp"
#include "Rhombus.hpp"
#include "RhombusFactory.hpp"
#include "TrapezoidFactory.hpp"
#include "PentagonFactory.hpp"
#include "functions.hpp"

PentagonFactory pentagonFactory;
RhombusFactory rhombusFactory;
TrapezoidFactory trapezoidFactory;

class TrapezoidIncorrectParametrTest :public ::testing::TestWithParam<std::vector<Point>> { };

TEST_P(TrapezoidIncorrectParametrTest, IncorrectVertices) {
    // arrange
    std::vector<Point> points = GetParam();

    // act
    // Must be std::invalid_argument

    // assert
    ASSERT_THROW(trapezoidFactory.createFigure(points), std::invalid_argument);

}

INSTANTIATE_TEST_CASE_P(
        TrapezoidIncorrectTest,
        TrapezoidIncorrectParametrTest,
        ::testing::Values(
                std::vector<Point>{Point(0, 0), Point(1, 0), Point(0, 0), Point(1, 0)},
                std::vector<Point>{Point(0, 0), Point(1, 0), Point(0, 0), Point(1, 0), Point(1, 2), Point(3, 4)},
                std::vector<Point>{Point(0, 0), Point(1, 0), Point(0, 0)},
                std::vector<Point>{Point(0, 0), Point(0, 1), Point(1, 1), Point(2, 0)}));

class RhombusIncorrectParametrTest :public ::testing::TestWithParam<std::vector<Point>> { };

TEST_P(RhombusIncorrectParametrTest, IncorrectVertices) {
    // arrange
    std::vector<Point> points = GetParam();

    // act
    // Must be std::invalid_argument

    // assert
    ASSERT_THROW(rhombusFactory.createFigure(points), std::invalid_argument);

}

INSTANTIATE_TEST_CASE_P(
        RhombusIncorrectTest,
        RhombusIncorrectParametrTest,
        ::testing::Values(
                std::vector<Point>{Point(0, 0), Point(1, 0), Point(0, 0), Point(1, 0)},
                std::vector<Point>{Point(0, 0), Point(1, 0), Point(0, 0), Point(1, 0), Point(1, 2), Point(3, 4)},
                std::vector<Point>{Point(0, 0), Point(1, 0), Point(0, 0)},
                std::vector<Point>{Point(0, 0), Point(0, 1), Point(1, 1), Point(2, 0)}));


class PentagonIncorrectParametrTest :public ::testing::TestWithParam<std::vector<Point>> { };

TEST_P(PentagonIncorrectParametrTest, IncorrectVertices) {
    // arrange
    std::vector<Point> points = GetParam();

    // act
    // Must be std::invalid_argument

    // assert
    ASSERT_THROW(pentagonFactory.createFigure(points), std::invalid_argument);

}

INSTANTIATE_TEST_CASE_P(
        PentagonIncorrectTest,
        PentagonIncorrectParametrTest,
        ::testing::Values(
                std::vector<Point>{Point(0, 0), Point(1, 0), Point(0, 0), Point(1, 0)},
                std::vector<Point>{Point(0, 0), Point(1, 0), Point(0, 0), Point(1, 0), Point(1, 2), Point(3, 4)},
                std::vector<Point>{Point(0, 0), Point(1, 0), Point(0, 0), Point(1, 2), Point(3, 4)},
                std::vector<Point>{Point(0, 0), Point(0, 1), Point(1, 1), Point(2, 0), Point(8, -15)}));

class TrapezoidSquareParametrTest :public ::testing::TestWithParam<std::pair<std::vector<Point>, double>> { };

TEST_P(TrapezoidSquareParametrTest, IncorrectVertices) {
    // arrange
    std::vector<Point> points = GetParam().first;
    double correctResult = GetParam().second;
    Figure* trapezoid = trapezoidFactory.createFigure(points);

    // act
    double square = static_cast<double>(*trapezoid);

    // assert
    EXPECT_EQ(square, correctResult);

}

INSTANTIATE_TEST_CASE_P(
        TrapezoidSquareTest,
        TrapezoidSquareParametrTest,
        ::testing::Values(
                std::pair(std::vector<Point>{Point(1, 1), Point(2, 1), Point(3, 0), Point(0, 0)}, 2),
                std::pair(std::vector<Point>{Point(2, -1), Point(1, -1), Point(0, 0), Point(3, 0)}, 2),
                std::pair(std::vector<Point>{Point(0, 1), Point(0, 2), Point(1, 3), Point(1, 0)}, 2),
                std::pair(std::vector<Point>{Point(1, 2), Point(1, 1), Point(0, 0), Point(0, 3)}, 2)));

class RhombusSquareParametrTest :public ::testing::TestWithParam<std::pair<std::vector<Point>, double>> { };

TEST_P(RhombusSquareParametrTest, IncorrectVertices) {
    // arrange
    std::vector<Point> points = GetParam().first;
    double correctResult = GetParam().second;
    Figure* rhombus = rhombusFactory.createFigure(points);

    // act
    double square = static_cast<double>(*rhombus);

    // assert
    EXPECT_EQ(equalDoubleValues(square, correctResult), true);

}

INSTANTIATE_TEST_CASE_P(
        RhombusSquareTest,
        RhombusSquareParametrTest,
        ::testing::Values(
                std::pair(std::vector<Point>{Point(0, 0), Point(0, 1), Point(1, 1), Point(1, 0)}, 1),
                std::pair(std::vector<Point>{Point(0, 1), Point(1, 0), Point(0, -1), Point(-1, 0)}, 2),
                std::pair(std::vector<Point>{Point(0, 2), Point(1, 0), Point(0, -2), Point(-1, 0)}, 4),
                std::pair(std::vector<Point>{Point(0, 1), Point(2, 0), Point(0, -1), Point(-2, 0)}, 4)));

class PentagonSquareParametrTest :public ::testing::TestWithParam<std::pair<std::vector<Point>, double>> { };

TEST_P(PentagonSquareParametrTest, IncorrectVertices) {
    // arrange
    double EPS = 1e-1;
    std::vector<Point> points = GetParam().first;
    double correctResult = GetParam().second;
    Figure* pentagon = pentagonFactory.createFigure(points);

    // act
    double square = static_cast<double>(*pentagon);

    // assert
    EXPECT_EQ(std::abs(square - correctResult) < EPS, true);
}

INSTANTIATE_TEST_CASE_P(
        PentagonSquareTest,
        PentagonSquareParametrTest,
        ::testing::Values(
                std::pair(std::vector<Point>{Point(0, 100), Point(95.10565, 30.9017), Point(58.7788, -80.9017),
                                            Point(-58.778, -80.9017), Point(-95.10565, 30.9017)},
                                            5.0 / 2.0 * 100 * 100 * std::sin(1.2566370614359L))));

class TrapezoidGeometricCenterParametrTest :public ::testing::TestWithParam<std::pair<std::vector<Point>, Point>> { };

TEST_P(TrapezoidGeometricCenterParametrTest, IncorrectVertices) {
    // arrange
    std::vector<Point> points = GetParam().first;
    Point correctResult = GetParam().second;
    Figure* trapezoid = trapezoidFactory.createFigure(points);

    // act
    Point center = trapezoid->getGeometricCenter();

    // assert
    EXPECT_EQ(center, correctResult);

}

INSTANTIATE_TEST_CASE_P(
        TrapezoidGeometricCenterTest,
        TrapezoidGeometricCenterParametrTest,
        ::testing::Values(
                std::pair(std::vector<Point>{Point(1, 1), Point(2, 1), Point(3, 0), Point(0, 0)}, Point(1.5, 1.58333)),
                std::pair(std::vector<Point>{Point(2, -1), Point(1, -1), Point(0, 0), Point(3, 0)}, Point(1.5, -0.416667)),
                std::pair(std::vector<Point>{Point(0, 1), Point(0, 2), Point(1, 3), Point(1, 0)}, Point(0.0, 2.08333)),
                std::pair(std::vector<Point>{Point(1, 2), Point(1, 1), Point(0, 0), Point(0, 3)}, Point(1.0, 2.08333))));

class RhombusGeometricCenterParametrTest :public ::testing::TestWithParam<std::pair<std::vector<Point>, Point>> { };

TEST_P(RhombusGeometricCenterParametrTest, IncorrectVertices) {
    // arrange
    std::vector<Point> points = GetParam().first;
    Point correctResult = GetParam().second;
    Figure* rhombus = rhombusFactory.createFigure(points);

    // act
    Point center = rhombus->getGeometricCenter();

    // assert
    EXPECT_EQ(center, correctResult);
}

INSTANTIATE_TEST_CASE_P(
        RhombusGeometricCenterTest,
        RhombusGeometricCenterParametrTest,
        ::testing::Values(
                std::pair(std::vector<Point>{Point(0, 0), Point(0, 1), Point(1, 1), Point(1, 0)}, Point(0.5, 0.5)),
                std::pair(std::vector<Point>{Point(0, 1), Point(1, 0), Point(0, -1), Point(-1, 0)}, Point(0, 0)),
                std::pair(std::vector<Point>{Point(0, 2), Point(1, 0), Point(0, -2), Point(-1, 0)}, Point(0, 0)),
                std::pair(std::vector<Point>{Point(0, 1), Point(2, 0), Point(0, -1), Point(-2, 0)}, Point(0, 0))));

class PentagonGeometricCenterParametrTest :public ::testing::TestWithParam<std::pair<std::vector<Point>, Point>> { };

TEST_P(PentagonGeometricCenterParametrTest, IncorrectVertices) {
    // arrange
    std::vector<Point> points = GetParam().first;
    Point correctResult = GetParam().second;
    Figure* pentagon = pentagonFactory.createFigure(points);

    // act
    Point center = pentagon->getGeometricCenter();

    // assert
    EXPECT_EQ(center, correctResult);
}

INSTANTIATE_TEST_CASE_P(
        PentagonGeometricCenterTest,
        PentagonGeometricCenterParametrTest,
        ::testing::Values(
                std::pair(std::vector<Point>{Point(0, 100), Point(95.10565, 30.9017), Point(58.7788, -80.9017),
                                            Point(-58.778, -80.9017), Point(-95.10565, 30.9017)},
                                            Point(0.0, 0.0))));

int main(int argc, char **argv) {
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}