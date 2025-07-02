#include "gmock/gmock.h"
#include "SimilarityChecker.cpp"

using namespace testing;

class SimilarityCheckerFixture : public Test {
public:
	SimilarityChecker checker;

	void check(string str1, string str2, float expected) {
		EXPECT_FLOAT_EQ(checker.checkLengthSimilarity(str1, str2), expected);
	}
};

TEST_F(SimilarityCheckerFixture, CheckLengthSimilarityEqualString) {
	check("ABC", "ABC", 60.0);
}

TEST_F(SimilarityCheckerFixture, CheckLengthSimilarityMaxDifferentString) {
	check("ABC", "ABCDEF", 0.0);
}

TEST_F(SimilarityCheckerFixture, CheckLengthSimilarityDifferentString) {
	check("ABC", "ABCD", 40.0);
}

int main() {
	::testing::InitGoogleMock();
	return RUN_ALL_TESTS();
}