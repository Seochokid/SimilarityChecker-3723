#include "gmock/gmock.h"
#include "SimilarityChecker.cpp"

using namespace testing;

class SimilarityCheckerFixture : public Test {
public:
	SimilarityChecker checker;

	void checkLength(string str1, string str2, float expected) {
		EXPECT_FLOAT_EQ(checker.checkLengthSimilarity(str1, str2), expected);
	}
	void checkAlphabet(string str1, string str2, float expected) {
		EXPECT_FLOAT_EQ(checker.checkAlphabetSimilarity(str1, str2), expected);
	}
};

TEST_F(SimilarityCheckerFixture, CheckLengthSimilarityEqualString) {
	checkLength("ABC", "ABC", 60.0);
}

TEST_F(SimilarityCheckerFixture, CheckLengthSimilarityMaxDifferentString) {
	checkLength("ABC", "ABCDEF", 0.0);
}

TEST_F(SimilarityCheckerFixture, CheckLengthSimilarityDifferentString) {
	checkLength("ABC", "ABCD", 40.0);
}

TEST_F(SimilarityCheckerFixture, CheckSimilarityAlphabetDifferent) {
	checkAlphabet("A", "BB", 0.0);
}

TEST_F(SimilarityCheckerFixture, CheckSimilarityAlphabetEqual) {
	checkAlphabet("ASD", "DSA", 40.0);
}

TEST_F(SimilarityCheckerFixture, CheckSimilarityAlphabetDifferentCase) {
	checkAlphabet("AAABB", "BA", 40.0);
}

TEST_F(SimilarityCheckerFixture, CheckSimilarityAlphabetEmpty) {
	checkAlphabet("AA", "AAE", 20.0);
}

TEST_F(SimilarityCheckerFixture, CheckSimilarityAlphabetLowerCase) {
	checkAlphabet("AA", "aA", 0.0);
}

int main() {
	::testing::InitGoogleMock();
	return RUN_ALL_TESTS();
}