#include <gtest/gtest.h>
#include <../include/Four.h>


TEST(DynamicArrayTest, pushAndPop1) {
	// arrange
	Vector vector;

	// act
	for (int i = 0; i < 150; ++i) {
        vector.pushBack('0' + i);
    }
    for (int i = 0; i < 150; ++i) {
        vector.popBack();
    }

	// assert
	EXPECT_EQ(vector.getSize(), 0);
}

TEST(DynamicArrayTest, pushAndPop2) {
	// arrange
	Vector vector;

	// act
	for (int i = 0; i < 150; ++i) {
        vector.pushBack('0' + i);
    }
    for (int i = 0; i < 149; ++i) {
        vector.popBack();
    }

	// assert
	EXPECT_EQ(vector.getSize(), 1);
    EXPECT_EQ(vector[0], '0');
}

TEST(DynamicArrayTest, pushAndPop3) {
	// arrange
	Vector vector;

	// act
	for (int i = 0; i < 150; ++i) {
        vector.pushBack('0' + i);
    }
    for (int i = 0; i < 145; ++i) {
        vector.popBack();
    }

	// assert
	EXPECT_EQ(vector.getSize(), 5);
    EXPECT_EQ(vector[0], '0');
    EXPECT_EQ(vector[1], '1');
    EXPECT_EQ(vector[2], '2');
    EXPECT_EQ(vector[3], '3');
    EXPECT_EQ(vector[4], '4');
}

TEST(DynamicArrayTest, push1) {
	// arrange
	Vector vector;

	// act
	for (int i = 0; i < 1025; ++i) {
        vector.pushBack('0' + i);
    }
    // assert
    EXPECT_EQ(vector.getSize(), 1025);
}

TEST(DynamicArrayTest, empty) {
	// arrange
	Vector vector;

	// act

    // assert
    EXPECT_EQ(vector.getSize(), 0);
}

TEST(FourNumbers, add1) {
	// arrange
	Four num1("0");
    Four num2("0");
    Four res1("0");
    Four res2("1");

	// act
    num1.add(num2);

    // assert
    EXPECT_EQ(num1.equal(res1), 1);
    EXPECT_EQ(num1.equal(res2), 0);
}

TEST(FourNumbers, add2) {
	// arrange
	Four num1("1");
    Four num2("1");
    Four res("2");

	// act
    num1.add(num2);

    // assert
    EXPECT_EQ(num1.equal(res), 1);
}

TEST(FourNumbers, add3) {
	// arrange
	Four num1("2");
    Four num2("1");
    Four res("3");

	// act
    num1.add(num2);

    // assert
    EXPECT_EQ(num1.equal(res), 1);
}

TEST(FourNumbers, add4) {
	// arrange
	Four num1("3");
    Four num2("1");
    Four res("10");

	// act
    num1.add(num2);

    // assert
    EXPECT_EQ(num1.equal(res), 1);
}

TEST(FourNumbers, add5) {
	// arrange
	Four num1("1");
    Four num2("3");
    Four res("10");

	// act
    num1.add(num2);

    // assert
    EXPECT_EQ(num1.equal(res), 1);
}

TEST(FourNumbers, add6) {
	// arrange
	Four num1("11");
    Four num2("3");
    Four res("20");

	// act
    num1.add(num2);

    // assert
    EXPECT_EQ(num1.equal(res), 1);
}

TEST(FourNumbers, add7) {
	// arrange
	Four num1("11111");
    Four num2("3");
    Four res("11120");

	// act
    num1.add(num2);

    // assert
    EXPECT_EQ(num1.equal(res), 1);
}

TEST(FourNumbers, add8) {
	// arrange
	Four num1("123");
    Four num2("3");
    Four res("132");

	// act
    num1.add(num2);

    // assert
    EXPECT_EQ(num1.equal(res), 1);
}

TEST(FourNumbers, add9) {
	// arrange
	Four num1("33333");
    Four num2("1");
    Four res("100000");

	// act
    num1.add(num2);

    // assert
    EXPECT_EQ(num1.equal(res), 1);
}

TEST(FourNumbers, add10) {
	// arrange
	Four num1("33333");
    Four num2("3");
    Four res("100002");

	// act
    num1.add(num2);

    // assert
    EXPECT_EQ(num1.equal(res), 1);
}

TEST(FourNumbers, add11) {
	// arrange
	Four num1("33333");
    Four num2("10");
    Four res("100003");

	// act
    num1.add(num2);

    // assert
    EXPECT_EQ(num1.equal(res), 1);
}

TEST(FourNumbers, subtract1) {
	// arrange
	Four num1("0");
    Four num2("0");
    Four res("0");

	// act
    num1.subtract(num2);

    // assert
    EXPECT_EQ(num1.equal(res), 1);
}

TEST(FourNumbers, subtract2) {
	// arrange
	Four num1("1");
    Four num2("0");
    Four res("1");

	// act
    num1.subtract(num2);

    // assert
    EXPECT_EQ(num1.equal(res), 1);
}

TEST(FourNumbers, subtract3) {
	// arrange
	Four num1("2");
    Four num2("0");
    Four res("2");

	// act
    num1.subtract(num2);

    // assert
    EXPECT_EQ(num1.equal(res), 1);
}

TEST(FourNumbers, subtract4) {
	// arrange
	Four num1("3");
    Four num2("0");
    Four res("3");

	// act
    num1.subtract(num2);

    // assert
    EXPECT_EQ(num1.equal(res), 1);
}

TEST(FourNumbers, subtract5) {
	// arrange
	Four num1("10");
    Four num2("0");
    Four res("10");

	// act
    num1.subtract(num2);

    // assert
    EXPECT_EQ(num1.equal(res), 1);
}

TEST(FourNumbers, subtract6) {
	// arrange
	Four num1("10");
    Four num2("1");
    Four res("3");

	// act
    num1.subtract(num2);

    // assert
    EXPECT_EQ(num1.equal(res), 1);
}

TEST(FourNumbers, subtract7) {
	// arrange
	Four num1("10");
    Four num2("2");
    Four res("2");

	// act
    num1.subtract(num2);

    // assert
    EXPECT_EQ(num1.equal(res), 1);
}

TEST(FourNumbers, subtract8) {
	// arrange
	Four num1("10");
    Four num2("3");
    Four res("1");

	// act
    num1.subtract(num2);

    // assert
    EXPECT_EQ(num1.equal(res), 1);
}

TEST(FourNumbers, subtract9) {
	// arrange
	Four num1("10");
    Four num2("10");
    Four res("0");

	// act
    num1.subtract(num2);

    // assert
    EXPECT_EQ(num1.equal(res), 1);
}

TEST(FourNumbers, subtract10) {
	// arrange
	Four num1("321");
    Four num2("10");
    Four res("311");

	// act
    num1.subtract(num2);

    // assert
    EXPECT_EQ(num1.equal(res), 1);
}

TEST(FourNumbers, subtract11) {
	// arrange
	Four num1("321");
    Four num2("10");
    Four res("311");

	// act
    num1.subtract(num2);

    // assert
    EXPECT_EQ(num1.equal(res), 1);
}

TEST(FourNumbers, subtract12) {
	// arrange
	Four num1("321");
    Four num2("11");
    Four res("310");

	// act
    num1.subtract(num2);

    // assert
    EXPECT_EQ(num1.equal(res), 1);
}

TEST(FourNumbers, subtract13) {
	// arrange
	Four num1("311231");
    Four num2("3312");
    Four res("301313");

	// act
    num1.subtract(num2);

    // assert
    EXPECT_EQ(num1.equal(res), 1);
}

TEST(FourNumbers, subtract14) {
	// arrange
	Four num1("1000");
    Four num2("1");
    Four res("333");

	// act
    num1.subtract(num2);

    // assert
    EXPECT_EQ(num1.equal(res), 1);
}

TEST(FourNumbers, subtract15) {
	// arrange
	Four num1("1000");
    Four num2("2");
    Four res("332");

	// act
    num1.subtract(num2);

    // assert
    EXPECT_EQ(num1.equal(res), 1);
}

TEST(FourNumbers, greaterThan1) {
	// arrange
	Four num1("1000");
    Four num2("2");

	// act
    bool result = num1.greaterThan(num2);

    // assert
    EXPECT_EQ(result, 1);
}

TEST(FourNumbers, greaterThan2) {
	// arrange
	Four num1("2");
    Four num2("2");

	// act
    bool result = num1.greaterThan(num2);

    // assert
    EXPECT_EQ(result, 0);
}

TEST(FourNumbers, greaterThan3) {
	// arrange
	Four num1("0");
    Four num2("2");

	// act
    bool result = num1.greaterThan(num2);

    // assert
    EXPECT_EQ(result, 0);
}

TEST(FourNumbers, lowerThan1) {
	// arrange
	Four num1("0");
    Four num2("2");

	// act
    bool result = num1.lowerThan(num2);

    // assert
    EXPECT_EQ(result, 1);
}

TEST(FourNumbers, lowerThan2) {
	// arrange
	Four num1("2");
    Four num2("2");

	// act
    bool result = num1.lowerThan(num2);

    // assert
    EXPECT_EQ(result, 0);
}

TEST(FourNumbers, lowerThan3) {
	// arrange
	Four num1("3");
    Four num2("2");

	// act
    bool result = num1.lowerThan(num2);

    // assert
    EXPECT_EQ(result, 0);
}

TEST(FourNumbers, equal1) {
	// arrange
	Four num1("3");
    Four num2("2");

	// act
    bool result = num1.equal(num2);

    // assert
    EXPECT_EQ(result, 0);
}

TEST(FourNumbers, equal2) {
	// arrange
	Four num1("22");
    Four num2("22");

	// act
    bool result = num1.equal(num2);

    // assert
    EXPECT_EQ(result, 1);
}

TEST(FourNumbers, lowerThanOrEq1) {
	// arrange
	Four num1("22");
    Four num2("22");

	// act
    bool result = num1.lowerThanEq(num2);

    // assert
    EXPECT_EQ(result, 1);
}

TEST(FourNumbers, lowerThanOrEq2) {
	// arrange
	Four num1("13");
    Four num2("22");

	// act
    bool result = num1.lowerThanEq(num2);

    // assert
    EXPECT_EQ(result, 1);
}

TEST(FourNumbers, lowerThanOrEq3) {
	// arrange
	Four num1("23");
    Four num2("22");

	// act
    bool result = num1.lowerThanEq(num2);

    // assert
    EXPECT_EQ(result, 0);
}

TEST(FourNumbers, greaterThanOrEq1) {
	// arrange
	Four num1("23");
    Four num2("22");

	// act
    bool result = num1.greaterThanEq(num2);

    // assert
    EXPECT_EQ(result, 1);
}

TEST(FourNumbers, greaterThanOrEq2) {
	// arrange
	Four num1("22");
    Four num2("22");

	// act
    bool result = num1.greaterThanEq(num2);

    // assert
    EXPECT_EQ(result, 1);
}

TEST(FourNumbers, greaterThanOrEq3) {
	// arrange
	Four num1("21");
    Four num2("22");

	// act
    bool result = num1.greaterThanEq(num2);

    // assert
    EXPECT_EQ(result, 0);
}

int main(int argc, char **argv) {
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}