#include <string>
#include <algorithm>
#include <set>

using namespace std;

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

    float checkAlphabetSimilarity(const string& str1, const string& str2) {
        constexpr float MAX_SCORE = 40.0f;
        if (!isAlphabetSimilarityValid(str1, str2) || hasLowerCase(str1) || hasLowerCase(str2)) {
            return 0.0f;
        }
        if (str1 == str2) {
            return MAX_SCORE;
        }
        int totalChars = 0, sameChars = 0;
        getAlphabetStats(str1, str2, totalChars, sameChars);

        return MAX_SCORE * sameChars / totalChars;
    }

private:
    bool isAlphabetSimilarityValid(const string& str1, const string& str2) const {
        return !(str1.empty() || str2.empty());
    }

    bool hasLowerCase(const string& str) const {
        for (char c : str) {
            if (c >= 'a' && c <= 'z') {
                return true;
            }
        }
        return false;
    }

    void getAlphabetStats(const string& str1, const string& str2, int& totalChars, int& sameChars) const {
        set<char> set1(str1.begin(), str1.end());
        set<char> set2(str2.begin(), str2.end());

        set<char> totalSet = set1;
        totalSet.insert(set2.begin(), set2.end());

        totalChars = static_cast<int>(totalSet.size());
        sameChars = 0;
        for (char c : set1) {
            if (set2.count(c)) {
                ++sameChars;
            }
        }
    }
};