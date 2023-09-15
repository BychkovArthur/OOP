#include <gtest/gtest.h>
#include <lab1.hpp>


TEST(testVowels, letterA) {
	// arrange
	char letter = 'a';

	// act
	bool isVowel = isLowerCaseVowel(letter);

	// assert
	EXPECT_EQ(isVowel, true);
}

TEST(testVowels, letterE) {
	char letter = 'e';

	bool isVowel = isLowerCaseVowel(letter);

	EXPECT_EQ(isVowel, true);
}

TEST(testVowels, letterU) {
	char letter = 'u';

	bool isVowel = isLowerCaseVowel(letter);

	EXPECT_EQ(isVowel, true);
}

TEST(testVowels, letterO) {
	char letter = 'o';

	bool isVowel = isLowerCaseVowel(letter);

	EXPECT_EQ(isVowel, true);
}

TEST(testVowels, letterI) {
	char letter = 'i';

	bool isVowel = isLowerCaseVowel(letter);

	EXPECT_EQ(isVowel, true);
}

TEST(testVowels, letterQ) {
	char letter = 'q';

	bool isVowel = isLowerCaseVowel(letter);

	EXPECT_EQ(isVowel, false);
}

TEST(testVowels, letterW) {
	char letter = 'w';

	bool isVowel = isLowerCaseVowel(letter);

	EXPECT_EQ(isVowel, false);
}

TEST(testVowels, letterR) {
	char letter = 'r';

	bool isVowel = isLowerCaseVowel(letter);

	EXPECT_EQ(isVowel, false);
}

TEST(testVowels, letterT) {
	char letter = 't';

	bool isVowel = isLowerCaseVowel(letter);

	EXPECT_EQ(isVowel, false);
}

TEST(testVowels, letterY) {
	char letter = 'y';

	bool isVowel = isLowerCaseVowel(letter);

	EXPECT_EQ(isVowel, false);
}

TEST(testVowels, letterP) {
	char letter = 'p';

	bool isVowel = isLowerCaseVowel(letter);

	EXPECT_EQ(isVowel, false);
}

TEST(testVowels, letterS) {
	char letter = 's';

	bool isVowel = isLowerCaseVowel(letter);

	EXPECT_EQ(isVowel, false);
}

TEST(testVowels, letterD) {
	char letter = 'd';

	bool isVowel = isLowerCaseVowel(letter);

	EXPECT_EQ(isVowel, false);
}

TEST(testVowels, letterF) {
	char letter = 'f';

	bool isVowel = isLowerCaseVowel(letter);

	EXPECT_EQ(isVowel, false);
}

TEST(testVowels, letterG) {
	char letter = 'g';

	bool isVowel = isLowerCaseVowel(letter);

	EXPECT_EQ(isVowel, false);
}

TEST(testVowels, letterH) {
	char letter = 'h';

	bool isVowel = isLowerCaseVowel(letter);

	EXPECT_EQ(isVowel, false);
}

TEST(testVowels, letterJ) {
	char letter = 'j';

	bool isVowel = isLowerCaseVowel(letter);

	EXPECT_EQ(isVowel, false);
}

TEST(testVowels, letterK) {
	char letter = 'k';

	bool isVowel = isLowerCaseVowel(letter);

	EXPECT_EQ(isVowel, false);
}

TEST(testVowels, letterL) {
	char letter = 'l';

	bool isVowel = isLowerCaseVowel(letter);

	EXPECT_EQ(isVowel, false);
}

TEST(testVowels, letterZ) {
	char letter = 'z';

	bool isVowel = isLowerCaseVowel(letter);

	EXPECT_EQ(isVowel, false);
}

TEST(testVowels, letterX) {
	char letter = 'x';

	bool isVowel = isLowerCaseVowel(letter);

	EXPECT_EQ(isVowel, false);
}

TEST(testVowels, letterC) {
	char letter = 'c';

	bool isVowel = isLowerCaseVowel(letter);

	EXPECT_EQ(isVowel, false);
}

TEST(testVowels, letterV) {
	char letter = 'v';

	bool isVowel = isLowerCaseVowel(letter);

	EXPECT_EQ(isVowel, false);
}

TEST(testVowels, letterB) {
	char letter = 'b';

	bool isVowel = isLowerCaseVowel(letter);

	EXPECT_EQ(isVowel, false);
}

TEST(testVowels, letterN) {
	char letter = 'n';

	bool isVowel = isLowerCaseVowel(letter);

	EXPECT_EQ(isVowel, false);
}

TEST(testVowels, letterM) {
	char letter = 'm';

	bool isVowel = isLowerCaseVowel(letter);

	EXPECT_EQ(isVowel, false);
}

TEST(testVowels, symbolSpace) {
	char letter = ' ';

	bool isVowel = isLowerCaseVowel(letter);

	EXPECT_EQ(isVowel, false);
}

TEST(testNumberOfVowels, emptyString) {
	std::string str = "";

	int numberOfVowels = getNumberOfVowels(str);

	EXPECT_EQ(numberOfVowels, 0);
}

TEST(testNumberOfVowels, stringOfOnlySpace) {
	std::string str = " ";

	int numberOfVowels = getNumberOfVowels(str);

	EXPECT_EQ(numberOfVowels, 0);
}

TEST(testNumberOfVowels, stringOfOnlySpaces1) {
	std::string str = "         ";

	int numberOfVowels = getNumberOfVowels(str);

	EXPECT_EQ(numberOfVowels, 0);
}

TEST(testNumberOfVowels, stringOfOnlySpaces2) {
	std::string str = "    ";

	int numberOfVowels = getNumberOfVowels(str);

	EXPECT_EQ(numberOfVowels, 0);
}

TEST(testNumberOfVowels, stringOfOnlyСonsonant1) {
	std::string str = "d";

	int numberOfVowels = getNumberOfVowels(str);

	EXPECT_EQ(numberOfVowels, 0);
}

TEST(testNumberOfVowels, stringOfOnlyСonsonant2) {
	std::string str = "b";

	int numberOfVowels = getNumberOfVowels(str);

	EXPECT_EQ(numberOfVowels, 0);
}

TEST(testNumberOfVowels, stringOfOnlyСonsonant3) {
	std::string str = "k";

	int numberOfVowels = getNumberOfVowels(str);

	EXPECT_EQ(numberOfVowels, 0);
}

TEST(testNumberOfVowels, stringOfOnlyСonsonants1) {
	std::string str = "kghjt";

	int numberOfVowels = getNumberOfVowels(str);

	EXPECT_EQ(numberOfVowels, 0);
}

TEST(testNumberOfVowels, stringOfOnlyСonsonants2) {
	std::string str = "kghjt";

	int numberOfVowels = getNumberOfVowels(str);

	EXPECT_EQ(numberOfVowels, 0);
}

TEST(testNumberOfVowels, stringOfOnlyСonsonants3) {
	std::string str = "qwrt";

	int numberOfVowels = getNumberOfVowels(str);

	EXPECT_EQ(numberOfVowels, 0);
}

TEST(testNumberOfVowels, stringOfOnlyСonsonants4) {
	std::string str = "qwrtypsdfghjklzxcvbnm";

	int numberOfVowels = getNumberOfVowels(str);

	EXPECT_EQ(numberOfVowels, 0);
}

TEST(testNumberOfVowels, stringWithoutVowels1) {
	std::string str = "qwr jhj sd vbn hdflk";

	int numberOfVowels = getNumberOfVowels(str);

	EXPECT_EQ(numberOfVowels, 0);
}

TEST(testNumberOfVowels, stringWithoutVowels2) {
	std::string str = ",mn vbzxcv pllp sd";

	int numberOfVowels = getNumberOfVowels(str);

	EXPECT_EQ(numberOfVowels, 0);
}

TEST(testNumberOfVowels, stringWithOneVowel1) {
	std::string str = "a";

	int numberOfVowels = getNumberOfVowels(str);

	EXPECT_EQ(numberOfVowels, 1);
}

TEST(testNumberOfVowels, stringWithOneVowel2) {
	std::string str = "e";

	int numberOfVowels = getNumberOfVowels(str);

	EXPECT_EQ(numberOfVowels, 1);
}

TEST(testNumberOfVowels, stringWithOneVowel3) {
	std::string str = "u";

	int numberOfVowels = getNumberOfVowels(str);

	EXPECT_EQ(numberOfVowels, 1);
}

TEST(testNumberOfVowels, stringWithOneVowel4) {
	std::string str = "o";

	int numberOfVowels = getNumberOfVowels(str);

	EXPECT_EQ(numberOfVowels, 1);
}

TEST(testNumberOfVowels, stringWithOneVowel5) {
	std::string str = "i";

	int numberOfVowels = getNumberOfVowels(str);

	EXPECT_EQ(numberOfVowels, 1);
}

TEST(testNumberOfVowels, randomString1) {
	std::string str = "hello world";

	int numberOfVowels = getNumberOfVowels(str);

	EXPECT_EQ(numberOfVowels, 3);
}

TEST(testNumberOfVowels, randomString2) {
	std::string str = "heello world";

	int numberOfVowels = getNumberOfVowels(str);

	EXPECT_EQ(numberOfVowels, 4);
}

TEST(testNumberOfVowels, randomString3) {
	std::string str = "heello woirld";

	int numberOfVowels = getNumberOfVowels(str);

	EXPECT_EQ(numberOfVowels, 5);
}

TEST(testNumberOfVowels, randomString4) {
	std::string str = "test case";

	int numberOfVowels = getNumberOfVowels(str);

	EXPECT_EQ(numberOfVowels, 3);
}

TEST(testNumberOfVowels, stringOfOnlyVowels) {
	std::string str = "aeiou";

	int numberOfVowels = getNumberOfVowels(str);

	EXPECT_EQ(numberOfVowels, 5);
}


int main(int argc, char **argv) {
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}