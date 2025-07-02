#include "gmock/gmock.h"
#include "SimilarityChecker.cpp"

using namespace testing;

class SimilarityCheckerFixture : public Test {
public:
	SimilarityChecker checker;
};

TEST_F(SimilarityCheckerFixture, CheckLengthSimilarityEqualString) {
	string str1 = "ABC";
	string str2 = "ABC";

	EXPECT_EQ(checker.checkLengthSimilarity(str1, str2), 60);
}

TEST_F(SimilarityCheckerFixture, CheckLengthSimilarityMaxDifferentString) {
	string str1 = "ABC";
	string str2 = "ABCDEF";
	EXPECT_EQ(checker.checkLengthSimilarity(str1, str2), 0);
}

TEST_F(SimilarityCheckerFixture, CheckLengthSimilarityDifferentString) {
	string str1 = "ABC";
	string str2 = "ABCD";
	EXPECT_FLOAT_EQ(checker.checkLengthSimilarity(str1, str2), 40.0);
}

int main() {
	::testing::InitGoogleMock();
	return RUN_ALL_TESTS();
}