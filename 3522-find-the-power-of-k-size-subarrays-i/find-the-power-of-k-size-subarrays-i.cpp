class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> result;

        for (int i = 0; i <= n - k; i++) {
            bool isSortedAndConsecutive = true;

            // Check if the subarray is sorted and consecutive
            for (int j = i + 1; j < i + k; j++) {
                if (nums[j] != nums[j-1] + 1) {
                    isSortedAndConsecutive = false;
                    break;
                }
            }

            if (isSortedAndConsecutive) {
                result.push_back(*max_element(nums.begin() + i, nums.begin() + i + k));
            } else {
                result.push_back(-1);
            }
        }

        return result;
    }
};