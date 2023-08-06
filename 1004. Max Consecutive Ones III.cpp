class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int i=0, j = 0;
        int n = nums.size();

        while (i<n) {
            if (!nums[i]) k--;
            if (k < 0) {
                if (!nums[j]) k++;
                j++;
            }

            i++;
        }

        return i-j;
    }
};
