class Solution {
public:
    long long findMaximumScore(vector<int>& array) {
        int length = array.size();
        long long totalScore = 0;
        int initialValue = array[0];
        int previousIndex = 0;

        for (int index = 1; index < length - 1; index++) {
            if (array[index] > array[previousIndex]) {
                totalScore += initialValue * 1LL * (index - previousIndex);
                initialValue = array[index];
                previousIndex = index;
            }
        }

        totalScore += initialValue * 1LL * (length - 1 - previousIndex);
        return totalScore;
    }
};
