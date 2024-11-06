class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        int i = 0;
        while (i < nums.size()) {
            int i1 = i;
            int p1 = __builtin_popcount(nums[i]);
            while (i < nums.size() && p1 == __builtin_popcount(nums[i])) i++;
            if (i <= nums.size()) {
                sort(nums.begin() + i1, nums.begin() + i);
            }
        }
        return is_sorted(nums.begin(), nums.end());
    }
};