#include <string>
#include <algorithm>

using std::string;
using std::abs;
using std::min;

class SimilarityChecker {
public:
    float checkLengthSimilarity(const string& str1, const string& str2) {
        constexpr float MAX_SCORE = 60.0f;
        constexpr int LENGTH_DIFF_LIMIT = 3;

        float length1 = static_cast<float>(str1.length());
        float length2 = static_cast<float>(str2.length());

        if (str1 == str2) {
            return MAX_SCORE;  // Equal strings
        }
        if (abs(length1 - length2) >= LENGTH_DIFF_LIMIT) {
            return 0.0f;  // Length difference is too large
        }
        float minLength = min(length1, length2);
        float diff = abs(length1 - length2);
        return (1.0f - (diff / minLength)) * MAX_SCORE;
    }
};