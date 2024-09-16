#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    long long maxScore(vector<int>& a, vector<int>& b) {
        long long dp0 = LLONG_MIN, dp1 = LLONG_MIN, dp2 = LLONG_MIN, dp3 = LLONG_MIN;

        for (int i = 0; i < b.size(); ++i) {
            if (dp2 != LLONG_MIN) {
                dp3 = max(dp3, dp2 + (long long)a[3] * b[i]);
            }

            if (dp1 != LLONG_MIN) {
                dp2 = max(dp2, dp1 + (long long)a[2] * b[i]);
            }

            if (dp0 != LLONG_MIN) {
                dp1 = max(dp1, dp0 + (long long)a[1] * b[i]);
            }

            dp0 = max(dp0, (long long)a[0] * b[i]);
        }

        return dp3;
    }
};
