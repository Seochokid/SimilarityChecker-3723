#include "gmock/gmock.h"
#include "SimilarityChecker.cpp"

using namespace testing;

TEST(SimilarityCheckerTest, CheckLengthSimilarityEqualString) {
	SimilarityChecker checker;
	string str1 = "ABC";
	string str2 = "ABC";

	EXPECT_EQ(checker.checkLengthSimilarity(str1, str2), 60);
}

TEST(SimilarityCheckerTest, CheckLengthSimilarityMaxDifferentString) {
	SimilarityChecker checker;
	string str1 = "ABC";
	string str2 = "ABCDEF";
	EXPECT_EQ(checker.checkLengthSimilarity(str1, str2), 0);
}

TEST(SimilarityCheckerTest, CheckLengthSimilarityDifferentString) {
	SimilarityChecker checker;
	string str1 = "ABC";
	string str2 = "ABCD";
	float expected = 40;
	EXPECT_EQ(checker.checkLengthSimilarity(str1, str2), expected);
}

int main() {
	::testing::InitGoogleMock();
	return RUN_ALL_TESTS();
}