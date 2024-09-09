#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxPossibleScore(vector<int>& positions, int increment) {
        sort(positions.begin(), positions.end());
        
        auto isFeasible = [&](long long minDiff) -> bool {
            long long lastChosen = positions[0];
            for (int idx = 1; idx < positions.size(); ++idx) {
                if (lastChosen + minDiff <= positions[idx] + increment) {
                    lastChosen = max(lastChosen + minDiff, (long long)positions[idx]);
                } else {
                    return false;
                }
            }
            return true;
        };
        
        long long lowerBound = 0;
        long long upperBound = (positions.back() + increment) - positions[0];
        long long optimalScore = 0;
        
        while (lowerBound <= upperBound) {
            long long midPoint = (lowerBound + upperBound) / 2;
            if (isFeasible(midPoint)) {
                optimalScore = midPoint;
                lowerBound = midPoint + 1;
            } else {
                upperBound = midPoint - 1;
            }
        }
        
        return static_cast<int>(optimalScore);  // Cast to int for return type
    }
};
