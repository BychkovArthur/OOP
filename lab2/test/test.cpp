#include "Four.h"
#include "Constants.h"
#include <gtest/gtest.h>
#include <tuple>

class DynamicArrayParametrTests :public ::testing::TestWithParam<std::pair<unsigned int, unsigned int>>
{
protected:
    Vector vector;
};

TEST_P(DynamicArrayParametrTests, PushAndPopChecking) {
    // arrange
    unsigned int pushTimes = GetParam().first;
    unsigned int popTimes = GetParam().second;

    // act
    for (unsigned int i = 0; i < pushTimes; ++i) {
        vector.pushBack('0' + i);
    }
    for (unsigned int i = 0; i < popTimes; ++i) {
        vector.popBack();
    }

    // assert
    EXPECT_EQ(vector.getSize(), pushTimes - popTimes);
    if (pushTimes > popTimes) {
        EXPECT_EQ(vector[0], '0');
    }
    if (pushTimes - popTimes - 1 < 10) {
        EXPECT_EQ(vector[pushTimes - popTimes - 1], '0' + (pushTimes - popTimes - 1));
    }

}

INSTANTIATE_TEST_CASE_P(
        DynamicArrayTests,
        DynamicArrayParametrTests,
        ::testing::Values(
                std::pair<int, int>(150, 150),
                std::pair<int, int>(150, 149),
                std::pair<int, int>(150, 145),
                std::pair<int, int>(1025, 0),
                std::pair<int, int>(0, 0)));


// num1, num2, result, operator 
class FourNumberArithmeticParametrTests :public ::testing::TestWithParam<std::tuple<const char*, const char*, const char*, const char*>> { };

TEST_P(FourNumberArithmeticParametrTests, AddAndSubtractTests) {
    // arrange
    Four num1(std::string(std::get<0>(GetParam())));
    Four num2(std::string(std::get<1>(GetParam())));
    Four resultNumber(std::string(std::get<2>(GetParam())));
    std::string op = std::string(std::get<3>(GetParam()));
    bool result;

    // act
    switch (OPERATORS[op])
    {
    case 0:
        num1.add(num2);
        result = num1.equal(resultNumber);
        break;
    case 1:
        num1.subtract(num2);
        result = num1.equal(resultNumber);
        break;
    }

    // assert
    EXPECT_EQ(result, true);
}

INSTANTIATE_TEST_CASE_P(
        AddAndSubtractTests,
        FourNumberArithmeticParametrTests,
        ::testing::Values(
                std::make_tuple("0", "0", "0", "+"),
                std::make_tuple("1", "0", "1", "+"),
                std::make_tuple("0", "1", "1", "+"),
                std::make_tuple("2", "0", "2", "+"),
                std::make_tuple("0", "2", "2", "+"),
                std::make_tuple("1", "1", "2", "+"),
                std::make_tuple("3", "0", "3", "+"),
                std::make_tuple("0", "3", "3", "+"),
                std::make_tuple("1", "2", "3", "+"),
                std::make_tuple("2", "1", "3", "+"),
                std::make_tuple("3", "1", "10", "+"),
                std::make_tuple("1", "3", "10", "+"),
                std::make_tuple("2", "3", "11", "+"),
                std::make_tuple("3", "2", "11", "+"),
                std::make_tuple("3", "3", "12", "+"),
                std::make_tuple("11", "3", "20", "+"),
                std::make_tuple("123", "3", "132", "+"),
                std::make_tuple("111111", "3", "111120", "+"),
                std::make_tuple("111111", "333333", "1111110", "+"),
                std::make_tuple("333333", "1", "1000000", "+"),
                std::make_tuple("333333", "2", "1000001", "+"),
                std::make_tuple("333333", "3", "1000002", "+"),

                std::make_tuple("0", "0", "0", "-"),
                std::make_tuple("2", "0", "2", "-"),
                std::make_tuple("3", "0", "3", "-"),
                std::make_tuple("10", "0", "10", "-"),
                std::make_tuple("10", "1", "3", "-"),
                std::make_tuple("10", "2", "2", "-"),
                std::make_tuple("10", "3", "1", "-"),
                std::make_tuple("10", "10", "0", "-"),
                std::make_tuple("321", "10", "311", "-"),
                std::make_tuple("321", "12", "303", "-"),
                std::make_tuple("321", "11", "310", "-"),
                std::make_tuple("311231", "3312", "301313", "-"),
                std::make_tuple("1000", "1", "333", "-"),
                std::make_tuple("1000", "2", "332", "-")));


class FourNumberComparisonOperatorsParametrTests :public ::testing::TestWithParam<std::tuple<const char*, const char*, const char*, const char*>> { };

TEST_P(FourNumberComparisonOperatorsParametrTests, ComparisonOperatorsTests) {
    // arrange
    Four num1(std::string(std::get<0>(GetParam())));
    Four num2(std::string(std::get<1>(GetParam())));
    std::string correctAnswerStr(std::get<2>(GetParam()));
    std::string op(std::get<3>(GetParam()));
    bool result;

    // act
    bool correctAnswerBool = correctAnswerStr == "1" ? 1 : 0;
    switch (OPERATORS[op])
    {
    case 2:
        result = num1.greaterThan(num2);
        break;
    case 3:
        result = num1.lowerThan(num2);
        break;
    case 4:
        result = num1.greaterThanEq(num2);
        break;
    case 5:
        result = num1.lowerThanEq(num2);
        break;
    case 6:
        result = num1.equal(num2);
        break;
    }

    // assert
    EXPECT_EQ(result, correctAnswerBool);
}

INSTANTIATE_TEST_CASE_P(
        ComparisonOperatorsTests,
        FourNumberComparisonOperatorsParametrTests,
        ::testing::Values(
                std::make_tuple("1000", "2", "1", ">"),
                std::make_tuple("2", "2", "0", ">"),
                std::make_tuple("0", "2", "0", ">"),
                std::make_tuple("0", "2", "1", "<"),
                std::make_tuple("2", "2", "0", "<"),
                std::make_tuple("3", "2", "0", "<"),
                std::make_tuple("3", "2", "0", "="),
                std::make_tuple("22", "22", "1", "="),
                std::make_tuple("22", "22", "1", "<="),
                std::make_tuple("13", "22", "1", "<="),
                std::make_tuple("23", "22", "0", "<="),
                std::make_tuple("23", "22", "1", ">="),
                std::make_tuple("22", "22", "1", ">="),
                std::make_tuple("21", "22", "0", ">=")));

int main(int argc, char **argv) {
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}