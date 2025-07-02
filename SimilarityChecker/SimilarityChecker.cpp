#include <string>
#include <algorithm>

using std::string;
using std::abs;
using std::min;

class SimilarityChecker {
public:
    float checkLengthSimilarity(const string& str1, const string& str2) {
        constexpr float MAX_SCORE = 60.0f;

        float length1 = static_cast<float>(str1.length());
        float length2 = static_cast<float>(str2.length());

        if (str1 == str2) {
            return MAX_SCORE;  // Equal strings
        }
        if (length1 >= 2 * length2 || length2 >= 2 * length1) {
            return 0.0f;  // Length difference is too large
        }
        float minLength = min(length1, length2);
        float diff = abs(length1 - length2);
        return (1.0f - (diff / minLength)) * MAX_SCORE;
    }
};