#include <string>

using std::string;

class SimilarityChecker {
public:
	float checkLengthSimilarity(const string& str1, const string& str2) {
		float length1 = str1.length();
		float length2 = str2.length();

		if (str1 == str2) {
			return 60.0;  // Equal strings
		}
		if (length1 == 0 || length2 == 0) {
			return 0;  // One of the strings is empty
		}
		if (length1 > length2 && (length1 - length2) >= 3) {
			return 0;  // Length difference is too large
		}
		if (length2 > length1 && (length2 - length1) >= 3) {
			return 0;  // Length difference is too large
		}
		// (1 - (|A-B|)/min(A,B)) * 60
		if (length1 < length2) {
			return (1.0 - (length2 - length1) / length1) * 60.0;
		} else {
			return (1.0 - (length1 - length2) / length2) * 60.0;
		}

		return 0;
	}
};